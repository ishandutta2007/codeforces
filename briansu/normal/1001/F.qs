namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int{
        mutable fg = 0;
        for(i in 0..Length(qs)-1)
        {
            if((M (qs[i]) == One) != bits0[i])
            {
                set fg = 1;
            }
        }
        return fg;
    }
}