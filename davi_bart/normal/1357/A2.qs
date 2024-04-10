namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            if(M(qs[1]) == Zero){
                ResetAll(qs);
                X(qs[0]);
                X(qs[1]);
                unitary(qs);
                if(M(qs[0]) == Zero){
                    ResetAll(qs);
                    return 2;
                }else{
                    ResetAll(qs);
                    return 0;
                }
            }else{
                ResetAll(qs);
                X(qs[0]);
                X(qs[1]);
                unitary(qs);
                if(M(qs[1])==Zero){
                    ResetAll(qs);
                    return 1;
                }else{
                    ResetAll(qs);
                    return 3;
                }
            }
        }
    }
}