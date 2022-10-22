namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable res=0;
        using (qs = Qubit()){
            X(qs);
            unitary(qs);
            Z(qs);
            unitary(qs);
            if(M(qs)==One){
                set res=1;
            }
            Reset(qs);
        }
        return res;
    }
}