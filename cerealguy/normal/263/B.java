import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		sort(a);
		int point = get(a, k);
		if (point < 0) {
			out.println(point);
		} else {
			out.println(point + " " + point);
		}
	}

	private static int get(int[] a, int k) {
		if (k > a.length) {
			return -1;
		}
		if (k == a.length) {
			return 0;
		}
		k = a.length - k;
		if (a[k] > a[k - 1]) {
			return a[k];
		} else {
			return -1;
		}
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		if (new File("b.in").exists()) {
			br = new BufferedReader(new FileReader("b.in"));
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