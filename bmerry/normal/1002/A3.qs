namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let N = Length(qs);
            mutable first = -1;
            for (i in 0..N-1)
            {
                if (bits0[i] != bits1[i])
                {
                    if (first == -1)
                    {
                        set first = i;
                        H(qs[i]);
                    }
                    else
                    {
                        if (bits1[i] != bits1[first])
                        {
                            X(qs[i]);
                        }
                        CNOT(qs[first], qs[i]);
                    }
                }
                elif (bits0[i])
                {
                    X(qs[i]);
                }
            }
        }
    }
}