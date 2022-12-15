namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (q: Qubit) : Int {
        H(q);
        if(M(q) == One){
            return -1;
        }
        else {
            return 1;
        }
    }
}