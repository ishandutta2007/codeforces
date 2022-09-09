namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Arrays;

    operation Inc(qs : Qubit[]) : Unit is Adj+Ctl {
        if (Length(qs) > 1) {
            Controlled Inc([Head(qs)], Rest(qs));
        }
        X(Head(qs));
    }

    function GetL(n : Int) : Int {
        mutable l = 1;
        while (1 <<< l <= n / 2) {
            set l += 1;
        }
        return l;
    }

    operation Solve(inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        let n = Length(inputs);
        let l = GetL(n);
        using (c = Qubit[l]) {
            within {
                for (i in 0 .. n-1) {
                    Controlled Inc([inputs[i]], c);
                }
            } apply {
                (ControlledOnInt(n / 2, X))(c, output);
            }
        }
    }
}