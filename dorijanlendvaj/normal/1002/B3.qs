namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            ApplyToEach(H,qs);
			return MeasureIntegerBE(BigEndian(qs));
        }
    }
}