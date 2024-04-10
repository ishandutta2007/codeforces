namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool {
        mutable res = true;
        using (qs = Qubit[N]){using(q = Qubit())
        {
            ResetAll(qs);Reset(q);
            X (q);
            for(i in 0..N-1){
                H (qs[i]);
            }
            H(q);
            Uf(qs, q);
            for(i in 0..N-1){
                H (qs[i]);
                if(M(qs[i]) == One){
                    set res = false;
                }
            }
            ResetAll(qs);
            Reset(q);
        }}
        return res;
    }
}