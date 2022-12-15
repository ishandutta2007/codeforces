namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs: Qubit[], idx: Int) : Unit {
        if(idx == 0){
            H (qs[0]);
            CNOT(qs[0], qs[1]);
        }elif(idx == 1){
            X (qs[0]);
            H (qs[0]);
            CNOT(qs[0], qs[1]);
        }elif(idx == 2){
            H (qs[0]);
            X (qs[1]);
            CNOT(qs[0], qs[1]);
        }elif(idx == 3){
            X (qs[0]);
            H (qs[0]);
            X (qs[1]);
            CNOT(qs[0], qs[1]);
        }
    }
}