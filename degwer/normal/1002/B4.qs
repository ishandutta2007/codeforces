namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[1]);
            CNOT(qs[1],qs[0]);
            H(qs[1]);
            X(qs[0]);
            X(qs[1]);
            mutable t=0;
            if(M(qs[0])==One){set t=t+2;}
            if(M(qs[1])==One){set t=t+1;}
            return t;
        }
    }
}