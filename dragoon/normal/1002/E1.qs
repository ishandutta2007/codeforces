namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (n : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            // We first create an array of size n which will hold the final result.
            mutable resultArray = new Int[n];

            // Now, we allocate n + 1 clean qubits. Note that the function Uf is defined
            // on inputs of the form (x, y), where x has n bits and y has 1 bit.
            using(qubits = Qubit[n + 1]) {
                // The last qubit needs to be flipped so that the function will 
                // actually be computed into the phase when Uf is applied.
                X(qubits[n]);

                // Now, a Hadamard transform is applied to each of the qubits.
                ApplyToEach(H, qubits);

                // We now apply Uf to the n+1 qubits, computing |x, y  |x, y  f(x).
                let x = qubits[0..n-1];
				let y = qubits[n];
                Uf(x, y);

                // As the last step before the measurement, a Hadamard transform is 
                // applied to all qubits except last one. We could apply the transform to
                // the last qubit also, but this would not affect the final outcome. 
                ApplyToEach(H, qubits[0..(n - 1)]); 

                // The following for-loop measures all qubits and resets them to 
                // zero so that they can be safely returned at the end of the 
                // using-block.
                for (idx in 0..(n-1)) {
                    let t = MResetZ(qubits[idx]);
                    set resultArray[idx] = 1;
                    if (t == Zero) {
                        set resultArray[idx] = 0;
                    }
                }

                // Finally, the last qubit, which held the y-register, is reset. 
                Reset(qubits[n]);							
            }	

            // The result is already contained in resultArray so no further
            // post-processing is necessary.
            return resultArray;
        }
    }
}