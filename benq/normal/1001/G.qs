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

    operation Solve (x : Qubit[], y : Qubit, k : Int) : ()
    {
        body
        {
            // Set(Zero,y);
            CNOT(x[k],y);
            // your code here
        }
    }
}