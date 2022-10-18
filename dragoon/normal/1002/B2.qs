namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable n = 0;
            for (i in 0..Length(qs)-1) {
                if (M(qs[i]) == One) {
                    set n = n + 1;
                }
            }
            if (n == 1) {
                return 1;
            }
            return 0;
        }
    }
}