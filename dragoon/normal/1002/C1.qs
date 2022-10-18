namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            T(q);
            T(q);
            T(q);
            T(q);
            T(q);
            H(q);
            T(q);
            H(q);
            
            if (M(q) == Zero) {
                return 0;
            }
            return 1;
        }
    }
}