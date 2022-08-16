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
	operation Solve (n : Int, f : ((Qubit[], Qubit) => ())) : Bool {
        body {
			mutable ret_val = true;
			mutable did_return = false;
			using (q = Qubit[n+1]){
				for(i in 0..n-1){
					PM(q[i], 1);
				}
				PM(q[n], -1);
				f(q[0..n-1], q[n]);
				ApplyToEachCA(H, q[0..n-1]);
				
				for(i in 0..n-1) { if (did_return == false){
					if(M(q[i]) == One){
						set ret_val = false;
						set did_return = true;
						//break;
						// return false;
					}
				}}
				ResetAll(q);
			}
			return ret_val;
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			for (it in 1..1){
				mutable bb = false;
				
				if(sign == 0){
					set bb = Solve(2, Popcount);
				} else{if (sign == 1){
					set bb = Solve(3, GG1);
				} else{if (sign == 2){
					set bb = Solve(2, S0);
				} else { if(sign == 3){
					set bb = Solve(2, S1);
				} } } }
				set mess = mess + $"{sign} -> {bb}#";
			}
			return mess;
		}
	}
}