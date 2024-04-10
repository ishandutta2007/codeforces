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

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0],qs[1]);
            let res = M(qs[1]);
            if (res == Zero) {
                H(qs[0]);
                let res1 = M(qs[0]);
                if (res1 == Zero) {
                    return 0;
                } 
                return 1;
            } else {
                H(qs[0]);
                let res1 = M(qs[0]);
                if (res1 == Zero) {
                    return 2;
                }
                return 3;
            }
        }
    }
}