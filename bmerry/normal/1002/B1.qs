namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            let N = Length(qs);
            mutable p = new Pauli[N];
            for (i in 0..N-1)
            {
                set p[i] = PauliZ;
            }
            if (Measure(p, qs) == One)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}