// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
public class Main {
    public static long[] cum = new long[5001];
    public static long[] cum1 = new long[5001];
    public static long[] rcum = new long[5001];
    public static long[] rcum1 = new long[5001];
    public static long[] po = new long[5001];
    public static long[] po1 = new long[5001];
    public static long[] invpo = new long[5001];
    public static long[] invpo1 = new long[5001];
    
    public static int[][] dp = new int[5001][5001];
    public static int[] ans = new int[5001];
    
    public static int MOD = 1000000007, MOD1 = 1000000009;
    public static String s;
    
    public static void gen() {
        po[0] = invpo[0] = po1[0] = invpo1[0] = 1;
        for (int i = 1; i < 5001; ++i) po[i] = (337*po[i-1]) % MOD;
        for (int i = 1; i < 5001; ++i) po1[i] = (337*po1[i-1]) % MOD1;
        for (int i = 1; i < 5001; ++i) invpo[i] = (41543027*invpo[i-1]) % MOD;
        for (int i = 1; i < 5001; ++i) invpo1[i] = (961424341*invpo1[i-1]) % MOD1;
        for (int i = 1; i < s.length(); ++i) {
            cum[i] = (cum[i-1]+po[i-1]*(Character.getNumericValue(s.charAt(i-1))-Character.getNumericValue('a')+1)) % MOD;
            rcum[i] = (rcum[i-1]+po[i-1]*(Character.getNumericValue(s.charAt(s.length()-i))-Character.getNumericValue('a')+1)) % MOD;
            cum1[i] = (cum1[i-1]+po1[i-1]*(Character.getNumericValue(s.charAt(i-1))-Character.getNumericValue('a')+1)) % MOD1;
            rcum1[i] = (rcum1[i-1]+po1[i-1]*(Character.getNumericValue(s.charAt(s.length()-i))-Character.getNumericValue('a')+1)) % MOD1;
        }
    }
    public static long get(int l, int r) {
        long tmp = (cum[r+1]-cum[l])*invpo[l] % MOD;
        tmp = (tmp+MOD) % MOD;
        //System.out.println(l+" "+r);
        //System.out.println(tmp);
        return tmp;
    }
    public static long get1(int l, int r) {
        long tmp = (cum1[r+1]-cum1[l])*invpo1[l] % MOD1;
        tmp = (tmp+MOD1) % MOD1;
        //System.out.println(l+" "+r);
        //System.out.println(tmp);
        return tmp;
    }
    public static long rget(int l, int r) {
        l = s.length()-1-l; r = s.length()-1-r;
        long tmp = (rcum[l+1]-rcum[r])*invpo[r] % MOD;
        tmp = (tmp+MOD) % MOD;
        return tmp;
    }
    public static long rget1(int l, int r) {
        l = s.length()-1-l; r = s.length()-1-r;
        long tmp = (rcum1[l+1]-rcum1[r])*invpo1[r] % MOD1;
        tmp = (tmp+MOD1) % MOD1;
        return tmp;
    }
	public static void main (String[] args) throws java.lang.Exception {
		Scanner in = new Scanner(System.in);
		s = in.next();
		gen();
		
		for (int len = 1; len <= s.length(); ++len)
		    for (int j = 0; j <= s.length()-len; ++j) {
		        long x = get(j,j+len/2-1);
		        long y = rget(j+len-len/2,j+len-1);
		        long x1 = get1(j,j+len/2-1);
		        long y1 = rget1(j+len-len/2,j+len-1);
		        if (x == y && x1 == y1) {
		            dp[j][len] = dp[j][len/2]+1;
		            ans[dp[j][len]]++;
		        }
		    }
		for (int i = 5000; i > 1; --i) ans[i-1] += ans[i];
		for (int i = 1; i <= s.length(); ++i) {
		    System.out.print(ans[i]);
		    System.out.print(" ");
		}
	}
}