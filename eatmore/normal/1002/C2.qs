namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve(q: Qubit): Int { body {
		mutable res = -1;
		using (qs = Qubit[1]) {
			let q2 = qs[0];
			R(PauliY, -PI() / 4.0, q);
			X(q);
			(Controlled R)([q], (PauliY, ArcCos(Tan(PI() / 8.0)) * 2.0, q2));
			X(q2);
			(Controlled H)([q2], q);
			if (M(q2) == One) {
				if (M(q) == One) {
					set res = 0;
				} else {
					set res = 1;
				}
			}
			Reset(q2);
		}
		return res;
	} }
}