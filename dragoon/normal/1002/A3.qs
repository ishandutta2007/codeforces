namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable split = -1;
            mutable at = -1;
            mutable dir = -1;
            
            for (i in 0 .. Length(bits0)-1) {
                if (split == -1) {
                    if (bits0[i] == bits1[i]) {
                        if (bits0[i] == true) {
                            X(qs[i]);
                        }
                    }
                    else {
                        set split = 1;
                        set at = i;
                        set dir = 1;
                        if (bits0[i] == true) {
                          set dir = 0;
                        }
                        H(qs[i]);
                    }
                }
                else {
                    if (bits0[i] == bits1[i]) {
                        if (bits0[i] == true) {
                            X(qs[i]);
                        }
                    }
                    else {
                        CNOT(qs[at], qs[i]);
                        if ((dir == 1 && bits0[i] == true) || (dir == 0 && bits1[i] == true)) {
                            X(qs[i]);
                        }
                    }
                }
            }
        }
    }
}