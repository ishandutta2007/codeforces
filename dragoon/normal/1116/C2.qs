namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
		  let n = Length(x);
		  
		  if (n <= 3) {
		    using (qs = Qubit[1]) {
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);
			  X(y);
			  (ControlledOnInt(0, X))(qs, y);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);
			}
		  }
		  elif (n <= 5) {
		    using (qs = Qubit[2]) {
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);

			  ApplyToEach(X, [x[0], x[n-2]]);
			  Controlled X([x[0], x[1], x[n-2], x[n-1]], qs[1]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[n-2], x[n-1]], qs[1]);
			  ApplyToEach(X, x);
			  ApplyToEach(X, [x[0], x[n-2]]);
			  
			  X(y);
			  (ControlledOnInt(0, X))(qs, y);

			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);

			  ApplyToEach(X, [x[0], x[n-2]]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[n-2], x[n-1]], qs[1]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[n-2], x[n-1]], qs[1]);
			  ApplyToEach(X, [x[0], x[n-2]]);
			}
		  }
		  else {
		    using (qs = Qubit[3]) {
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);

			  ApplyToEach(X, [x[0], x[n-2]]);
			  Controlled X([x[0], x[1], x[n-2], x[n-1]], qs[1]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[n-2], x[n-1]], qs[1]);
			  ApplyToEach(X, x);
			  ApplyToEach(X, [x[0], x[n-2]]);
			  
			  ApplyToEach(X, [x[0], x[n-3]]);
			  Controlled X([x[0], x[1], x[2], x[n-3], x[n-2], x[n-1]], qs[2]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[2], x[n-3], x[n-2], x[n-1]], qs[2]);
			  ApplyToEach(X, x);
			  ApplyToEach(X, [x[0], x[n-3]]);
			  ApplyToEach(X, [x[2], x[n-1]]);
			  Controlled X([x[0], x[1], x[2], x[n-3], x[n-2], x[n-1]], qs[2]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[2], x[n-3], x[n-2], x[n-1]], qs[2]);
			  ApplyToEach(X, x);
			  ApplyToEach(X, [x[2], x[n-1]]);
			  
			  
			  X(y);
			  (ControlledOnInt(0, X))(qs, y);

			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[n-1]], qs[0]);

			  ApplyToEach(X, [x[0], x[n-2]]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[n-2], x[n-1]], qs[1]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[n-2], x[n-1]], qs[1]);
			  ApplyToEach(X, [x[0], x[n-2]]);

			  ApplyToEach(X, [x[2], x[n-1]]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[2], x[n-3], x[n-2], x[n-1]], qs[2]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[2], x[n-3], x[n-2], x[n-1]], qs[2]);
			  ApplyToEach(X, [x[2], x[n-1]]);
			  ApplyToEach(X, [x[0], x[n-3]]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[2], x[n-3], x[n-2], x[n-1]], qs[2]);
			  ApplyToEach(X, x);
			  Controlled X([x[0], x[1], x[2], x[n-3], x[n-2], x[n-1]], qs[2]);
			  ApplyToEach(X, [x[0], x[n-3]]);
	     	}
		  }
        }
        adjoint self;
    }
}