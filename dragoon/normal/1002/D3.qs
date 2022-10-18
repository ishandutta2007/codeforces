namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            CNOT(x[1], x[0]);
            CCNOT(x[0], x[1], x[2]);
            CNOT(x[1], x[0]);
            
            CNOT(x[0], x[2]);
            CCNOT(x[0], x[2], x[1]);
            CNOT(x[0], x[2]);

            CNOT(x[2], x[1]);
            CCNOT(x[1], x[2], x[0]);
            CNOT(x[2], x[1]);
            
            CNOT(x[0], y);
            CNOT(x[1], y);
            CNOT(x[2], y);

            CNOT(x[2], x[1]);
            CCNOT(x[1], x[2], x[0]);
            CNOT(x[2], x[1]);

            CNOT(x[0], x[2]);
            CCNOT(x[0], x[2], x[1]);
            CNOT(x[0], x[2]);

            CNOT(x[1], x[0]);
            CCNOT(x[0], x[1], x[2]);
            CNOT(x[1], x[0]);
        }
    }
}