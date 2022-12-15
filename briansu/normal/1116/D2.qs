namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        ApplyToEach(X, qs[1..n-1]);
        for(i in 1..n-1){
            X (qs[i]);
            for(j in 0..i-1){
                (Controlled H)(qs[i..n-1], qs[j]);
            }
        }
    }
}