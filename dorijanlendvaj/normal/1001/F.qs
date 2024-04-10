namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            mutable WasItOne=0;
			for (i in 0..Length(qs)-1)
			{
			    if ((M(qs[i])==Zero && bits0[i]==true) || (M(qs[i])==One && bits0[i]==false))
				{
					set WasItOne=1;
				}
			}
			return WasItOne;
        }
    }
}