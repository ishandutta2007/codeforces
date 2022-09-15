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
	
	static int maxn = 100010;
	static int[] isprime = new int[maxn];
	static ArrayList<Integer> prime = new ArrayList<>();
	static int[] used = new int[maxn];
	
	static void solve() {
		int n = Input.nextInt();
		Arrays.fill(isprime, 1);
		for (int i = 2; i < maxn; i++) {
			if (isprime[i] == 1) {
				prime.add(i);
				for (long j = (long) i * i; j < maxn; j += i) {
					isprime[(int) j] = 0;
				}
			}
		}
		ArrayList<Pair> ans = new ArrayList<>();
		for (int i = 1; i < prime.size() && prime.get(i) <= n / 2; i++) {
			ArrayList<Integer> t = new ArrayList<>();
			for (int j = 1; (long) j * prime.get(i) <= n; j++) {
				int k = j * prime.get(i);
				if (used[k] == 0 && j != 2) {
					t.add(k);
				}
			}
			if (t.size() % 2 == 1 && used[2 * prime.get(i)] == 0) {
				t.add(2 * prime.get(i));
			}
			for (int j = 0; j < t.size() / 2; j++) {
				ans.add(new Pair(t.get(2 * j), t.get(2 * j + 1)));
				used[t.get(2 * j)] = used[t.get(2 * j + 1)] = 1;
			}
		}
		ArrayList<Integer> t = new ArrayList<>();
		for (int i = 2; i <= n; i += 2) {
			if (used[i] == 0) {
				t.add(i);
			}
		}
		for (int j = 0; j < t.size() / 2; j++) {
			ans.add(new Pair(t.get(2 * j), t.get(2 * j + 1)));
		}
		out.println(ans.size());
		for (Pair e : ans) {
			out.println(e.fi + " " + e.se);
		}
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