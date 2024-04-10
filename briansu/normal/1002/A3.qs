namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Unit
    {
        mutable stat = -1;
        for(i in 0..Length(qs)-1){
            if(bits0[i] == bits1[i]){
                if(bits0[i] == true){
                    X (qs[i]);
                }
            }else{
                if(stat != -1){
                    if(bits0[stat] != bits0[i]){
                        X (qs[i]);
                    }
                    CNOT (qs[stat], qs[i]);
                }else{
                    H (qs[i]);
                    set stat = i;
                }
            }
        }
    }
}