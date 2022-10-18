namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            mutable b0 = 1;
            if (M(qs[0]) == One) {
                set b0 = 0;
            }
            mutable b1 = 1;
            if (M(qs[1]) == One) {
                set b1 = 0;
            }
            
            mutable x = 2 * b0 + b1;
            return x;
        }
    }
}