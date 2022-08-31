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

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
			if(sign == -1){
				X(q);
			}
			H(q);
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			for (it in 1..100){
				using (qubit = Qubit[1]) {
					Solve(qubit[0], sign);
					//Set (One, qubit[0]);
					//Set (Zero, qubit[1]);
					
					// these don't work for some reason
					//DumpMachine(());
					//DumpRegister((), qubit);
					
					//set mess = $"0={qubit[0]};";
					H(qubit[0]);
					let a = M(qubit[0]);
					set mess = mess + $"0={a};#";
					ResetAll(qubit);
				}
			}
			return mess;
		}
	}
}