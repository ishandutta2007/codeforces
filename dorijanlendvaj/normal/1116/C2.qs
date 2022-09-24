namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n=Length(x);
			let c=((n+1)/2-1);
			let d=n-1-((n+1)/2);
			using(q = Qubit[n-c+d]) {
				for (r in 0..d)
				{
					let p=r+1+c;
					for (i in 0..n-p-1)
					{
						CNOT(x[i],q[i+d+1]);
						CNOT(x[i+p],q[i+d+1]);
						X(q[i+d+1]);
					}
					Controlled X (Subarray(IntArrayFromRange(d+1..n-p+d),q), q[r]);
					for (i in 0..n-p-1)
					{
						CNOT(x[i],q[i+d+1]);
						CNOT(x[i+p],q[i+d+1]);
						X(q[i+d+1]);
					}
				}
				X(y);
				(ControlledOnInt(0, X))(q, y);
				for (r in 0..d)
				{
					let p=r+1+c;
					for (i in 0..n-p-1)
					{
						CNOT(x[i],q[i+d+1]);
						CNOT(x[i+p],q[i+d+1]);
						X(q[i+d+1]);
					}
					Controlled X (Subarray(IntArrayFromRange(d+1..n-p+d),q), q[r]);
					for (i in 0..n-p-1)
					{
						CNOT(x[i],q[i+d+1]);
						CNOT(x[i+p],q[i+d+1]);
						X(q[i+d+1]);
					}
				}
			}
        }
        adjoint auto;
    }
}