namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
	  let n = Length(qs);
	  // First part
	  X(qs[n - 1]);
	  for (i in n-2..-1..1) {
	    ApplyToEach(X, qs[0..i-1]);
		using (ax = Qubit[1]) {
	      X(ax[0]);
          (ControlledOnInt(0, X))(qs[0..i-1], ax[0]);
		  CCNOT(qs[n-1], ax[0], qs[i]);
          (ControlledOnInt(0, X))(qs[0..i-1], ax[0]);
	      X(ax[0]);
		}
	    ApplyToEach(X, qs[0..i-1]);
	  }
	  X(qs[n - 1]);

	  // Second part
	  for (i in 0..n-2) {
	    CNOT(qs[n-1], qs[i]);
	  }
	  for (i in n-2..-1..1) {
	    ApplyToEach(X, qs[0..i-1]);
		using (ax = Qubit[1]) {
	      X(ax[0]);
          (ControlledOnInt(0, X))(qs[0..i-1], ax[0]);
		  CCNOT(qs[n-1], ax[0], qs[i]);
          (ControlledOnInt(0, X))(qs[0..i-1], ax[0]);
	      X(ax[0]);
		}
	    ApplyToEach(X, qs[0..i-1]);
	  }
	  
	  // Third part
	  H(qs[n-1]);
	  for (i in 0..n-2) {
	    CNOT(qs[n-1], qs[i]);
	  }
    }
}