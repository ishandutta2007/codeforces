namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            return Measure([PauliX], [q]) == Zero ? 1 | -1;
        }
    }
}