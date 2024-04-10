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

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        // your code here
        using (q = Qubit[4]) {
            let N = Length(inputs);
            let L = LittleEndian(q);
            for (i in 0..N-1) {
                if (i %2 == 0) {
                    (Controlled Incr)([inputs[i]],L);
                } else {
                    (Controlled Decr)([inputs[i]],L);
                }
            }
            (ControlledOnInt(0,X))(q,output);
            (ControlledOnInt(3,X))(q,output);
            (ControlledOnInt(6,X))(q,output);
            (ControlledOnInt(13,X))(q,output);
            (ControlledOnInt(10,X))(q,output);
            for (i in 0..N-1) {
                if (i %2 == 0) {
                    (Controlled Decr)([inputs[i]],L);
                } else {
                    (Controlled Incr)([inputs[i]],L);
                }
            }
        }
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