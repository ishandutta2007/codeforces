
 namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(1.910633236249018556327714205031515508486829390020010981919,qs[0]);
        (Controlled H)([qs[0]],qs[1]);
        X(qs[0]);
    }
}