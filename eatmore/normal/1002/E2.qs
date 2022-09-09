namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve(N: Int, Uf: ((Qubit[], Qubit) => ())): Int[] { body {
		mutable res = new Int[N];
		using (qs = Qubit[N]) {
			using (qq = Qubit[1]) {
				let q = qq[0];
				Uf(qs, q);
				set res[0] = N % 2;
				if (M(q) == One) {
					set res[0] = 1 - res[0];
				}
				Reset(q);
			}
			ResetAll(qs);
		}
		return res;
	} }
}