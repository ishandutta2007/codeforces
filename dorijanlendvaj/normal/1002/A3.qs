namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let n=Length(qs);
			mutable ind=-1;
			for (i in 0..n-1)
			{
				if (bits0[i]!=bits1[i])
				{
					if (ind==-1)
					{
						set ind=i;
					}
				}
				else
				{
					if (bits0[i]==true)
					{
						X(qs[i]);
					}
				}
			}
			H(qs[ind]);
			for (i in 0..n-1)
			{
				if (bits0[i]!=bits1[i])
				{
					if (ind!=i)
					{
						CNOT(qs[ind],qs[i]);
						if (bits0[ind]!=bits0[i])
						{
							X(qs[i]);
						}
					}
				}
			}
        }
    }
}