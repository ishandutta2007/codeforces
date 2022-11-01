import static java.lang.Math.max;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt(), q = nextInt();
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			v[i] = nextInt();
		}
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = nextInt() - 1;
		}
		int[] a = new int[q];
		int[] b = new int[q];
		long[] dp = new long[n];
		for (int i = 0; i < q; i++) {
			a[i] = nextInt();
			b[i] = nextInt();
			long answer = get(v, c, a[i], b[i], dp);
			out.println(answer);
		}
	}

	private static long get(int[] v, int[] c, long a, long b, long[] dp) {
		int n = c.length;
		fill(dp, Long.MIN_VALUE);
		long max1 = 0;
		int where1 = n;
		long max2 = Long.MIN_VALUE;

		for (int i = 0; i < n; i++) {
			int val = v[i];
			int col = c[i];

			long newCan = Long.MIN_VALUE;
			{
				long use = col != where1 ? max1 : max2;
				long can = use + val * b;
				newCan = can;
			}
			{
				if (dp[col] != Long.MIN_VALUE) {
					long can = dp[col] + val * a;
					if (newCan < can) {
						newCan = can;
					}
				}
			}

			if (newCan > dp[col]) {
				dp[col] = newCan;
				if (newCan > max1) {
					if (where1 == col) {
						max1 = newCan;
					} else {
						max2 = max1;
						max1 = newCan;
						where1 = col;
					}
				} else {
					if (newCan > max2) {
						max2 = newCan;
					}
				}
			}
		}
		
		return max1;
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		if (new File("c.in").exists()) {
			br = new BufferedReader(new FileReader("c.in"));
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