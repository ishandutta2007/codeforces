// https://docs.microsoft.com/en-us/qsharp/api/prelude/microsoft.quantum.primitive?view=qsharp-preview
// https://github.com/Microsoft/QuantumKatas/blob/master/quickref/qsharp-quick-reference.pdf
// https://codeforces.com/contest/1115/standings
 
namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
 
    operation Set (desired: Result, q1: Qubit) : Unit {
        body {
            let current = M(q1);
            if (desired != current) { X(q1); }
        }
    }
 
    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()) {
            mutable done = false;
            repeat {
                Set(Zero,qs[0]);
                Set(Zero,qs[1]);
                H(qs[0]); H(qs[1]);
                Controlled X(qs,q);
                if (M(q) == Zero) {
                    set done = true;
                }
                Set(Zero,q);
                X(qs[0]);
                X(qs[1]);
            } until (done) fixup {}
        }
        // your code here
    }
    
    // ------------- Operation which is called from C# -------------------
    operation RunQsharp () : Bool {
        body {
            for (j in 0..4) {
                using (Q = Qubit[4]) {
                
                }
            }
            return false;
        }
    }
}