namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable t=-1;
            for(i in 0..Length(qs)-1)
            {
                if(bits0[i] != bits1[i])
                {
                    if(t==-1)
                    {
                        set t=i;
                        H(qs[i]);
                    }
                    else
                    {
                        CNOT(qs[t],qs[i]);
                    }
                }
            }
            for(i in 0..Length(qs)-1)
            {
                if(bits0[i])
                {
                    X(qs[i]);
                }
            }
        }
    }
}