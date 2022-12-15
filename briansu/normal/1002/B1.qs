namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        let N = Length(qs);
        mutable ans = 0;
        using (q = Qubit()){
            for(i in 0..N-1){
                CNOT(qs[i], q);
            }
            if(M (q) == One){
                set ans = 1;
                X (q);
            }
        }
        return ans;
    }
}