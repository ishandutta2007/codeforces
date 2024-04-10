namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            for(i in 1..Length(qs)-1)
            {
                CNOT(qs[0],qs[i]);
            }
            H(qs[0]);
            mutable t=0;
            for(i in 0..Length(qs)-1)
            {
                if(M(qs[i])==One)
                {
                    set t=1;
                }
            }
            return t;
        }
    }
}