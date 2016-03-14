#include "thread/compute_thread.hpp"
#include "dummy_item.hpp"

class ComputeThreadThread1 : public afs::ComputeThread<DummyType, DummyType, afs::NullClass, afs::NullClass> {
public:
    ComputeThreadThread1(int num_out_queue, afs::RouterBase* r) :
        afs::ComputeThread<DummyType, DummyType, afs::NullClass, afs::NullClass>(num_out_queue, 0) {}

private:
    int cur = 0;

    void ComputeThreadInit() {}
    void ComputeThreadFinish() {}
    void ComputeThreadRecovery() {}

    void ProcessRecord(DummyType& tuple, uint64_t seq) {
        printf("ComputeThread %d, data number %u\n", thr_id(), tuple.number);
        EmitData(cur, tuple);
        cur = (cur+1) % GetNumDownstream();
    }
    void ProcessTimeout() {}
};
