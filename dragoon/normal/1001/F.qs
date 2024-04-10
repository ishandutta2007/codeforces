namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            mutable n = 0;
            set n = Length(qs);
            for (i in 0..n-1) {
              if (bits0[i] != bits1[i]) {
                let res = M(qs[i]);
                if (res == Zero && bits0[i] == false) {
                  return 0;
                }
                elif (res == One && bits0[i] == true) {
                  return 0;
                }
                return 1;
              }
            }
            return -1;
        }
    }
}