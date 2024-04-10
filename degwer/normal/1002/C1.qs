namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(0.78539816339,q);
            if(M(q)==One){return 1;}
            else{return 0;}
        }
    }
}