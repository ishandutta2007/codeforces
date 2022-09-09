namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable res = true;
            using ((qs, q) = (Qubit[N], Qubit())) {
                X(q);
                for (qq in qs) {
                    H(qq);
                }
                H(q);
                Uf(qs, q);
                for (qq in qs) {
                    H(qq);
                }
                for (qq in qs) {
                    if (M(qq) == One) {
                        set res = false;
                    }
                }
                ResetAll(qs);
                Reset(q);
            }
            return res;
        }
    }
}