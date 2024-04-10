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

    function nRow(qs: Qubit[]): Int { return 1 <<< Length(qs); }

    function numToBitArray(n: Int, len: Int) : Bool[] {
        mutable x = new Bool[len];
        for (i in 0..len - 1) {
            set x[i] = ((n >>> i) &&& 1) == 1;
        }
        return x;
    }

    function findDiff(a: Bool[], b: Bool[]) : Int {
        mutable diffPos = -1;
        for (i in 0..Length(a) - 1) {
            if (a[i] != b[i]) {
                set diffPos = i;
            }
        }
        return diffPos;
    }

    operation moveToRowWithAll1(qs: Qubit[], rowBits: Bool[], controlledBit: Int): Unit {
        body(...) {
            if (not rowBits[controlledBit]) {
                X(qs[controlledBit]);
            }
            for (i in 0..Length(qs) - 1) {
                if (i != controlledBit && not rowBits[i]) {
                    CNOT(qs[controlledBit], qs[i]);
                }
            }
            if (not rowBits[controlledBit]) {
                X(qs[controlledBit]);
            }
        }
        adjoint invert;
        controlled auto;
        adjoint controlled invert;
    }

    operation swapRows(qs: Qubit[], r1: Int, r2: Int): Unit {
        body (...) {
            let n1 = numToBitArray(r1, Length(qs));
            let n2 = numToBitArray(r2, Length(qs));
            let diffPos = findDiff(n1, n2);
            if (diffPos != -1) {
                moveToRowWithAll1(qs, n1, diffPos);
                moveToRowWithAll1(qs, n2, diffPos);

                Controlled X(Exclude([diffPos], qs), qs[diffPos]);

                Adjoint moveToRowWithAll1(qs, n1, diffPos);
                Adjoint moveToRowWithAll1(qs, n2, diffPos);
            }
        }
        adjoint invert;
        controlled auto;
        adjoint controlled invert;
    }

    operation shiftRowToLast(qs: Qubit[], r: Int): Unit {
        body (...) {
            for (i in r .. nRow(qs) - 2) {
                swapRows(qs, i, i + 1);
            }
        }
        adjoint invert;
        controlled auto;
        adjoint controlled invert;
    }

    operation shiftRowToTop(qs: Qubit[], r: Int): Unit {
        body (...) {
            for (i in r .. -1..1) {
                swapRows(qs, i, i - 1);
            }
        }
        adjoint invert;
        controlled auto;
        adjoint controlled invert;
    }

    operation applyQ(qs: Qubit[]): Unit {
        body(...) {
            let last = Length(qs) - 1;
            swapRows(qs, 0, nRow(qs) - 1);
            for (f in 1 .. nRow(qs) - 2) {
                swapRows(qs, f, nRow(qs) - 2);
                Controlled H(Exclude([0], qs), qs[0]);
                swapRows(qs, f, nRow(qs) - 2);
            }
            shiftRowToLast(qs, 0);
            Controlled H(Exclude([0], qs), qs[0]);
        }
        adjoint invert;
        controlled auto;
        adjoint controlled invert;
    }

    operation Solve (qs : Qubit[]) : Unit {
        Adjoint applyQ(qs);
    }
}