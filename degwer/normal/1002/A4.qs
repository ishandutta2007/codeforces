namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            mutable N=Length(qs);
            mutable t=0;
            if(N==1){set t=0;}
            if(N==2){set t=1;}
            if(N==4){set t=2;}
            if(N==8){set t=3;}
            if(N==16){set t=4;}
            mutable now=1;
            X(qs[0]);
            for(i in 0..t-1)
            {
                for(j in 0..now-1)
                {
                    (Controlled H)([qs[j]],qs[j+now]);
                    CNOT(qs[j+now],qs[j]);
                }
                set now=now+now;
            }
        }
    }
}