namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation HelloQ () : Unit {
        using (qs = Qubit[2]) {
            Solve(qs);
            DumpMachine("dump.txt");
            ResetAll(qs);
        }
    }

     operation Solve (qs : Qubit[]) : Unit {
        let alpha = ArcCos(Sqrt(2.0) / Sqrt(3.));
        let beta = ArcCos(1.0 / Sqrt(2.));
        let angle = 2.0 * (alpha - beta);
        H(qs[0]);
        Ry(angle, qs[0]);
        X(qs[0]);
        Controlled H([qs[0]], qs[1]);
        X(qs[0]);
    }
}