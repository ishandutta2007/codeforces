namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(3.14159265358979/4.0,q);
			let a=M(q);
			if (a==One)
			{
				return 1;
			}
			else
			{
				return 0;
			}
        }
    }
}