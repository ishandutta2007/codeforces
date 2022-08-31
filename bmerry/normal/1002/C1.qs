namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(0.785398163397448, q);
            if (M(q) == One)
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