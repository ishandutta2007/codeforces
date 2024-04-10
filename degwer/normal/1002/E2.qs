  namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable r=new Int[N];
            using(q=Qubit[N])
            {
                using(p=Qubit[1])
                {
                    Uf(q,p[0]);
                    mutable t=N%2;
                    mutable s=0;
                    if(M(p[0])==One){set s=1;}
                    if(t!=s){set r[0]=1;}
                    ResetAll(p);
                }
                ResetAll(q);
            }
            return r;
        }
    }
}