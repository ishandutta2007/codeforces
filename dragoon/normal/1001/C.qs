namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            mutable n = 0;
            set n = Length(qs);
            set n = n - 1;
            H(qs[0]);
            for (i in 1..n) {
              CNOT(qs[0], qs[i]);
            }
        }
    }
}