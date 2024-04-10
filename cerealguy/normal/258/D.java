import java.io.*;
import java.util.*;

public class D {

	private static void solve() throws IOException {
		int n = nextInt(), ops = nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt();
		}
		double[][] prob = new double[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (p[i] > p[j]) {
					prob[i][j] = 1;
					prob[j][i] = 1;
				}
			}
		}
		for (int op = 0; op < ops; op++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			if (u > v) {
				int t = u;
				u = v;
				v = t;
			}
			for (int i = 0; i < n; i++) {
				if (i < u && i < v || (i > u && i > v)) {
					double x = prob[i][u], y = prob[i][v];
					prob[i][u] = (x + y) * 0.5;
					prob[i][v] = (x + y) * 0.5;
					prob[u][i] = (x + y) * 0.5;
					prob[v][i] = (x + y) * 0.5;
					continue;
				}
				if (i == u || i == v) {
					continue;
				}
				double x = prob[i][u], y = prob[i][v];

				prob[i][u] = (1 + x - y) * 0.5;
				prob[i][v] = (1 - x + y) * 0.5;
				prob[u][i] = (1 + x - y) * 0.5;
				prob[v][i] = (1 - x + y) * 0.5;
			}
			prob[u][v] = 0.5;
			prob[v][u] = 0.5;
		}
		double ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += prob[i][j];
			}
		}
		out.println(ans);
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