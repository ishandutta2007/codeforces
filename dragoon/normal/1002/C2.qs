namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            let r = RandomReal(2);
            if (r <= 0.5) {
                let res = M(q);
                if (res == One) {
                    return 1;
                }
                return -1;
            }
            else {
                H(q);
                let res = M(q);
                if (res == One) {
                    return 0;
                }
                return -1;
            }

        }
    }
}