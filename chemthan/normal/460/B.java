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
	
	static int sumofdigit(int n) {
		int res = 0;
		while (n > 0) {
			res += n % 10;
			n /= 10;
		}
		return res;
	}
	
	static void solve() {
		int a = Input.nextInt();
		int b = Input.nextInt();
		int c = Input.nextInt();
		ArrayList<Integer> ans = new ArrayList<>();
		for (int i = 0; i <= 81; i++) {
			int x = (int) (((long) b * fpow(i, a, MOD) + c + MOD) % MOD);
			long t = 1, k = (long) sumofdigit(x);
			for (int j = 0; j < a; j++) {
				t *= k;
			}
			if (x == b * t + c && x > 0) {
				ans.add(x);
			}
		}
		out.println(ans.size());
		for (int e : ans) {
			out.print(e + " ");
		}
	}
	
	public static void main(String[] args) {
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	static class Matrix {
		int maxn = 2;
		int[][] x = new int[maxn][maxn];
		Matrix mul(Matrix A) {
			Matrix res = new Matrix();
			for (int i = 0; i < maxn; i++) {
				for (int k = 0; k < maxn; k++) {
					for (int j = 0; j < maxn; j++) {
						res.x[i][j] = (int) ((res.x[i][j] + (long) x[i][k] * A.x[k][j]) % MOD);
					}
				}
			}
			return res;
		}
		Matrix pow(long k) {
			Matrix res = this, T = this; k--;
			while (k > 0) {
				if ((k & 1) > 0) {
					res = res.mul(T);
				}
				T = T.mul(T); k >>= 1;
			}
			return res;
		}
	}
	
	static class Pair implements Comparable<Pair> {
		int fi, se;
		Pair(int fi, int se) {
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