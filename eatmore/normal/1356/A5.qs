namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve(unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using ((q1, q2) = (Qubit(), Qubit())) {
            H(q1);
            H(q2);
            Controlled unitary([q1], q2);
            H(q2);
            CNOT(q1, q2);
            H(q1);
            let res = M(q1) == One ? 1 | 0;
            ResetAll([q1, q2]);
            return res;
        }
    }
}