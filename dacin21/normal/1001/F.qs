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


    operation Solve (q : Qubit[], b1 : Bool[], b2 : Bool[]) : Int {
        body {
			for(i in 0..Length(b1)-1){
				if(b1[i]){
					X(q[i]);
				}
			}
			for(i in 0..Length(q)-1){
				if(M(q[i]) == One){
					return 1;
				}
			}
			return 0;
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			for (it in 1..1){
				using (qubit = Qubit[2]) {
					Bell(qubit, sign);
					//mutable aa = Bool[2]{true, true};
					//mutable ba = Bool[2]{1, 1};
					let ret = Solve(qubit, [false; false], [true; true]);

					DumpMachine($"dump{sign}.txt");
					
					set mess = mess + $"{sign} -> {ret}#";
					ResetAll(qubit);
				}
			}
			return mess;
		}
	}
}