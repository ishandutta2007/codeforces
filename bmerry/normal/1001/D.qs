namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            (Adjoint H)(q);
            let r = M(q);
            if (r == Zero)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}