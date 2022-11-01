import java.io.*;
import java.util.*;

public class B {

	private void solve() throws IOException {
		int n = nextInt(), k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		double left = 0, right = 1000;
		for (int it = 0; it < 50; it++) {
			double m = (left + right) / 2;
			double s1 = 0, s2 = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] < m) {
					s1 += m - a[i];
				} else {
					s2 += a[i] - m;
				}
			}
			if (s2 * (100 - k) * .01 >= s1) {
				left = m;
			} else {
				right = m;
			}
		}
		out.printf(Locale.US, "%.9f", left);
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}