// make sure to reset qubits to zero!
// quick reference: https://assets.codeforces.com/rounds/997-998/qs-language-quick-reference.pdf

namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current) { X(q1); }
        }
    }

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            // your code here
            for (i in 0..Length(qs)-1) {
                H(qs[i]);
            }
        }
    }
}