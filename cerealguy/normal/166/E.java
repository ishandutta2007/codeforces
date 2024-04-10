import java.io.*;
import java.util.*;

public class E {

	static final int MOD = 1000000007;

	private static void solve() throws IOException {
		int n = nextInt();
		out.println(get(n));
	}

	static int get(int n) {
		long pow = 1;
		long ans = 1;
		for (int i = 0; i < n; i++) {
			ans = pow - ans;
			pow = 3L * pow % MOD;
		}
		ans %= MOD;
		if (ans < 0) {
			ans += MOD;
		}
		return (int) ans;
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}