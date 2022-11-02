import java.io.*;
import java.util.*;

public class F {

	private static void solve() throws IOException {
		int n = nextInt(), k = nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = 2 * nextInt();
			y[i] = 2 * nextInt();
		}
		if (k >= n) {
			out.println(-1);
			return;
		}
		int[] xs = getXCandidates(x, k);
		int[] ys = getXCandidates(y, k);
		Set<Long> set = new HashSet<Long>();
		for (int i = 0; i < n; i++) {
			set.add(toLong(x[i], y[i]));
		}
		List<Point> list = new ArrayList<Point>();
		for (int i = 0; i < xs.length; i++) {
			for (int j = 0; j < ys.length; j++) {
				if (isGood(x, y, xs[i], ys[j], k, set)) {
					list.add(new Point(xs[i], ys[j]));
				}
			}
		}
		out.println(list.size());
		for (Point p : list) {
			out.println(toString(p.x) + " " + toString(p.y));
		}
	}

	static String toString(int x) {
		return String.format(Locale.US, "%.2f", x * .5);
	}

	static boolean isGood(int[] x, int[] y, int cx, int cy, int k, Set<Long> set) {
		int n = x.length;
		for (int i = 0; i < n; i++) {
			long a = 2L * cx - x[i];
			long b = 2L * cy - y[i];
			if (bad(a) || bad(b) || !set.contains(toLong((int) a, (int) b))) {
				--k;
				if (k < 0) {
					return false;
				}
			}
		}
		return true;
	}

	static boolean bad(long a) {
		return a > Integer.MAX_VALUE || a < Integer.MIN_VALUE;
	}

	static long toLong(int x, int y) {
		return ((long) x << 32) | ((long) y & 0xFFFFFFFFL);
	}

	static int[] getXCandidates(int[] x, int k) {
		x = x.clone();
		Arrays.sort(x);
		int n = x.length;
		Set<Integer> set = new HashSet<Integer>();
		for (int a = 0; a <= k; a++) {
			for (int b = n - 1; b >= n - 1 - k + a; b--) {
				set.add((x[a] + x[b]) / 2);
			}
		}
		int[] res = new int[set.size()];
		int cnt = 0;
		for (int i : set) {
			res[cnt++] = i;
		}
		return res;
	}

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
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