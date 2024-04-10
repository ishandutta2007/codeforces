// reference: https://github.com/microsoft/QuantumKatas/blob/master/quickref/qsharp-quick-reference.pdf
 
namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arithmetic;
 
    operation Set (q: Qubit, des: Result) : Unit { // set state of q -> desired
        if (des != M(q)) { X(q); }
    }
 
    // operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
    //     mutable res = 0;
    //     using (q = Qubit()) {
    //         H(q);
    //         unitary(q);
    //         unitary(q);
    //         H(q);
    //         if (M(q) == Zero) {
    //             set res = 0;
    //         } else {
    //             set res = 1;
    //         }
    //         Set(q,Zero);
    //     }
    //     return res;
    //     // your code here
    // }

    // operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
    //     mutable res = 0;
    //     using (q = Qubit[2]) {
    //         unitary(q);
    //         if (M(q[1]) == Zero) {
    //             set res = 1;
    //         }
    //         Set(q[0],Zero);
    //         Set(q[1],Zero);
    //     }
    //     return res;
    // }

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        let arr = register!;
        X(arr[0]);
        for (i in 1..Length(arr)-1) {
            using (q = Qubit[i]) {
                for (j in 0..i-1) {
                    CNOT(arr[j],q[j]);
                    X(q[j]);
                }
                Controlled X(q,arr[i]);
                for (j in 0..i-1) {
                    CNOT(arr[j],q[j]);
                    X(q[j]);
                }
            }
        }
        // your code here
    }
    // @EntryPoint()
    // operation HelloQ() : Unit {
    //     Message("Hello quantum world!");
    //     using (q = Qubit[3]) {
    //         Set(q[0],One);
    //         Set(q[1],One);
    //         Solve()
    //         for (i in 0..2) {
    //             Set(q[i],Zero);
    //         }
    //     }
    // }
}