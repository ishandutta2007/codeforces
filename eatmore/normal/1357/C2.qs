namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arrays;
    operation Solve(qs : Qubit[], parity : Int) : Unit {
        ApplyToEach(H, Most(qs));
        ApplyToEach(CNOT(_, Tail(qs)), Most(qs));
        if (parity != 0) {
            X(Tail(qs));
        }
    }
}