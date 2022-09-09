namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            return (M(qs[1]) == Zero ? 0 | 2) + (M(qs[0]) == Zero ? 0 | 1);
        }
    }
}