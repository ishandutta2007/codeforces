namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int {
        R1(-2.09439510239,qs[1]);
        R1(2.09439510239,qs[2]);
        CNOT(qs[0],qs[1]);
        (Controlled H)([qs[1]],qs[0]);
        CNOT(qs[1],qs[2]);
        Ry(-1.910633236249018556327714205031515508486829390020010981919,qs[1]);
        if(M(qs[0])==One){return 1;}
        if(M(qs[1])==One){return 1;}
        if(M(qs[2])==Zero){return 1;}
        return 0;
    }
}