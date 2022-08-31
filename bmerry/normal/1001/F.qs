namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for (i in 0..(Length(qs) - 1))
            {
                if (bits0[i] != bits1[i])
                {
                    let one = (M(qs[i]) == One);
                    if (one == bits1[i])
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            return 0;
        }
    }
}