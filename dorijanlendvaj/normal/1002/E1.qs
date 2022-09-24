namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            // We first create an array of size n which will hold the final result.
            mutable resultArray = new Int[N];

            // Now, we allocate n + 1 clean qubits. Note that the function Uf is defined
            // on inputs of the form (x, y), where x has n bits and y has 1 bit.
            using(qubits = Qubit[N + 1]) {
                // The last qubit needs to be flipped so that the function will 
                // actually be computed into the phase when Uf is applied.
                X(qubits[N]);

                // Now, a Hadamard transform is applied to each of the qubits.
                ApplyToEach(H, qubits);

                // We now apply Uf to the n+1 qubits, computing |x, y  |x, y  f(x).
                Uf(qubits[0..N-1],qubits[N]);

                // As the last step before the measurement, a Hadamard transform is 
                // applied to all qubits except last one. We could apply the transform to
                // the last qubit also, but this would not affect the final outcome. 
                ApplyToEach(H, qubits[0..(N - 1)]); 

                // The following for-loop measures all qubits and resets them to 
                // zero so that they can be safely returned at the end of the 
                // using-block.
                for (idx in 0..(N-1)) {
					let res = MResetZ(qubits[idx]);
                    if (res==One)
					{
						set resultArray[idx]=1;
					}
					else
					{
						set resultArray[idx]=0;
					}
                }

                // Finally, the last qubit, which held the y-register, is reset. 
                Reset(qubits[N]);							
            }
			return resultArray;
        }
    }
}