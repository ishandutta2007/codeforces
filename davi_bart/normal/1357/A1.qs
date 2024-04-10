namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res = 0;
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            if (M(qs[1]) == Zero) {
                set res = 1;
            }
            ResetAll(qs);
        }
        return res;
    }
}