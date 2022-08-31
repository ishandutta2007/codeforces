// quick ref: https://github.com/microsoft/QuantumKatas/blob/master/quickref/qsharp-quick-reference.pdf
// warmup round: https://codeforces.com/contest/1356
// when including Microsoft.Quantum.MachineLearning you need to modify .csproj manually
    // see HalfMoons.csproj for example

namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Math;
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

    operation Incr (register : LittleEndian) : Unit is Adj+Ctl {
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

    operation Decr (register : LittleEndian) : Unit is Adj+Ctl {
        let arr = register!;
        X(arr[0]);
        for (i in 1..Length(arr)-1) {
            using (q = Qubit[i]) {
                for (j in 0..i-1) {
                    CNOT(arr[j],q[j]);
                }
                Controlled X(q,arr[i]);
                for (j in 0..i-1) {
                    CNOT(arr[j],q[j]);
                }
            }
        }
        // your code here
    }

    // operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
    //     mutable res = -1;
    //     using (q = Qubit[2]) {
    //         H(q[0]); CNOT(q[0],q[1]);
    //         unitary(q[1]);
    //         CNOT(q[0],q[1]); H(q[0]);
    //         if (M(q[0]) == Zero) {
    //             if (M(q[1]) == Zero) {
    //                 set res = 0;
    //             } else {
    //                 set res = 1;
    //             }
    //         } else {
    //             if (M(q[1]) == Zero) {
    //                 set res = 3;
    //             } else {
    //                 set res = 2;
    //             }
    //         }
    //         ResetAll(q);
    //     }
    //     return res;
    //     // your code here
    // }

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable done = false;
        mutable cnt = 0;
        mutable ang = 0.0;
        mutable res = 0;
        using (q = Qubit()) {
            repeat {
                unitary(q);
                set cnt += 1;
                set ang += theta;
                if (cnt == 150 or ang+theta > PI()) {
                    if (M(q) == One) {
                        set res = 1;
                    }
                    Reset(q);
                    set ang = 0.0;
                }
            } until (cnt == 150);
            Reset(q);
        }
        return res;
        // your code here
    }
    

    // @EntryPoint()
    // operation HelloQ() : Unit {
    //     Message("Hello quantum world!");
    //     let theta = 0.3;
    //     let y = Ry(theta,_);
    //     let z = Rz(theta,_);
    //     for (i in 1..100) {
    //         Message($"{i} {Solve(theta,z)} {Solve(theta,y)}");
    //     }
    //     // using ((a,b) = (Qubit(),Qubit())) { // https://docs.microsoft.com/en-us/quantum/user-guide/using-qsharp/working-with-qubits
    //     //     H(b);
    //     //     DumpMachine(); // https://docs.microsoft.com/en-us/qsharp/api/qsharp/microsoft.quantum.diagnostics.dumpmachine
    //     //     Reset(a); Reset(b);

    //     //     // DumpMachine output:
    //     //     // 0:	 0.707107 +  0.000000 i	 == 	***********          [ 0.500000 ]     --- [  0.00000 rad ]
    //     //     // 1:	 0.000000 +  0.000000 i	 == 	                     [ 0.000000 ]                   
    //     //     // 2:	 0.707107 +  0.000000 i	 == 	***********          [ 0.500000 ]     --- [  0.00000 rad ]
    //     //     // 3:	 0.000000 +  0.000000 i	 == 	                     [ 0.000000 ]   
    //     // }
    // }
}