namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            let N = Length(qs);
            mutable first = -1;
            for (i in 0..N-1)
            {
                if (bits[i])
                {
                    if (first == -1)
                    {
                        set first = i;
                        H(qs[i]);
                    }
                    else
                    {
                        CNOT(qs[first], qs[i]);
                    }
                }
            }
        }
    }
}