namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve(x: Qubit[], y: Qubit, b: Int[]): () { body {
		mutable flip = Length(x) % 2 == 1;
		for (i in 0 .. Length(x) - 1) {
			if (b[i] != 0) {
				set flip = !flip;
			}
			CNOT(x[i], y);
		}
		if (flip) {
			X(y);
		}
	} }
}