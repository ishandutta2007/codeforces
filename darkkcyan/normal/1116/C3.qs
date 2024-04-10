namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation PrepairQubit(x: Qubit[], y: Bool[]): Unit {
        ResetAll(x);
        for (i in 0..Length(x) - 1) {
            ApplyIf(X, y[i], x[i]);
        }
    }

    operation HelloQ () : Unit {
        let state = [true, false, true];
        using ((num, ans) = (Qubit[Length(state)], Qubit())) {
            PrepairQubit(num, state);
            DumpMachine("predump.txt");
            Solve(num, ans);
            DumpMachine("postdump.txt");
            Reset(ans);
            ResetAll(num);
        }
    }

    operation inc(num: Qubit[]): Unit {
        body (...) {
            for (i in Length(num) - 1 .. -1 .. 1) {
                SWAP(num[i], num[i - 1]);
            }
            SWAP(num[0], num[Length(num) - 1]);
        }
        adjoint invert;
        controlled auto;
        adjoint controlled invert;
    }

    operation countBit(x: Qubit[], num: Qubit[]): Unit {
        body(...) {
            for (i in x) {
                Controlled inc([i], num);
            }
        }
        adjoint invert;
    }

    operation preprocess(x: Qubit[], num: Qubit[]): Unit {
        body(...) {
            let n = Length(x);
            X(num[0]);
            countBit(x[0..n - 1], num);
            MultiX(num[1..Length(num) - 1]);
        }
        adjoint invert;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let postprocess = Adjoint preprocess;
            using (num = Qubit[4]) {
                preprocess(x, num);
                Controlled X(num, y);
                postprocess(x, num);
            }
        }
        adjoint auto;
    }
}