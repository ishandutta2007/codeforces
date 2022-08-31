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
	operation Solve (q : Qubit[], p : Qubit) : () {
        body {
			for(i in 0..Length(q)-1){
				GG(q, p, i);
			}
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			for (it in 1..1){
				using (qubit = Qubit[2]) {
				using (qq = Qubit[1]) {
					Bell(qubit, sign);
					Solve(qubit, qq[0]);

					DumpMachine($"dump{sign}.txt");
					
					set mess = mess + $"qq -> {qq}#";
					ResetAll(qubit);
					ResetAll(qq);
				}
				}
			}
			return mess;
		}
	}
}