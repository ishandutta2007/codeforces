namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            H(qs[1]);
            let r0 = M(qs[0]);
            let r1 = M(qs[1]);
            if (r0 == Zero && r1 == Zero)
            {
                return 0;
            }
            elif (r0 == Zero && r1 == One)
            {
                return 1;
            }
            elif (r1 == Zero)
            {
                return 2;
            }
            else
            {
                return 3;
            }
        }
    }
}