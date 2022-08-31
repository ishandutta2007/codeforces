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
    operation OneQubitQFT_Reference (q : Qubit) : Unit is Adj+Ctl {
        H(q);
    }
 
    // Task 1.2. Rotation gate
    operation Rotation_Reference (q : Qubit, k : Int) : Unit is Adj+Ctl {
        R1Frac(2, k, q);
    }
    
 
    // Task 1.3. Prepare binary fraction exponent (classical input)
    // Inputs:
    //      1) A qubit in state | =  |0 +  |1
    //      2) An array of bits [j, j, ..., j], stored as Int[] (j  {0, 1}).
    // Goal: Change the state of the qubit to  |0 +   exp(2i  0.jj...j) |1,
    // where 0.jj...j is a binary fraction, similar to decimal fractions:
    //       0.jj...j = j / 2 + j / 2 + ... + j / 2.
    operation BinaryFractionClassical_Reference (q : Qubit, j : Int[]) : Unit is Adj+Ctl {
        for (ind in 0 .. Length(j) - 1) {
            if (j[ind] == 1) {
                Rotation_Reference(q, ind + 1);
            }
        }
    }
 
 
    function IntArrayAsInt (j : Int[]) : Int {
        mutable n = 0;
        for (ind in 0 .. Length(j) - 1) {
            set n = n * 2 + j[ind];
        }
        return n;
    }
 
    operation BinaryFractionClassical_Alternative (q : Qubit, j : Int[]) : Unit is Adj+Ctl {
        // alternatively, we can convert the number to an integer and apply a single R1 rotation
        let num = IntArrayAsInt(j);
        R1(2.0 * PI() * IntAsDouble(num) / IntAsDouble(1 <<< Length(j)), q);
    }
 
 
    // Task 1.4. Prepare binary fraction exponent (quantum input)
    // Inputs:
    //      1) A qubit in state | =  |0 +  |1
    //      2) A register of qubits in state |jj...j
    // Goal: Change the state of the input 
    //       from ( |0 +  |1)  |jj...j
    //         to ( |0 +   exp(2i  0.jj...j) |1)  |jj...j,
    //       where 0.jj...j is a binary fraction corresponding to the basis state jj...j of the register.
    operation BinaryFractionQuantum_Reference (q : Qubit, jRegister : Qubit[]) : Unit is Adj+Ctl {
        for (ind in 0 .. Length(jRegister) - 1) {
            Controlled Rotation_Reference([jRegister[ind]], (q, ind + 1));
        }
    }
 
 
    // Task 1.5. Prepare binary fraction exponent in place (quantum input)
    // Input: A register of qubits in state |jj...j
    // Goal: Change the state of the register
    //       from |j  |j...j
    //         to 1/sqrt(2) (|0 + exp(2i  0.jj...j) |1)  |j...j.
    operation BinaryFractionQuantumInPlace_Reference (register : Qubit[]) : Unit is Adj+Ctl {
        OneQubitQFT_Reference(register[0]);
        for (ind in 1 .. Length(register) - 1) {
            Controlled Rotation_Reference([register[ind]], (register[0], ind + 1));
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
    operation QuantumFourierTransform_Reference (register : Qubit[]) : Unit is Adj+Ctl {
        let n = Length(register);
        for (i in 0 .. n - 1) {
            BinaryFractionQuantumInPlace_Reference(register[i ...]);
        }
        ReverseRegister_Reference(register);
    }
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl { 
        // your code here
        let q = inputRegister!;
        let up = p%4;
        for (i in 1..up) {
            QFTLE(inputRegister);
            // QuantumFourierTransform_Reference(q);
        }
    }
    // @EntryPoint()
    operation HelloQ() : Unit {
        using (q = Qubit[3]) {
            Solve(13,LittleEndian(q));
            DumpMachine();
            ResetAll(q);
        }
        // Message("Hello quantum world!");
        // for (i in 1..100) {
        //     Message($"{Solve(Y)}");
        //     Message($"{Solve(XZ)}");
        // }
        // let theta = 0.3;
        // let y = Ry(theta,_);
        // let z = Rz(theta,_);
        // for (i in 1..100) {
        //     Message($"{i} {Solve(theta,z)} {Solve(theta,y)}");
        // }
        // using ((a,b) = (Qubit(),Qubit())) { // https://docs.microsoft.com/en-us/quantum/user-guide/using-qsharp/working-with-qubits
        //     H(b);
        //     DumpMachine(); // https://docs.microsoft.com/en-us/qsharp/api/qsharp/microsoft.quantum.diagnostics.dumpmachine
        //     Reset(a); Reset(b);
 
        //     // DumpMachine output:
        //     // 0:	 0.707107 +  0.000000 i	 == 	***********          [ 0.500000 ]     --- [  0.00000 rad ]
        //     // 1:	 0.000000 +  0.000000 i	 == 	                     [ 0.000000 ]                   
        //     // 2:	 0.707107 +  0.000000 i	 == 	***********          [ 0.500000 ]     --- [  0.00000 rad ]
        //     // 3:	 0.000000 +  0.000000 i	 == 	                     [ 0.000000 ]   
        // }
    }
}