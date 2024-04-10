namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Convert;

    operation Solve (qs : Qubit[]) : Unit {
using (x = Qubit[2]) {
X(x[0]);
        let theta = ArcCos(Sqrt((2.0)) / Sqrt((3.0)));
        Ry(2.0 * theta, qs[0]);
        X(qs[0]);
        Controlled H([qs[0]], qs[1]);
        X(qs[0]);
X(x[0]);
}
    }
}