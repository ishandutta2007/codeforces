namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (n : Int, fun : ((Qubit[], Qubit) => ())) : Int[] {
        body
        {
			mutable ret = new Int[n];
			for(i in 0..n-1){
				set ret[i] = 0;
			}
			if(( n &&& 1) == 1){
				set ret[0] = 1 - ret[0];
			}
            using (qs = Qubit[n+1]){
				fun(qs[0..n-1], qs[n]);
				if(M(qs[n]) == One){
					set ret[0] = 1 - ret[0];
				}
				ResetAll(qs);
			}
			return ret;
        }
    }
}