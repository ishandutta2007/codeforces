namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;
	
	operation Set (desired: Result, q1: Qubit) : Unit {
            let current = M(q1);
            if (desired != current) {
                X(q1);
            }
    }
	
	operation Bell (q : Qubit[], sign : Int) : Unit {
			if((sign&&&2) == 2){
				Set(One, q[1]);
				//Z(q[1]);
			}
			if((sign&&&1) == 1){
				X(q[0]);
			}
			H(q[0]);
			CNOT(q[0], q[1]);
    }
	
	operation PM (q : Qubit, sign : Int) : Unit {
			if(sign == -1){
				X(q);
			}
			H(q);
    }


    operation GG (q : Qubit[], p : Qubit, k : Int) : Unit {
			CNOT(q[k], p);
    }     
	operation GG1 (q : Qubit[], p : Qubit) : Unit {
			CNOT(q[1], p);
    }    
	operation Popcount (q : Qubit[], p : Qubit) : Unit {
			for(i in 0..Length(q)-1){
				GG(q, p, i);
			}
    } 	
	operation S0 (q : Qubit[], p : Qubit) : Unit {
			Set(Zero, p);
    } 
	operation S1 (q : Qubit[], p : Qubit) : Unit {
			Set(One, p);
    }
	//operation Modinc(anc : Qubit[]) : Unit {
	//	body (...) {
	//		let cnt = LittleEndian(anc);
	//		IntegerIncrementLE(1, cnt);
	//		X(anc[0]);
	//		SWAP(anc[0], anc[1]);
	//		X(anc[0]);
	//	}
	//	controlled adjoint auto;
	//}
	//
	//operation Sumup(x : Qubit[], anc : Qubit[]) : Unit {
	//	body (...) {
	//		for(i in 0..Length(x)-1){
	//			let cnt = LittleEndian(anc);
	//			(Controlled Modinc)([x[i]], (anc));
	//		}
	//	}
    //    adjoint auto;
	//
	//}
	//		
	//operation Solve (x : Qubit[], y : Qubit) : Unit {
    //    body (...) {
	//		using (anc = Qubit[2]){
	//			Sumup(x, anc);
	//			ApplyToEachCA(X, anc);
	//			CCNOT(anc[0], anc[1], y);
	//			ApplyToEachCA(X, anc);
	//			(Adjoint Sumup)(x, anc);
	//		}
    //    }
    //    adjoint auto;
    //}
	
	
	operation Solve (qs : Qubit[]) : Unit {
		let n = Length(qs)-1;
		for(i in 0..n-1){
			CNOT(qs[n], qs[i]);
		}
		H(qs[n]);
		X(qs[n]);
		for(i in 0..n-1){
			CNOT(qs[n], qs[i]);
		}
		let cnt = LittleEndian(qs[0..n-1]);
		for(i in 0..n-1){
			CNOT(qs[n], qs[i]);
		}
		
		X(qs[n]);
		for(i in 0..n-1){
			CNOT(qs[n], qs[i]);
		}
		(Controlled IntegerIncrementLE)([qs[n]], ((1<<<n)-1, cnt));
		X(qs[n]);
		(Controlled IntegerIncrementLE)([qs[n]], (1, cnt));
	}
	
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
        let unitary = Solve(_);

        DumpUnitaryToFiles(N, unitary);
	}

}