namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable ans = -1;
            using (t = Qubit[1])
            {
                H(t[0]);
                let result = M(t[0]);
                if (result == One)
                {
                    if (M(q) == One)
                    {
                        set ans = 1;
                    }
                }
                else
                {
                    H(q);
                    if (M(q) == One)
                    {
                        set ans = 0;
                    }
                }
                Reset(t[0]);
            }
            return ans;
        }
    }
}