namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve(unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            within {
                H(q);
            }
            apply {
                unitary(q);
                unitary(q);
            }
            let res = M(q) == One ? 1 | 0;
            Reset(q);
            return res;
        }
    }
}