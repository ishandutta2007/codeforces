namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    function CalcPow2 (n : Int) : Int
    {
        mutable ret = 1;
        for (i in 1..n) {
            set ret = 2 * ret;
        }
        return ret;
    }

    function CalcLog2(n : Int) : Int
    {
        if (n == 1) {
            return 0;
        }
        elif (n == 2) {
            return 1;
        }
        elif (n == 4) {
            return 2;
        }
        elif (n == 8) {
            return 3;
        }
        return 4;
    }
    
    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            mutable N = Length(qs);
            mutable n = CalcLog2(N);
            X(qs[0]);
            for (i in 1..n) {
                mutable at = CalcPow2(i - 1);
                mutable row = CalcPow2(i);
                mutable sz = CalcPow2(i - 1);
                H(qs[sz]);
                for (j in 1..sz) {
                    set at = at - 1;
                    set row = row - 1;
                    if (row > sz) {
                        CCNOT(qs[sz], qs[at], qs[row]);
                    }
                    CNOT(qs[row], qs[at]);
                    if (row > sz) {
                        CNOT(qs[row], qs[sz]);
                    }
                }
            }
        }
    }
}