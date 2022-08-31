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
	operation Solve (qs : Qubit[], a : Bool[], b : Bool[]) : () {
        body {
			mutable j = 0;
			mutable _break = false;
			for(i in 0..Length(a)-1){
				if(_break == false){
				if(a[i] != b[i]){
					set j = i;
					set _break = true;
				}
			} }
			H(qs[j]);
			for(i in 0..Length(a)-1) { if(i != j) {
				if(a[i] != b[i]){
					if(a[i] != a[j]){
						X(qs[i]);
					}
					CNOT(qs[j], qs[i]);
				} else{if (a[i]){
					X(qs[i]);
				} }
			} }
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			using (qs = Qubit[5]){
				let a = [false; true; true; true; true];
				let b = [false; true; true; false; false];
				Solve(qs, a, b);
				DumpMachine("");
				ResetAll(qs);
			}
			return mess;
		}
	}
}