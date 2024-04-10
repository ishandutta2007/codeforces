namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            (Controlled CNOT)([x[0]],(x[1],y));
            (Controlled CNOT)([x[1]],(x[2],y));
            (Controlled CNOT)([x[2]],(x[0],y));
        }
    }
}