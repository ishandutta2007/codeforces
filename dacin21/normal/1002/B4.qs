namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;

	operation ipow(b : Int, exp : Int) : Int {
        body {
			mutable ret = 1;
			for (i in 1 .. exp){
				set ret = ret * b;
			}
			return ret;
		}
	}
	operation ilg(_b : Int) : Int {
        body {
			mutable b = _b;
			mutable ret = 0;
			for (i in 1..128){
				if (b <= 1) {
					return ret;
				}
				set b = b / 2;
				set ret = ret + 1;
			}
			return 128;
		}
	}
	operation Cpmove(from : Qubit, to : Qubit) : (){
		body{
			(Controlled H)([from], to);
			CNOT(to, from);
		}
	}
	operation Solve (qs : Qubit[]) : Int {
        body {
			H(qs[0]);
			mutable ret = 0;
			if (Measure([PauliX; PauliX], qs) == Zero){
				set ret = ret + 2;
			}
			if (Measure([PauliZ; PauliZ], qs) == Zero){
				set ret = ret + 1;
			}
			return ret;
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
			using (qs = Qubit[2]){
				if(sign == 0){
					setup(qs, [1.0; -1.0; -1.0; -1.0]);
				} else{if (sign == 1) {
					setup(qs, [-1.0; 1.0; -1.0; -1.0]);
				} else{if (sign == 2) { 
					setup(qs, [-1.0; -1.0; 1.0; -1.0]);
				} else {
					setup(qs, [-1.0; -1.0; -1.0; 1.0]);
				} } }
				DumpMachine("");
				//X(qs[sign-1]);
				let res = Solve(qs);
				DumpMachine("");
				Message($" -> {res}"); 
				ResetAll(qs);
			}
			return mess;
		}
	}
}