namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
			CNOT(qs[0],qs[1]);
			H(qs[0]);
			return 3-MeasureIntegerBE(BigEndian(qs));
        }
    }
}