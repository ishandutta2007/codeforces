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
            [true, false, false],
            [false, true, false],
            [false, false, true]
        ];
        using (qu = Qubit[Length(states[0])]) {
            Helper(qu, states);
            let omegaPhase = 2.0 * PI() / 3.0;
            R1(omegaPhase, qu[2]);
            R1(omegaPhase * 2.0, qu[1]);
            DumpMachine("dump.txt");
            Message($"{Solve(qu)}");
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

    operation Helper(qs : Qubit[], bits : Bool[][]) : Unit {
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
                    Controlled Helper([qs[i]], (newQs, Map(excluder, Filter(falsePre, bits))));
                    X(qs[i]);
                    Controlled Helper([qs[i]], (newQs, Map(excluder, Filter(truePre, bits))));
                    return ();
                }
            }
        }
        controlled auto;
    }

    operation makeWState(qs : Qubit[]) : Unit {
        
        body (...) {
            let N = Length(qs);
            if (N == 1) {
                X(qs[0]);
            } else {
                let theta = ArcSin(1.0 / Sqrt(ToDouble(N)));
                Ry(2.0 * theta, qs[0]);
                
                X(qs[0]);
                Controlled makeWState(qs[0 .. 0], qs[1 .. N - 1]);
                X(qs[0]);
            }
        }
        
        adjoint invert;
        controlled distribute;
        controlled adjoint distribute;
    }

   

    operation Solve (qs : Qubit[]) : Int {
        let omegaPhase = 2.0 * PI() / 3.0;
        R1(omegaPhase * 2.0, qs[1]);
        R1(omegaPhase, qs[2]);
        Adjoint makeWState(qs);
        DumpMachine("after.txt");
        return (M(qs[0]) == Zero && M(qs[1]) == Zero && M(qs[2]) == Zero ? 0 | 1);
    }
}