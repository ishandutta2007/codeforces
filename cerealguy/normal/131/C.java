import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int n = nextInt(), m = nextInt(), t = nextInt();
		long[][] c = getC(max(n, m) + 1);
		long res = 0;
		for (int a = 4; a < t; a++) {
			if (a > n || t - a > m) {
				continue;
			}
			res += c[n][a] * c[m][t - a];
		}
		out.println(res);
	}

	static long[][] getC(int max) {
		long[][] c = new long[max][max];
		for (int i = 0; i < max; i++) {
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++) {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			}
		}
		return c;
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