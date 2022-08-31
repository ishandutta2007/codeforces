namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;
	
	operation Set (desired: Result, q1: Qubit) : () {
        body {
            let current = M(q1);
            if (desired != current) {
                X(q1);
            }
        }
    }
	
	operation Bell (q : Qubit[], sign : Int) : () {
        body {
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
    }
	
	operation PM (q : Qubit, sign : Int) : () {
        body {
			if(sign == -1){
				X(q);
			}
			H(q);
        }
    }


    operation GG (q : Qubit[], p : Qubit, k : Int) : () {
        body {
			CNOT(q[k], p);
        }
    }     
	operation GG1 (q : Qubit[], p : Qubit) : () {
        body {
			CNOT(q[1], p);
        }
    }    
	operation Popcount (q : Qubit[], p : Qubit) : () {
        body {
			for(i in 0..Length(q)-1){
				GG(q, p, i);
			}
        }
    } 	
	operation S0 (q : Qubit[], p : Qubit) : () {
        body {
			Set(Zero, p);
        }
    } 
	operation S1 (q : Qubit[], p : Qubit) : () {
        body {
			Set(One, p);
        }
    } 
	operation Solve (qs : Qubit[]) : () {
        body {
			for(i in 0..Length(qs)-1){
			  H(qs[i]);
			}
        }
    }
	

	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			using (qubit = Qubit[sign]) {
				Solve(qubit);
				
				DumpMachine("");
				
				set mess = mess + $"0={sign};#";
				ResetAll(qubit);
			}
			return mess;
		}
	}
}