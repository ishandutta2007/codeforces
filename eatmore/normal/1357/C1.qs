namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    operation Solve(qs : Qubit[]) : Unit {
        using (q = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                Controlled X(qs, q);
            } until (M(q) == Zero)
            fixup {
                Reset(q);
                ResetAll(qs);
            }
            Reset(q);
        }
    }
}