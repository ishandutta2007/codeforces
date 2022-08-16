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

    operation Solve (q : Qubit[]) : ()
    {
        body
        {
			H(q[0]);
			for (i in 1..Length(q)-1){
				CNOT(q[0], q[i]);
			}
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			for (it in 1..1){
				using (qubit = Qubit[sign]) {
					Solve(qubit);
					//Set (One, qubit[0]);
					//Set (Zero, qubit[1]);

					DumpMachine($"dump{sign}.txt");
					
					ResetAll(qubit);
				}
			}
			return mess;
		}
	}
}