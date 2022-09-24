namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n=Length(x);
			using(q = Qubit[n-1]) {
				for (i in 0..n-2)
				{
					CNOT(x[i],q[i]);
					CNOT(x[i+1],q[i]);
				}
				Controlled X (q, y);
				for (i in 0..n-2)
				{
					CNOT(x[i],q[i]);
					CNOT(x[i+1],q[i]);
				}
			}
        }
        adjoint auto;
    }
}