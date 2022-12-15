namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        let n = Length(qs);
        let fg = (M (qs[0]) == One);
        for(i in 1..n-1){
            if((M (qs[i]) == One) != fg){
                return 1;
            }
        }
        return 0;
    }
}