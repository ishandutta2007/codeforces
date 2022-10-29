namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            mutable r=0;
            if(M(qs[1])==One){set r=r+2;}
            if(M(qs[0])==One){set r=r+1;}
            return r;
        }
    }
}