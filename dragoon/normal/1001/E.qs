namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
          H(qs[1]);

          X(qs[0]);
          X(qs[1]);
          S(qs[0]);
          SWAP(qs[0], qs[1]);
          S(qs[0]);
          CNOT(qs[1], qs[0]);
          S(qs[0]);
          Z(qs[0]);
          CNOT(qs[1], qs[0]);
          SWAP(qs[0], qs[1]);
          X(qs[1]);
          X(qs[0]);

          H(qs[0]);
          H(qs[1]);
          let x = M(qs[0]);
          let y = M(qs[1]);
          if (x == One && y == One) {
            return 0;
          }
          elif (x == Zero && y == One) {
            return 1;
          }
          elif (x == One && y == Zero) {
            return 2;
          }
          elif (x == Zero && y == Zero) {
            return 3;
          }
          return -1;
        }
    }
}