namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable ans = true;
            using (q = Qubit[N])
            {
                using (h = Qubit[1])
                {
                    for (i in 0..N-1)
                    {
                        H(q[i]);
                    }
                    H(h[0]);
                    Z(h[0]);
                    Uf(q, h[0]);
                    for (i in 0..N-1)
                    {
                        H(q[i]);
                    }
                    for (i in 0..N-1)
                    {
                        if (M(q[i]) == One)
                        {
                            set ans = false;
                        }
                    }
                    for (i in 0..N-1)
                    {
                        Reset(q[i]);
                    }
                    Reset(h[0]);
                }
            }
            return ans;
        }
    }
}