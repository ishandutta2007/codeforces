namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation add(qs: Qubit[]) : Unit {
        body(...){
            let n = Length(qs);
            for(i in n-1..-1..1){
                (Controlled X)(qs[0..i-1], qs[i]);
            }
            X(qs[0]);
        }
        controlled auto;
    } 
    operation sub(qs: Qubit[]) : Unit {
        body(...){
            ApplyToEachC(X, qs);
            add(qs);
            ApplyToEachC(X, qs);
        }
        controlled auto;
    }

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        ApplyToEach(X, qs[0..n-2]);
        Controlled add([qs[n-1]], qs[0..n-2]);
        X(qs[n-1]);
        Controlled sub([qs[n-1]], qs[0..n-2]);
        X(qs[n-1]);
        for(i in 1..n-1){
            CNOT(qs[0], qs[i]);
        }
        H (qs[0]);
        for(i in 1..n-1){
            CNOT(qs[0], qs[i]);
        }
    }
}