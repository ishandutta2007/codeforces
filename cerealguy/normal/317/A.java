import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		long x = nextLong(), y = nextLong();
		long m = nextLong();
		long steps = steps(x, y, m);
		out.println(steps);
	}

	private static long steps(long x, long y, long m) {
		if (x >= m || y >= m) {
			return 0;
		}
		if (x <= 0 && y <= 0) {
			return -1;
		}
		if (x < y) {
			long t = x;
			x = y;
			y = t;
		}
		long steps = 0;
		if (y < 0) {
			long stepsToMakeNonNegative = (Math.abs(y) + x - 1) / x;
			y += stepsToMakeNonNegative * x;
			steps += stepsToMakeNonNegative;
		}
		while (x < m && y < m) {
			long nx = max(x, y);
			long ny = x + y;

			x = nx;
			y = ny;
			++steps;
		}
		return steps;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("a.in");
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