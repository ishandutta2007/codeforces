namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
			using (qs = Qubit[2]) {
				X(qs[0]);
				X(qs[1]);
				
				for (i in 0..Length(x)-1) {
				  CCNOT(x[i], qs[0], qs[1]);
				  CCNOT(x[i], qs[1], qs[0]);
				}
				CCNOT(qs[0], qs[1], y);
				for (i in 0..Length(x)-1) {
				  CCNOT(x[i], qs[0], qs[1]);
				  CCNOT(x[i], qs[1], qs[0]);
				}
				for (i in 0..Length(x)-1) {
				  CCNOT(x[i], qs[0], qs[1]);
				  CCNOT(x[i], qs[1], qs[0]);
				}
				X(qs[0]);
				X(qs[1]);
			}
        }
        adjoint auto;
    }
}