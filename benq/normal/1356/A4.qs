// reference: https://github.com/microsoft/QuantumKatas/blob/master/quickref/qsharp-quick-reference.pdf
 
namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    // @EntryPoint()
    operation HelloQ() : Unit {
        Message("Hello quantum world!");
    }
 
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

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res = 0;
        using (q = Qubit[2]) {
            unitary(q);
            if (M(q[1]) == Zero) {
                set res = 1;
            }
            Set(q[0],Zero);
            Set(q[1],Zero);
        }
        return res;
    }
}