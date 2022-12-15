namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            using(qs = Qubit[n-1]){
                for(i in 0..n-2){
                    CCNOT(x[i], x[i+1], qs[i]);
                    X(x[i]);X(x[i+1]);
                    CCNOT(x[i], x[i+1], qs[i]);
                    X(x[i]);X(x[i+1]);
                }
                ApplyToEachA(X, qs);
                (Controlled X)(qs, y);
                ApplyToEachA(X, qs);
                for(i in 0..n-2){
                    CCNOT(x[i], x[i+1], qs[i]);
                    X(x[i]);X(x[i+1]);
                    CCNOT(x[i], x[i+1], qs[i]);
                    X(x[i]);X(x[i+1]);
                }
            }
        }
        adjoint auto;
    }
}