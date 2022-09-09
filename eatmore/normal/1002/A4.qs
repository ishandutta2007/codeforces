namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve(qs: Qubit[]): () { body {
		X(qs[0]);
		mutable p2 = 0;
		for (i in 1 .. Length(qs) - 1) {
			if ((i &&& -i) == i) {
				if (p2 != 0) {
					CNOT(qs[p2], qs[0]);
				}
				H(qs[i]);
				set p2 = i;
			} else {
				(Controlled SWAP)([qs[p2]], (qs[i - p2], qs[i]));
				CNOT(qs[i], qs[p2]);
			}
		}
		if (p2 != 0) {
			CNOT(qs[p2], qs[0]);
		}
	} }
}