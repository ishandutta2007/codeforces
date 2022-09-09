namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve(N: Int, Uf: ((Qubit[], Qubit) => ())): Int[] { body {
		mutable res = new Int[N];
		using (qs = Qubit[N]) {
			using (qq = Qubit[1]) {
				let q = qq[0];
				for (i in 0 .. N - 1) {
					H(qs[i]);
				}
				X(q);
				H(q);
				Uf(qs, q);
				for (i in 0 .. N - 1) {
					H(qs[i]);
					if (M(qs[i]) == One) {
						set res[i] = 1;
					}
				}
				Reset(q);
			}
			ResetAll(qs);
		}
		return res;
	} }
}