import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int n = nextInt(), k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int c = solve(a, n, k);
		out.println(c);
	}

	private static int solve(int[] a, int n, int k) {
		if (k >= n - 1) {
			return 0;
		}
		int[] minCost = new int[n];
		int low = -1, high = Integer.MAX_VALUE;
		while (high > low + 1) {
			int c = (low + high) >>> 1;
			for (int i = 0; i < n; i++) {
				minCost[i] = i;
			}
			for (int i = 0; i < n; i++) {
				for (int to = i + 1; to < n; to++) {
					int diff = Math.abs(a[to] - a[i]);
					if (diff <= (long)c * (long)(to-i)) {
						int val = minCost[i] + to - i - 1;
						if (minCost[to] > val) {
							minCost[to] = val;
						}
					}
				}
			}
			int best = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				best = Math.min(best, minCost[i] + n - 1 - i);
			}
			if (best <= k) {
				high = c;
			} else {
				low = c;
			}
		}
		return high;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
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
}