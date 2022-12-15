namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation cal(x : Qubit[], y: Qubit, p: Int) : Unit {
        body (...) {
            let n = Length(x);
            for(i in 0..n-p-1){
                CNOT(x[i+p], x[i]);
            }
            for(i in 0..n-p-1){
                X(x[i]);
            }
            Controlled X(x[0..n-p-1], y);
            for(i in 0..n-p-1){
                X(x[i]);
            }
            for(i in n-p-1..-1..0){
                CNOT(x[i+p], x[i]);
            }
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            using(qs = Qubit[n]){
                for(i in 1..n-1){
                    if(i * 2 > n-1){
                        cal(x, qs[n-i], i);
                    }
                }
                for(i in 1..n-1){
                    X(qs[i]);
                }   
                Controlled X(qs[1..n-1], y);
                X(y);
                for(i in 1..n-1){
                    X(qs[i]);
                }  
                for(i in n-1..-1..1){
                    if(i * 2 > n-1){
                        cal(x, qs[n-i], i);
                    }
                }
            }
        }
        adjoint auto;
    }
}