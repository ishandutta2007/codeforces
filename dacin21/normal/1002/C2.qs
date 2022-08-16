namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;

	operation Solve (qs : Qubit) : Int {
        body {
			let r = Random([0.5; 0.5]);
			if(r != 1){
				H(qs);
			}
			if(M(qs) == One){
				return r;
			}
			return -1;
        }
    }
	
	operation setup (qs : Qubit[], _data : Double []) : (){
		body {
			let data = PNormalize (2.0, _data);
			mutable c_data = new ComplexPolar[Length(data)];
			for (i in 0 .. Length(c_data)-1){
				mutable phase = 0.0;
				mutable r = data[i];
				if(r < 0.0){
					set r = - r;
					set phase = 3.1415926535897932384626;
				}
				set c_data[i] = ComplexPolar(r, phase);
			}
			let fun = StatePreparationComplexCoefficients(c_data);
			fun(BigEndian(qs));
		}
	}
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			using (qs = Qubit[1]){
				if((sign &&& 1) == 0){
					setup(qs, [1.0; 0.0]);
				} else {
					setup(qs, [1.0; 1.0]);
				}
				//DumpMachine("");
				//X(qs[sign-1]);
				let res = Solve(qs[0]);
				//DumpMachine("");
				Message($" {sign} -> {res}"); 
				ResetAll(qs);
			}
			return mess;
		}
	}
}