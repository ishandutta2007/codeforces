namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	
	operation DetermineOne(q : Qubit): Int
	{
		body
		{
			if (M(q)==One)
			{
				return 1;
			}
			return -1;
		}
	}
	
	operation DetermineZero(q : Qubit): Int
	{
		body
		{
			Ry(1.5707963267948966192313216916398,q);
			if (M(q)==Zero)
			{
				return 0;
			}
			return -1;
		}
	}
	
    operation Solve (q : Qubit) : Int
    {
        body
        {
            if (RandomInt(2)==0)
			{
				return DetermineOne(q);
			}
			else
			{
				return DetermineZero(q);
			}
        }
    }
}