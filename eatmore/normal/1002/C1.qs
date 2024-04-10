namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Math;

	operation Solve(q: Qubit): Int { body {
		R(PauliY, PI() / 4.0, q);
		if (M(q) == One) {
			return 1;
		} else {
			return 0;
		}
	} }
}