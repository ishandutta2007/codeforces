namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable ones = 0;
            let N = Length(qs);
            for (i in 0..N-1)
            {
                if (M(qs[i]) == One)
                {
                    set ones = ones + 1;
                }
            }
            if (ones == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}