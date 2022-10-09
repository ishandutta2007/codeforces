namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    
    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                // Prepare k-th basis vector
                let binary = BoolArrFromPositiveInt(k, N);
                
                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                
                // Apply the operation
                unitary(qs);
                
                // Dump the contents of the k-th column
                DumpMachine($"DU_{N}_{k}.txt");
                
                ResetAll(qs);
            }
        }
    }

    // The operation which is called from C# code
    operation CallDumpUnitary (N : Int) : Unit {
        // make sure the operation passed to DumpUnitaryToFiles matches the number of qubits set in Driver.cs
        // let unitary = ApplyToEach(I, _);

        DumpUnitaryToFiles(N, Solve);
    }

    operation makeQuater1(qs: Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);
            if (n != 1) {
                makeQuater1(qs[0..n - 2]);
                X(qs[n - 1]);
                Controlled X(qs[0..n-2], qs[n - 1]);
            }
        }
        controlled auto;
    }

    operation makeQuater2(qs: Qubit[]) : Unit {
        body(...) {
            let n = Length(qs);
            if (n == 1) {
                X(qs[0]);
            } else {
                makeQuater2(qs[0..n - 2]);
                Controlled X(qs[0..n-2], qs[n - 1]);
            }
        }
        controlled auto;
    }

    operation Solve (qs : Qubit[]) : Unit {
        let last = Length(qs) - 1;
        X(qs[last]);
        Controlled makeQuater1([qs[last]], qs[0..last - 1]);
        X(qs[last]);
        Controlled makeQuater2([qs[last]], qs[0..last - 1]);
        H(qs[last]);
        for (i in 0..last - 1) {
            CNOT(qs[last], qs[i]);
        }
    }
}