import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		int n = nextInt(), R = nextInt(), r = nextInt();
		out.println(get(n, R, r) ? "YES" : "NO");
	}

	static boolean get(int n, int R, int r) {
		if (R < r) {
			return false;
		}
		if (R < 2 * r) {
			return n == 1;
		}
		if (R == 2 * r) {
			return n <= 2;
		}
		double angle = Math.asin((double) r / (R - r));
		double ok = angle * n;
		if (ok < Math.PI + 1e-9) {
			return true;
		} else {
			return false;
		}
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