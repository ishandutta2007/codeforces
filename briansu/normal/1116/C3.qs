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
        adjoint auto;
    } 
    operation sub(qs: Qubit[]) : Unit {
        body(...){
            ApplyToEachCA(X, qs);
            add(qs);
            ApplyToEachCA(X, qs);
        }
        controlled auto;
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            
            let n = Length(x);
            if(n == 9){
                Controlled X(x, y);
            }
            ApplyToEachA(X, x);
            Controlled X(x, y);
            ApplyToEachA(X, x);
            using(cnt = Qubit[3]){
                for(i in 0..n-1){
                    Controlled add([x[i]], cnt);
                }
                for(t in 1..2){
                    for(p in 1..3){
                        sub(cnt);
                    }
                    ApplyToEachA(X, cnt);
                    Controlled X(cnt, y);
                    ApplyToEachA(X, cnt);
                }
                for(t in 1..6){
                    add(cnt);
                }
                for(i in 0..n-1){
                    Controlled sub([x[i]], cnt);
                }
            }
        }
        adjoint auto;
    }
}