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

    operation Solve (qs : Qubit[], index : Int) : () {
        body {
            if (index == 0) {
                Set(Zero,qs[0]);
                Set(Zero,qs[1]);
            } 
            if (index == 1) {
                Set(One,qs[0]);
                Set(Zero,qs[1]);
            } 
            if (index == 2) {
                Set(Zero,qs[0]);
                Set(One,qs[1]);
            }
            if (index == 3) {
                Set(One,qs[0]);
                Set(One,qs[1]);
            }
            H(qs[0]);
            CNOT(qs[0],qs[1]);
            // your code here
        }
    }
}