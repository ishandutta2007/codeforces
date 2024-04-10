namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs: Qubit[]) : Unit {
        H (qs[0]);
        for(i in 1..Length(qs) - 1)
        {
            CNOT(qs[0], qs[i]);
        }
    }
}