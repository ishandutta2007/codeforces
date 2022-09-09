namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    operation Solve(theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable n = 0;
        repeat {
            set n += 1;
        } until (theta * IntAsDouble(n) > PI());
        if (theta * (IntAsDouble(n) - 0.5) > PI()) {
            set n -= 1;
        }
        mutable res = 2;
        using (q = Qubit()) {
            repeat {
                for (j in 0 .. n-1) {
                    unitary(q);
                }
                if (M(q) == One) {
                    set res = 1;
                }
                Reset(q);
                within {
                    H(q);
                    S(q);
                } apply {
                    for (j in 0 .. n-1) {
                        unitary(q);
                    }
                }
                if (M(q) == One) {
                    set res = 0;
                }
                Reset(q);
            } until (res != 2);
        }
        return res;
    }
}