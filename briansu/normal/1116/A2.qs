namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation eq(a: Bool[], b: Bool[]) : Bool {
        for(i in 0..Length(a)-1){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        let n = Length(qs);
        for(i in 0..n-1){
            for(j in 0..3){
                mutable fg = true;
                for(k in 0..j-1){
                    if(eq(bits[j][0..i-1], bits[k][0..i-1])){
                        set fg = false;
                    }
                }
                if(fg){
                    mutable ct = [0.0, 0.0];
                    for(k in j..3){
                        if(eq(bits[j][0..i-1], bits[k][0..i-1])){
                            if(bits[k][i] == true){
                                set ct[1] = ct[1] + 1.0;
                            }else{
                                set ct[0] = ct[0] + 1.0;
                            }
                        }
                    }
                    for(k in 0..i-1){
                        if(bits[j][k] == false){
                            X (qs[k]);
                        }
                    }
                    if(ct[0] == 0.0){
                        Controlled X(qs[0..i-1], qs[i]);
                    }else{
                        Controlled Ry(qs[0..i-1], (2.0 * ArcTan(Sqrt(ct[1] / ct[0])), qs[i]));
                    }
                    for(k in 0..i-1){
                        if(bits[j][k] == false){
                            X (qs[k]);
                        }
                    }
                }
            }
        }
    }
}