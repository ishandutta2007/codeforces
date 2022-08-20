namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current) { X(q1); }
        }
    }

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            Set(Zero,qs[0]);
            H(qs[0]);
            for (i in 1..Length(qs)-1) {
                CNOT(qs[0],qs[i]);
            }
        }
    }
}