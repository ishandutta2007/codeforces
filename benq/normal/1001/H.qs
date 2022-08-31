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

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            for (i in 0..Length(x)-1) {
                CNOT(x[i],y);
            }
        }
    }
}