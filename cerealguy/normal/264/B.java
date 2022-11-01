import static java.lang.Math.max;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[] divisor = divisor(a[n - 1] + 1);

		int[] dp = new int[a[n - 1] + 1];
		fill(dp, -1);
		dp[1] = 0;
		int answer = 0;

		for (int i = 0; i < n; i++) {
			int val = a[i];
			int best = 0;
			while (val > 1) {
				int p = divisor[val];
				while (val % p == 0) {
					val /= p;
				}
				best = max(best, dp[p]);
			}
			val = a[i];
			while (val > 1) {
				int p = divisor[val];
				while (val % p == 0) {
					val /= p;
				}
				dp[p] = max(dp[p], best + 1);
			}
			answer = max(answer, best + 1);
		}
		out.println(answer);

	}

	static int[] divisor(int max) {
		int[] divisor = new int[max];
		fill(divisor, -1);
		for (int i = 2; i * i < max; i++) {
			if (divisor[i] < 0) {
				for (int j = i * i; j < max; j += i) {
					divisor[j] = i;
				}
			}
		}
		for (int i = 2; i < max; i++) {
			if (divisor[i] < 0) {
				divisor[i] = i;
			}
		}
		return divisor;
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		if (new File("b.in").exists()) {
			br = new BufferedReader(new FileReader("b.in"));
		} else {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

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