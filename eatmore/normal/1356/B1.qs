namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arithmetic;
    operation Solve(register : LittleEndian) : Unit is Adj+Ctl {
        let r = register!;
        if (Length(r) != 0) {
            Controlled Solve([r[0]], LittleEndian(r[1...]));
            X(r[0]);
        }
    }
}