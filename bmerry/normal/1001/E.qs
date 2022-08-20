namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            (Adjoint CNOT)(qs[0], qs[1]);
            (Adjoint H)(qs[0]);
            let r0 = M(qs[0]);
            let r1 = M(qs[1]);
            if (r0 == Zero && r1 == Zero)
            {
                return 0;
            }
            elif (r0 == One && r1 == Zero)
            {
                return 1;
            }
            elif (r0 == Zero && r1 == One)
            {
                return 2;
            }
            return 3;
        }
    }
}