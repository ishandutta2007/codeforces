import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	static int k, t;
	static long[][] c = new long[30][30];
	
	static ArrayList<Integer> toHex(long m) {
		ArrayList<Integer> res = new ArrayList<>();
		while (m > 0) {
			res.add((int) (m % 16));
			m /= 16;
		}
		Collections.reverse(res);
		return res;
	}
	
	static long calc(long m) {
		long res = 0;
		ArrayList<Integer> digit = toHex(m);
		for (int sum = 0; sum < digit.size() - 1; sum++) {
			for (int i = 1; i < 16; i++) {
				int[] f = new int[16];
				Arrays.fill(f, t);
				f[i]--;
				long[][] dp = new long[17][sum + 1];
				dp[0][sum] = 1;
				for (int u = 0; u < 16; u++) {
					for (int v = sum; v >= 0; v--) {
						for (int k = 0; k <= f[u]; k++) if (v >= k) {
							dp[u + 1][v - k] += dp[u][v] * c[k][v];
						}
					}
				}
				res += dp[16][0];
			}
		}
		int[] cnt = new int[16];
		for (int i = 0; i < digit.size(); i++) {
			for (int j = 0; j < digit.get(i); j++) if (i + j > 0) {
				int[] f = new int[16];
				Arrays.fill(f, t);
				for (int k = 0; k < 16; k++) {
					f[k] -= cnt[k];
				}
				f[j]--;
				int sum = digit.size() - i - 1;
				int tot = 0;
				boolean ok = true;
				for (int k = 0; k < 16; k++) {
					if (f[k] < 0) {
						ok = false;
					}
					tot += f[k];
				}
				if (tot < sum) {
					ok = false;
				}
				if (sum < 0) continue;
				if (!ok) continue;
				long[][] dp = new long[17][sum + 1];
				dp[0][sum] = 1;
				for (int u = 0; u < 16; u++) {
					for (int v = sum; v >= 0; v--) {
						for (int k = 0; k <= f[u]; k++) if (v >= k) {
							dp[u + 1][v - k] += dp[u][v] * c[k][v];
						}
					}
				}
				res += dp[16][0];
			}
			cnt[digit.get(i)]++;
		}
		for (int i = 0; i < 16; i++) {
			if (cnt[i] > t) {
				return res;
			}
		}
		return res + 1;
	}
	
	static void solve() {
		for (int i = 0; i < 30; i++) c[0][i] = 1;
		for (int i = 1; i < 30; i++) {
			for (int j = 1; j < 30; j++) {
				c[i][j] = c[i][j - 1] + c[i - 1][j - 1];
			}
		}
		k = Input.nextInt();
		t = Input.nextInt();
		long l = 1, r = LINF;
		while (l < r) {
			long m = (l + r) >> 1;
			if (calc(m) < k) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		ArrayList<Integer> res = toHex(l);
		for (int e : res) {
			if (e < 10) out.print(e);
			else out.printf("%c", 'a' + e - 10);
		}
		out.println();
	}
	
	public static void main(String[] args) {
		try {
			out = new PrintWriter(System.out);
			//out = new PrintWriter(new FileWriter("a.out"));
		}
		catch (Exception ex) {
		}
		long stime = System.currentTimeMillis();
		solve();
		if (System.getProperty("ONLINE_JUDGE") == null) {
			out.println("\nTime elapsed: " + (System.currentTimeMillis() - stime) + "ms");
		}
		out.close();
	}
	
	static class Input {
		static StringTokenizer token = null;
		static BufferedReader in;
		static {
			try {
				if (System.getProperty("ONLINE_JUDGE") == null) {
					in = new BufferedReader(new FileReader("in.txt"));
				}
				else {
					in = new BufferedReader(new InputStreamReader(System.in));
				}
			}
			catch (Exception ex) {
			}
		}
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
			}
			catch (IOException e) {
			}
			return token.nextToken();
		}
	}
}