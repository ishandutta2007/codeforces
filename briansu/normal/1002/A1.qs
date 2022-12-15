namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs: Qubit[]) : Unit {
        for(i in 0..Length(qs)-1)
        {
            H(qs[i]);
        }
    }
}