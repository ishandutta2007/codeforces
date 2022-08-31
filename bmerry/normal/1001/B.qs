namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            Reset(qs[0]);
            Reset(qs[1]);
            if (index >= 2)
            {
                X(qs[1]);
            }
            H(qs[0]);
            if (index == 1 || index == 3)
            {
                Z(qs[0]);
            }
            CNOT(qs[0], qs[1]);
        }
    }
}