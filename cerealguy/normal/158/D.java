import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class D {

	private static void solve() throws IOException {
		int n = nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
		}
		int answer = get(t);
		out.println(answer);
	}

	static int get(int[] t) {
		int n = t.length;
		int best = Integer.MIN_VALUE;
		for (int d = 3; d <= n; d++) {
			if (n % d == 0) {
				best = max(best, get(t, d));
			}
		}
		return best;
	}

	static int get(int[] t, int d) {
		int n = t.length;
		int step = n / d;
		int best = Integer.MIN_VALUE;
		for (int r = 0; r < step; r++) {
			int sum = 0;
			for (int i = 0; i < d; i++) {
				sum += t[i * step + r];
			}
			best = max(best, sum);
		}
		return best;
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