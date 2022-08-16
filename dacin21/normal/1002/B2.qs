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
			let n = Length(qs);
			mutable cnt = 0;
			for(i in 0..n-1){
				if(M(qs[i]) == One){
					set cnt = cnt + 1;
				}
			}
			if(cnt == 1){
				return 1;
			}
			
			return 0;
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			using (qs = Qubit[sign]){
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