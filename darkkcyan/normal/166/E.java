import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
    static final long mod = (long)(1e9 + 7);
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        long[][] coef = new long[4][4];
        for (int i = 4; i-- > 0; ) 
        for (int f = 4; f-- > 0; ) {
            if (i != f) coef[i][f] = 1;
        }
        
        long[][] final_coef = pow(coef, n);
        long[][] res = mul(final_coef, new long[][] {{0}, {0}, {0}, {1}});
        System.out.println(res[3][0]);
    }
    
    static long[][] mul(long[][] a, long[][] b) {
        assert(a[0].length == b.length);
        long[][] c = new long[a.length][b[0].length];
        for (int i = a.length; i-- > 0; ) {
            for (int f = b[0].length; f-- > 0; ) {
                for (int g = b.length; g-- > 0; ) {
                    c[i][f] += a[i][g] * b[g][f] % mod;
                    c[i][f] %= mod;
                }
            }
        }
        return c;
    }
    
    static long[][] iden(int n) {
        long[][] res = new long[n][n];
        for (int i = n; i-- > 0; ) res[i][i] = 1;
        return res;
    }
    
    static long[][] pow(long[][] base, long exp) {
        assert(base[0].length == base.length);
        long[][] res = iden(base.length);
        for (; exp > 0; exp >>= 1) {
            if ((exp & 1) == 1) res = mul(res, base);
            base = mul(base, base);
        }
        return res;
    }
}