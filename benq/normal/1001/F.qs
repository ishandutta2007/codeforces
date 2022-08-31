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

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for (i in 0..Length(qs)-1) {
                if (bits0[i] != bits1[i]) {
                    let z = M(qs[i]);
                    if (bits0[i] == true) {
                        if (z == One) {
                            return 0;
                        }
                        return 1;
                    } else {
                        if (z == Zero) {
                            return 0;
                        }
                        return 1;
                    }
                }
            }
            return 0;
            // your code here
        }
    }
}