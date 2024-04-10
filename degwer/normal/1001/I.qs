namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable f=true;
            using(q=Qubit[N])
            {
                using(p=Qubit[1])
                {
                    for(i in 0..N-1){H(q[i]);}
                    X(p[0]);
                    H(p[0]);
                    Uf(q,p[0]);
                    for(i in 0..N-1){H(q[i]);}
                    for(i in 0..N-1)
                    {
                        if(M(q[i])==One){set f=false;}
                    }
                    ResetAll(p);
                }
                ResetAll(q);
            }
            return f;
        }
    }
}