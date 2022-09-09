namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve(qs: Qubit[], bits0: Bool[], bits1: Bool[]): () { body {
		mutable first = true;
		mutable firstI = -1;
		mutable firstV = false;
		for (i in 0 .. Length(qs) - 1) {
			if (bits0[i] == bits1[i]) {
				if (bits0[i]) {
					X(qs[i]);
				}
			} elif (first) {
				set first = false;
				H(qs[i]);
				set firstI = i;
				set firstV = bits0[i];
			} else {
				CNOT(qs[firstI], qs[i]);
				if (bits0[i] != firstV) {
					X(qs[i]);
				}
			}
		}
	} }
}