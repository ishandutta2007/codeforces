// quick ref: https://github.com/microsoft/QuantumKatas/blob/master/quickref/qsharp-quick-reference.pdf
// warmup round: https://codeforces.com/contest/1356
// when including Microsoft.Quantum.MachineLearning you need to modify .csproj manually
    // see HalfMoons.csproj for example

namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Diagnostics;

    operation Set (q: Qubit, des: Result) : Unit { // set state of q -> desired
        if (des != M(q)) { X(q); }
    }

    // operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
    //     // unwrap LittleEndian type
    //     let qarray = register!;
    //     X(qarray[0]);
    //     if (Length(qarray) > 1) {
    //         // increment the rest of the number if the least significant bit is 1
    //         (Controlled Solve)([qarray[0]], LittleEndian(qarray[1 ...]));
    //     }
    //     // increment the least significant bit
    // }
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res = -1;
        using (q = Qubit[2]) {
            X(q[0]);
            unitary(q);
            let a = M(q[0]);
            let b = M(q[1]);
            if (a == One and b == Zero) {
                Set(q[1],One);
                unitary(q);
                if (M(q[0]) == Zero) {
                    set res = 2;
                } else {
                    set res = 0;
                }
            } elif (a == One and b == One) {
                set res = 1;
            } else {
                set res = 3;
            }
            Reset(q[0]);
            Reset(q[1]);
        }
        return res;
        // your code here
    }

    // @EntryPoint()
    // operation HelloQ() : Unit {
    //     Message("Hello quantum world!");
    //     using ((a,b) = (Qubit(),Qubit())) { // https://docs.microsoft.com/en-us/quantum/user-guide/using-qsharp/working-with-qubits
    //         H(b);
    //         DumpMachine(); // https://docs.microsoft.com/en-us/qsharp/api/qsharp/microsoft.quantum.diagnostics.dumpmachine
    //         Reset(a); Reset(b);

    //         // DumpMachine output:
    //         // 0:	 0.707107 +  0.000000 i	 == 	***********          [ 0.500000 ]     --- [  0.00000 rad ]
    //         // 1:	 0.000000 +  0.000000 i	 == 	                     [ 0.000000 ]                   
    //         // 2:	 0.707107 +  0.000000 i	 == 	***********          [ 0.500000 ]     --- [  0.00000 rad ]
    //         // 3:	 0.000000 +  0.000000 i	 == 	                     [ 0.000000 ]   
    //     }
    // }
}