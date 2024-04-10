namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            // your code here
            mutable t=-1;
            for(i in 0..Length(qs)-1)
            {
                if(bits[i])
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
        }
    }
}