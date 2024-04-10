namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            for (i in 0..Length(qs)-1)
			{
				for (j in 0..5*Length(qs))
				{
					if (M(qs[i])==One)
					{
						return 1;
					}
				}
			}
			return 0;
        }
    }
}