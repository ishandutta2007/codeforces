namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;
	

	operation Solve (n : Int, fun : ((Qubit[], Qubit) => ())) : Int[] {
        body {
			mutable ret = new Int[n];
			using (qs = Qubit[n+1]){
				X(qs[n]);
				for(i in 0..n){
					H(qs[i]);
				}
				fun(qs[0..n-1], qs[n]);
				for(i in 0..n){
					H(qs[i]);
				}
				
				for(i in 0..n-1){
					set ret[i] = 0;
					if(M(qs[i]) == One){
						set ret[i] = 1;
					}
				}
				ResetAll(qs);
			}
			return ret;
        }
    }
	
	operation or (x : Qubit[], y : Qubit) : () {
        body
        {
			CNOT(x[0], y);
			CNOT(x[3], y);
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
				//DumpMachine("");
				//X(qs[sign-1]);
				let res = Solve(4, or);
				//DumpMachine("");
				Message($" {sign} -> {res}"); 
				ResetAll(qs);
			}
			return mess;
		}
	}
}