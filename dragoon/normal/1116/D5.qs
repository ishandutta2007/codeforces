namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        Controlled H([qs[2], qs[1]], qs[0]);
		Controlled X([qs[2]], qs[1]);
		X(qs[2]);
		Controlled X([qs[2], qs[1]], qs[0]);
		X(qs[1]);
		Controlled H([qs[2], qs[1]], qs[0]);
		X(qs[1]);
		X(qs[2]);
		H(qs[2]);
		CCNOT(qs[2], qs[1], qs[0]);
		CCNOT(qs[0], qs[1], qs[2]);
		CNOT(qs[2], qs[1]);
    }
}