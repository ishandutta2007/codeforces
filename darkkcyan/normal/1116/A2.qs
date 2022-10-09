namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Convert;

    operation PrepairQubit(x: Qubit[], y: Bool[]): Unit {
        body (...) {
            for (i in 0..Length(x) - 1) {
                if (y[i]) {
                    X(x[i]);
                }
            }
        }
        controlled auto;
    }

    operation HelloQ () : Unit {
        let states = [
            [false, true],
            [true, false],
            [false, false],
            [true, true]
        ];
        using (qu = Qubit[Length(states[0])]) {
            Solve(qu, states);
            DumpMachine("dump.txt");
            ResetAll(qu);
        }
    }

    function predicate(bits: Bool[], curbit: Int, val: Bool): Bool {
        return bits[curbit] == val;
    }

    function findAngle(n: Int, n1: Int): Double {
        let num = Sqrt(ToDouble(n - n1) / ToDouble(n)) ;
        return ArcCos(num);
    }

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        body (...) {
            let n = Length(bits);
            // Message($"{n}");
            let m = Length(bits[0]);
            if (n == 1) {
                PrepairQubit(qs, bits[0]);
                return ();
            }
            for (i in 0..m - 1) {
                mutable cnt = 0;
                for (f in 0..n - 1) {
                    set cnt = cnt + (bits[f][i] ? 1 | 0);
                }
                if (cnt != 0 && cnt != n) {
                    let angle = findAngle(n, cnt);
                    // Message($"{n} {m} {i} {cnt} {angle}");
                    Ry(angle * 2.0, qs[i]);

                    let truePre = predicate(_, i, true);
                    let falsePre = predicate(_, i, false);
                    let newQs = Exclude([i], qs);
                    let excluder = Exclude<Bool>([i], _);

                    X(qs[i]);
                    Controlled Solve([qs[i]], (newQs, Map(excluder, Filter(falsePre, bits))));
                    X(qs[i]);
                    Controlled Solve([qs[i]], (newQs, Map(excluder, Filter(truePre, bits))));
                    return ();
                }
            }
        }
        controlled auto;
    }
}