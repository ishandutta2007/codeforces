namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation HelloQ () : Unit {
        using ((qu, ans) = (Qubit[5], Qubit())) {
            PrepairQubit(qu, [true, false, false, true, false]);
            DumpMachine("predump.txt");
            Solve(qu, ans);
            DumpMachine("dump.txt");
            Message($"{qu} {ans}");
            ResetAll(qu);
            Reset(ans);
        }
    }

    operation PrepairQubit(x: Qubit[], y: Bool[]): Unit {
        ResetAll(x);
        for (i in 0..Length(x) - 1) {
            ApplyIf(X, y[i], x[i]);
        }
    }

    operation And(x: Qubit[], y: Qubit): Unit {
        body (...) {
            Controlled X(x, y);
        }
        adjoint auto;
    }

    operation Or(x: Qubit[], y: Qubit): Unit {
        body (...) {
            MultiX(x);
            And(x, y);
            X(y);
            MultiX(x);
        }
        adjoint auto;
    }

    operation CheckHelper(x: Qubit[], p: Int) : Unit {
        body (...) {
            for (i in 0..1..Length(x) - 1 - p) {
                CNOT(x[i + p], x[i]);
                X(x[i]);
            }
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            using (temp = Qubit[n - 1]) {
                for (i in 1..n - 1) {
                    CheckHelper(x, i);
                    And(x[0..n - i - 1], temp[i - 1]);
                    Adjoint CheckHelper(x, i);
                }
                // DumpMachine("dumpmiddle.txt");
                // Message($"{temp}");
                Or(temp, y);
                for (i in 1..n - 1) {
                    CheckHelper(x, i);
                    Adjoint And(x[0..n - i - 1], temp[i - 1]);
                    Adjoint CheckHelper(x, i);
                }
            }
        }
        adjoint auto;
    }
}