namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	
    operation Solve (qs : Qubit[], bs : Bool[][]) : Unit {
        mutable ids = [0, 0, 0];
		mutable bits = bs;
		let n = Length(qs);
		if (n == 2) {
		  H(qs[0]);
		  H(qs[1]);
		}
		else {
			for (i in 0..n-1) {
			  for (j in i+1..n-1) {
				for (k in j+1..n-1) {
				  mutable fl = 0;
				  for (a in 0..3) {
					for (b in a+1..3) {
					  if (bits[a][i] == bits[b][i] && bits[a][j] == bits[b][j] && bits[a][k] == bits[b][k]) {
						set fl = 1;
					  }
					}
				  }
				  if (fl == 0) {
					set ids[0] = i;
					set ids[1] = j;
					set ids[2] = k;
				  }
				}
			  }
			}
			
			if (XOR(bits[0][ids[1]], XOR(bits[1][ids[1]], XOR(bits[2][ids[1]], bits[3][ids[1]])))) {
			  mutable tmp = ids[0];
			  set ids[0] = ids[1];
			  set ids[1] = tmp;
			}
			if (XOR(bits[0][ids[2]], XOR(bits[1][ids[2]], XOR(bits[2][ids[2]], bits[3][ids[2]])))) {
			  mutable tmp = ids[0];
			  set ids[0] = ids[2];
			  set ids[2] = tmp;
			}
			if (bits[0][ids[1]] == bits[1][ids[1]] && bits[1][ids[1]] == bits[2][ids[1]] && bits[2][ids[1]] == bits[3][ids[1]]) {
			  mutable tmp = ids[0];
			  set ids[0] = ids[1];
			  set ids[1] = tmp;
			}
			if (bits[0][ids[2]] == bits[1][ids[2]] && bits[1][ids[2]] == bits[2][ids[2]] && bits[2][ids[2]] == bits[3][ids[2]]) {
			  mutable tmp = ids[0];
			  set ids[0] = ids[2];
			  set ids[2] = tmp;
			}
			
			mutable st = [0, 0, 0];
			if (XOR(bits[0][ids[0]], XOR(bits[1][ids[0]], XOR(bits[2][ids[0]], bits[3][ids[0]])))) {
			  if (XOR(bits[0][ids[1]], XOR(bits[1][ids[1]], XOR(bits[2][ids[1]], bits[3][ids[1]])))) {
			    set st[1] = 1;
				for (i in 0..3) {
				  if (bits[i][ids[0]]) {
				    set bits[i][ids[1]] = (bits[i][ids[1]] != true);
				  }
				}
			  }
 			  if (XOR(bits[0][ids[2]], XOR(bits[1][ids[2]], XOR(bits[2][ids[2]], bits[3][ids[2]])))) {
			    set st[2] = 1;
				for (i in 0..3) {
				  if (bits[i][ids[0]]) {
				    set bits[i][ids[2]] = (bits[i][ids[2]] != true);
				  }
				}
			  }
			}
			
			H(qs[ids[1]]);
			H(qs[ids[2]]);
			for (i in 0..3) {
			  if (bits[i][ids[0]]) {
			    if (bits[i][ids[1]] == false) { X(qs[ids[1]]); }
				if (bits[i][ids[2]] == false) { X(qs[ids[2]]); }
				Controlled X([qs[ids[1]], qs[ids[2]]], qs[ids[0]]);
			    if (bits[i][ids[1]] == false) { X(qs[ids[1]]); }
				if (bits[i][ids[2]] == false) { X(qs[ids[2]]); }
			  }
			}
			
			if (st[1] == 1) { CNOT(qs[ids[0]], qs[ids[1]]); }
			if (st[2] == 1) { CNOT(qs[ids[0]], qs[ids[2]]); }
			
			if (XOR(bits[0][ids[0]], XOR(bits[1][ids[0]], XOR(bits[2][ids[0]], bits[3][ids[0]])))) {
			  if (st[1] == 1) {
				for (i in 0..3) {
				  if (bits[i][ids[0]]) {
				    set bits[i][ids[1]] = (bits[i][ids[1]] != true);
				  }
				}
			  }
 			  if (st[2] == 1) {
				for (i in 0..3) {
				  if (bits[i][ids[0]]) {
				    set bits[i][ids[2]] = (bits[i][ids[2]] != true);
				  }
				}
			  }
			}
			
			for (row in 0..3) {
			  for (col in 0..n-1) {
			    if (col != ids[0] && col != ids[1] && col != ids[2] && bits[row][col]) {
					for (i in 0..2) {
					  if (bits[row][ids[i]] == false) {
						X(qs[ids[i]]);
					  }
					}
					Controlled X([qs[ids[0]], qs[ids[1]], qs[ids[2]]], qs[col]);
					for (i in 0..2) {
					  if (bits[row][ids[i]] == false) {
						X(qs[ids[i]]);
					  }
					}
				}
			  }
			}
		}
    }
}