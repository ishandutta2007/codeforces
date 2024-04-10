// quick ref: https://github.com/microsoft/QuantumKatas/blob/master/quickref/qsharp-quick-reference.pdf
// warmup round: https://codeforces.com/contest/1356
// when including Microsoft.Quantum.MachineLearning you need to modify .csproj manually
    // see HalfMoons.csproj for example

namespace Solution {
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Set (q: Qubit, des: Result) : Unit { // set state of q -> desired
        if (des != M(q)) { X(q); }
    }

    //////////////////////////////////////////////////////////////////
    // Part I. Implementing Quantum Fourier Transform
    //////////////////////////////////////////////////////////////////

    // Task 1.1. 1-qubit QFT
    operation powerH(q: Qubit, p: Int)  : Unit is Adj+Ctl {
        let theta = PI()/4.0;
        Ry(-theta,q);
        R1(PI()/IntAsDouble(p),q);
        Ry(theta,q);
    }
    operation OneQubitQFT_Reference (q : Qubit, p: Int) : Unit is Adj+Ctl {
        powerH(q,p);
    }

    // Task 1.2. Rotation gate
    operation Rotation_Reference (q : Qubit, k : Int, p: Int) : Unit is Adj+Ctl { // 2*pi / 2^k /
        //R1Frac(2, k, q);
        Message("DOING");
        R1(2.0*PI()/IntAsDouble(1<<<k)/IntAsDouble(p),q);
    }

    // Task 1.5. Prepare binary fraction exponent in place (quantum input)
    // Input: A register of qubits in state |jj...j
    // Goal: Change the state of the register
    //       from |j  |j...j
    //         to 1/sqrt(2) (|0 + exp(2i  0.jj...j) |1)  |j...j.
    operation BinaryFractionQuantumInPlace_Reference (register : Qubit[], p: Int) : Unit is Adj+Ctl {
        OneQubitQFT_Reference(register[0],p);
        for (ind in 1 .. Length(register) - 1) {
            Controlled Rotation_Reference([register[ind]], (register[0], ind + 1, p));
        }
    }


    // Task 1.6. Reverse the order of qubits
    // Input: A register of qubits in state |xx...x
    // Goal: Reverse the order of qubits, i.e., convert the state of the register to |x...xx.
    operation ReverseRegister_Reference (register : Qubit[]) : Unit is Adj+Ctl {
        let N = Length(register);
        for (ind in 0 .. N / 2 - 1) {
            SWAP(register[ind], register[N - 1 - ind]);
        }
    }


    // Task 1.7. Quantum Fourier transform
    // Input: A register of qubits in state |jj...j
    // Goal: Apply quantum Fourier transform to the input register, i.e.,
    //       transform it to a state 
    //       1/sqrt(2) (|0 + exp(2i  0.j) |1) 
    //       1/sqrt(2) (|0 + exp(2i  0.jj) |1)  ... 
    //       1/sqrt(2) (|0 + exp(2i  0.jj...jj) |1) 
    operation QuantumFourierTransform_Reference (register : Qubit[],p : Int) : Unit is Adj+Ctl {
        let n = Length(register);
        for (i in 0 .. n - 1) {
            BinaryFractionQuantumInPlace_Reference(register[i ...],p);
        }
        ReverseRegister_Reference(register);
    }
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl { 
        // supposedly https://arxiv.org/pdf/quant-ph/0208130.pdf helps
        using (q = Qubit[2]) { 
            H(q[0]); H(q[1]); // ([00]+[01]+[10]+[11]) x v
            Controlled QFTLE([q[0]],inputRegister); // ([00]+[01]e+[10]e^2+[11]e^3) x v
            Controlled QFTLE([q[1]],inputRegister); // ([01]) x v
            Controlled QFTLE([q[1]],inputRegister);
            Adjoint QFTLE(LittleEndian(q));

            // multiple by eigenvalue^{1/p}
            R1(PI()/2.0/IntAsDouble(p),q[0]);
            R1(PI()/IntAsDouble(p),q[1]); // ([01]e) x v
            
            // now undo everything
            QFTLE(LittleEndian(q));
            Adjoint Controlled QFTLE([q[1]],inputRegister); // ([01]) x v
            Adjoint Controlled QFTLE([q[1]],inputRegister);
            Adjoint Controlled QFTLE([q[0]],inputRegister); // ([00]+[01]e+[10]e^2+[11]e^3) x v
            H(q[0]); H(q[1]); // ([00]+[01]+[10]+[11]) x v
        }
    }
    // @EntryPoint()
    // operation HelloQ() : Unit {
    //     // using (q = Qubit()) {
    //     //     X(q);
    //     //     powerH(q,3);
    //     //     DumpMachine();
    //     //     powerH(q,3);
    //     //     DumpMachine();
    //     //     powerH(q,3);
    //     //     DumpMachine();
    //     //     Reset(q);
    //     // }
    //     using (q = Qubit[2]) {
    //         Solve(2,LittleEndian(q));
    //         DumpMachine();
    //         Solve(2,LittleEndian(q));
    //         DumpMachine();
    //         ResetAll(q);
    //     }
    //     // Message("Hello quantum world!");
    //     // for (i in 1..100) {
    //     //     Message($"{Solve(Y)}");
    //     //     Message($"{Solve(XZ)}");
    //     // }
    //     // let theta = 0.3;
    //     // let y = Ry(theta,_);
    //     // let z = Rz(theta,_);
    //     // for (i in 1..100) {
    //     //     Message($"{i} {Solve(theta,z)} {Solve(theta,y)}");
    //     // }
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