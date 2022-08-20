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

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let res = M(q);
            if (res == Zero) {
                return 1;
            } else {
                return -1;
            }
        }
    }
}