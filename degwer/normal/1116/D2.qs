namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        mutable N=Length(qs);
        for(i in 1..N-1)
        {
            for(j in 0..i-1)
            {
                (Controlled Ry)([qs[i]],(0.2,qs[j]));
                (Controlled Rz)([qs[i]],(0.1,qs[j]));
                (Controlled Rx)([qs[i]],(0.4,qs[j]));
                (Controlled Ry)([qs[i]],(0.3,qs[j]));
                (Controlled Rz)([qs[i]],(0.5,qs[j]));
            }
        }
    }
}