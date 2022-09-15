import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	static double EPS = 1e-9;
	static int INF = (int) 1e9;
	static long LINF = (long) 1e18;
	static int MOD = (int) 1e9 + 7;
	static double PI = 2 * Math.acos(0);
	
	static void solve() {
		int n = Input.nextInt();
		int[] a = new int[n];
		int[][] f = new int[21][1 << 20];
		for (int i = 0; i < n; i++) {
			f[0][a[i] = Input.nextInt()]++;
		}
		for (int i = 1; i < 21; i++) {
			for (int msk = 0; msk < (1 << 20); msk++) {
				if ((msk & (1 << (i - 1))) > 0) {
					f[i][msk] += f[i - 1][msk];
					if (f[i][msk] >= MOD) f[i][msk] -= MOD;
				}
				else {
					f[i][msk] += f[i - 1][msk];
					if (f[i][msk] >= MOD) f[i][msk] -= MOD;
					f[i][msk] += f[i - 1][msk | (1 << (i - 1))];
					if (f[i][msk] >= MOD) f[i][msk] -= MOD;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < (1 << 20); i++) {
			if ((Integer.bitCount(i) & 1) == 0) {
				ans += fpow(2, f[20][i], MOD);
				if (ans >= MOD) ans -= MOD;
			}
			else {
				ans -= fpow(2, f[20][i], MOD);
				if (ans < 0) ans += MOD;
			}
		}
		out.print((fpow(2, n, MOD) + ans) % MOD);
	}
	
	public static void main(String[] args) {
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	static class Pair implements Comparable<Pair> {
		int fi, se;
		public Pair(int fi, int se) {
			this.fi = fi;
			this.se = se;
		}
		public int compareTo(Pair oth) {
			if (fi > oth.fi) return +1;
			if (fi < oth.fi) return -1;
			if (se > oth.se) return +1;
			if (se < oth.se) return -1;
			return 0;
		}
	}
	
	static long gcd(long a, long b) {
		long r;
		while (b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
	
	static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}
	
	static long fpow(long n, long k, int p) {
		long r = 1;
		for (; k > 0; k >>= 1) {
			if (k % 2 == 1) {
				r = r * n % p;
			}
			n = n * n % p;
		}
		return r;
	}
	
	static class Input {
		static StringTokenizer token = null;
		static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		static BufferedReader in;
//		static {
//			try {
//				in = new BufferedReader(new FileReader("in.txt"));
//			} catch (IOException e) {
//			}
//		}

		static int nextInt() {
			return Integer.parseInt(nextString());
		}

		static long nextLong() {
			return Long.parseLong(nextString());
		}

		static double nextDouble() {
			return Double.parseDouble(nextString());
		}

		static String nextString() {
			try {
				while (token == null || !token.hasMoreTokens()) {
					token = new StringTokenizer(in.readLine());
				}
			} catch (IOException e) {
			}
			return token.nextToken();
		}
	}
}