namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve(qs: Qubit[]): Int { body {
		mutable z = false;
		mutable o = false;
		for (i in 0 .. Length(qs) - 1) {
			if (M(qs[i]) == One) {
				set o = true;
			} else {
				set z = true;
			}
		}
		if (o == z) {
			return 1;
		} else {
			return 0;
		}
	} }
}