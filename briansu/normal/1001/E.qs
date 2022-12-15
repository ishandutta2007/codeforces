namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs: Qubit[]) : Int{
        CNOT(qs[0], qs[1]);
        H(qs[0]);
        let a = M (qs[0]);
        let b = M (qs[1]);
        if(a == One && b == One){
            return 3;
        }elif(a == One && b == Zero){
            return 1;
        }elif(a== Zero && b == Zero){
            return 0;
        }else{
            return 2;
        }
    }
}