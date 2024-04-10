import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt(), k = nextInt();
		String s = nextToken();
		int[][] dp = new int[n + 1][k];
		int[][] parent = new int[n + 1][k];

		for (int i = 0; i < s.length(); i++) {
			int val = s.charAt(i) - 'A';
			int[] next = dp[i + 1];
			int[] prev = dp[i];
			int[] par = parent[i + 1];
			fill(next, Integer.MAX_VALUE / 2);
			for (int from = 0; from < k; from++) {
				if (from == val) {
					continue;
				}
				if (next[val] > prev[from]) {
					next[val] = prev[from];
					par[val] = (from << 16) | val;
				}
			}
			int best1 = -1, best2 = -1;
			for (int j = 0; j < k; j++) {
				if (best1 < 0 || prev[best1] > prev[j]) {
					best2 = best1;
					best1 = j;
				} else {
					if (best2 < 0 || prev[best2] > prev[j]) {
						best2 = j;
					}
				}
			}
			for (int paint = 0; paint < k; paint++) {
				if (paint == val) {
					continue;
				}
				int from = paint != best1 ? best1 : best2;
				int cur = paint != best1 ? prev[best1] + 1 : prev[best2] + 1;
				if (next[paint] > cur) {
					next[paint] = cur;
					par[paint] = (from << 16) | paint;
				}
			}
		}
		int ans = Integer.MAX_VALUE;
		int last = -1;
		for (int i = 0; i < k; i++) {
			if (dp[n][i] < ans) {
				ans = dp[n][i];
				last = i;
			}
		}
		char[] c = new char[n];
		for (int i = n - 1; i >= 0; --i) {
			int ok = parent[i + 1][last];
			c[i] = (char) ('A' + ok);
			last = ok >>> 16;
		}
		out.println(ans);
		out.println(c);
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
	}

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		File inputFile = new File("fn.in");
		if (inputFile.canRead()) {
			input = new FileInputStream(inputFile);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}
}