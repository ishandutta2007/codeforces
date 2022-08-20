namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current) { X(q1); }
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable ans = true;
            using (register = Qubit[N]) {
                using (res = Qubit[1]) {
                    // initialize
                    for (i in 0..N-1) {
                        Set(Zero,register[i]); H(register[i]);
                    }
                    Set(One,res[0]); H(res[0]);

                    // apply oracle
                    Uf(register,res[0]);

                    // apply hadamard again
                    for (i in 0..N-1) {
                        H(register[i]);
                        if (M(register[i]) == One) {
                            set ans = false;
                        }
                    }
				    for (i in 0..N-1) {
					    Set(Zero,register[i]);
				    }
                    Set(Zero,res[0]);
                }
            }
            return ans;
        }
    }
}