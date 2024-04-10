namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arrays;

    operation Solve(inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using ((c1, c2) = (Qubit(), Qubit())) {
            within {
                X(c1);
                X(c2);
                for (i in 0 .. Length(inputs)-1) {
                    if (i % 2 == 0) {
                        CCNOT(inputs[i], c1, c2);
                        CCNOT(inputs[i], c2, c1);
                    } else {
                        CCNOT(inputs[i], c2, c1);
                        CCNOT(inputs[i], c1, c2);
                    }
                }
            } apply {
                CCNOT(c1, c2, output);
            }
        }
    }
}