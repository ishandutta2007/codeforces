namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            H(qs[1]);
            mutable a = M(qs[0]);
            mutable b = M(qs[1]);
            if (a == Zero && b == Zero) {
                return 0;
            }
            elif (a == One && b == Zero) {
                return 2;
            }
            elif (a == Zero && b == One) {
                return 1;
            }
            else {
                return 3;
            }
            //return ResultAsInt([M(qs[0]); M(qs[1])])
        }
    }
}