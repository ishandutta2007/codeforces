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

    operation makeBase(qs: Qubit[]) : Unit {
        body (...) {
            X(qs[2]);
            Controlled H([qs[2]], qs[0]);
            X(qs[2]);
            Controlled H([qs[2]], qs[0]);
            Controlled H([qs[2]], qs[1]);
        }
        adjoint invert;
    }

    operation swapRow05(qs: Qubit[]) : Unit {
        body(...) {
            X(qs[0]);
            X(qs[1]);
            CCNOT(qs[0], qs[1], qs[2]);
            X(qs[0]);
            X(qs[1]);
        }
        adjoint invert;
    }

    operation swapRow14(qs: Qubit[]) : Unit {
        body (...) {
            X(qs[2]);
            CNOT(qs[2], qs[1]);
            X(qs[2]);
            Controlled SWAP([qs[0]], (qs[1], qs[2]));
            X(qs[2]);
            CNOT(qs[2], qs[1]);
            X(qs[2]);
        }
        adjoint invert;
    }

    operation swapRow24(qs: Qubit[]): Unit {
        body(...) {
            X(qs[0]);
            Controlled SWAP([qs[0]], (qs[1], qs[2]));
            X(qs[0]);
        }
        adjoint invert;
    }

    operation Solve1(qs: Qubit[]): Unit {
        body(...) {
            makeBase(qs);

            swapRow14(qs);
            swapRow05(qs);
            swapRow24(qs);
        }
        adjoint invert;
    }

    operation Solve (qs : Qubit[]) : Unit {
        // makeBase(qs);
        Adjoint Solve1(qs);
        swapRow14(qs);
        swapRow05(qs);
    }
}