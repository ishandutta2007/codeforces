namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable num=0;
			let n=Length(qs);
			for (i in 0..n-1)
			{
				if (M(qs[i])==One)
				{
					set num=num+1;
				}
			}
			if (num==1)
			{
				return 1;
			}
			return 0;
        }
    }
}