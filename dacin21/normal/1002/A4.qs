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
	operation Solve (qs : Qubit[]) : () {
        body {
			X(qs[0]);
			
		
			let n = Length(qs);
			let k = ilg(n);
			for (i in 0..k-1){
				let nn = ipow(2, i);
				for (j in 0 .. nn-1){
					Cpmove(qs[j], qs[j+nn]);
				}
			}
        }
    }
	
	operation MMain(sign: Int) : String {
		body {
			mutable mess = "";
			using (qs = Qubit[sign]){
				Solve(qs);
				DumpMachine("");
				ResetAll(qs);
			}
			return mess;
		}
	}
}