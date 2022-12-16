import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;

public class C {
	public static final long MOD = 1000000007;
	public static int dp[] = new int[1005];
	public static ArrayList<Integer> okay;
	public static BigInteger one = BigInteger.ONE;
	public static BigInteger two = BigInteger.ONE;

	public static int popcount(int ii) {
		int cpy = ii;
		int cnt = 0;
		while(cpy != 0) {
			if(cpy%2 == 1) ++cnt;
			cpy /= 2;
		}
		return cnt;
	}

	public static int popcount(BigInteger ii) {
		BigInteger cpy = ii;
		int cnt = 0;
		while(!cpy.equals(BigInteger.ZERO)) {
			if(!cpy.mod(two).equals(BigInteger.ZERO)) ++ cnt;
			cpy = cpy.divide(two);
		}
		return cnt;
	}

	public static void fillDp() {
		dp[0] = -10;
		dp[1] = 0;
		for(int i=2;i<1002;++i) {
			dp[i] = 1 + dp[popcount(i)];
		}
	}

	public static long inv(long in) {
		long pow = MOD-2;
		long ans = 1;
		long curr = in;

		while(pow != 0) {
			if(pow%2 == 1) {
				ans = (ans*curr)%MOD;
			}
			pow/=2;
			curr = (curr*curr)%MOD;
		}
		return ans;
	}

	public static long modder(int n, int extra, int threshold) {
		int k = 0;
		long ans = 0;
		long denom = 1;
		long num = 1;
		for(int bot=n;bot>k;--bot) {
			if(dp[bot + extra] == threshold) {
				//System.err.println("  " + n + "C" + bot + " GOOD FOR " + ((num*denom)%MOD));
				ans = (ans+(num*denom)%MOD)%MOD;
				if(extra == 0 && threshold == 0) {
					ans = (ans+MOD-1)%MOD;
				}
			}
			num = (num*bot)%MOD;
			denom = (denom*inv(n-bot+1))%MOD;
		}
		return ans;
	}

/*
	public static int smallestOne(BigInteger ii) {
		BigInteger cpy = ii;
		int pos = 0;
		for(pos=0;cpy%2 != 0;++pos, cpy /=2) {}
		return pos;
	}
	*/

	public static void main(String args[]) {
		two = two.add(one);
		fillDp();

		Scanner s = new Scanner(System.in);
		String ss = s.next();
		int k = s.nextInt();
		BigInteger N = BigInteger.ZERO;
		for(int i=ss.length()-1;i>=0;--i) {
			if(ss.charAt(i) == '1') {
				N = N.flipBit(ss.length()-1-i);
			}
		}

		if(k == 0) {
			System.out.println(1);
			return ;
		}
		if(k == 1 && ss.equals("1")) {
			System.out.println(0);
			return ;
		}

		BigInteger Ncpy = N;

		int pc = popcount(Ncpy);
		long ans = 0;
		while(pc > 0 && !Ncpy.equals(BigInteger.ZERO)) {
			int lsb = Ncpy.getLowestSetBit();
			if(dp[pc] == k-1 && !(k == 1 && lsb == 0 && pc == 1)) ans = (ans+1)%MOD;
			//System.err.println("1. " + ans + " : " + pc + ", " + dp[pc]);
			if(lsb != 0)
				ans = (ans + modder(lsb, pc-1, k-1))%MOD;
			--pc;
			Ncpy = Ncpy.flipBit(lsb);
			//System.err.println("2. " + ans);
			//System.err.println("   N = " + Ncpy);
		}

		System.out.println(ans);
		
	}

}