import static java.lang.Math.max;
import static java.lang.Math.sqrt;

import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		int n = nextInt();
		int a = nextInt(), d = nextInt();
		int[] t = new int[n];
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
			v[i] = nextInt();
		}
		double slowMan = 0;
		for (int i = 0; i < n; i++) {
			slowMan = max(slowMan, t[i] + time(a, d, v[i]));
			out.println(slowMan);
		}
	}

	static double time(int a, int d, int v) {
		double t = (double) v / a;
		double dist = a * t * t * 0.5;
		if (dist <= d) {
			return (d - dist) / v + t;
		} else {
			return sqrt(2.0 * d / a);
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