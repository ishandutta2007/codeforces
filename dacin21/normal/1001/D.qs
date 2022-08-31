namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;
	
	operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }
	
	operation Bell (q : Qubit[], sign : Int) : ()
    {
        body
        {
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
	
	operation PM (q : Qubit, sign : Int) : ()
    {
        body
        {
			if(sign == -1){
				X(q);
			}
			H(q);
        }
    }

    operation Solve (q : Qubit) : Int
    {
        body
        {
			H(q);
			let mres = M(q);
			if(mres == Zero){
				return 1;
			} else {
				return -1;
			}
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			for (it in 1..1){
				using (qubit = Qubit[1]) {
					PM(qubit[0], sign);
					let ret = Solve(qubit[0]);

					//DumpMachine($"dump{sign}.txt");
					
					set mess = mess + $"{sign} -> {ret}#";
					ResetAll(qubit);
				}
			}
			return mess;
		}
	}
}