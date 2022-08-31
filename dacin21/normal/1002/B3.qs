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
			mutable ret = 0;
			if (Measure([PauliX; PauliX], qs) == One){
				set ret = ret + 2;
			}
			if (Measure([PauliX], qs[1..1]) == One){
				set ret = ret + 1;
			}
			if(ret != 0){
				set ret = 4 - ret;
			}
			return ret;
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			using (qs = Qubit[2]){
				if((sign &&& 1) != 0){
					X(qs[0]);
					X(qs[1]);
				}
				if((sign &&& 2) != 0){
					CNOT(qs[0], qs[1]);
				}
				H(qs[0]);
				H(qs[1]);
				DumpMachine("");
				//X(qs[sign-1]);
				let res = Solve(qs);
				Message($" -> {res}"); 
				DumpMachine("");
				ResetAll(qs);
			}
			return mess;
		}
	}
}