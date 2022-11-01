import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int n = nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(nextInt(), nextInt());
		}
		int q = nextInt();
		Point[] queries = new Point[q];
		for (int i = 0; i < q; i++) {
			queries[i] = new Point(nextInt(), nextInt());
		}
		out.println(yes(a, queries) ? "YES" : "NO");
	}

	static boolean yes(Point[] a, Point[] queries) {
		Point best = null;
		for (Point p : a) {
			if (best == null || best.y > p.y || best.y == p.y && best.x > p.x) {
				best = p;
			}
		}
		{
			Point[] copy = new Point[a.length - 1];
			int cnt = 0;
			for (Point p : a) {
				if (p != best) {
					copy[cnt++] = p.sub(best);
				}
			}
			a = copy;
		}
		sort(a);
		{
			Point[] copy = queries.clone();
			for (int i = 0; i < copy.length; i++) {
				copy[i] = copy[i].sub(best);
				if (copy[i].y < 0 || copy[i].y == 0 && copy[i].x <= 0) {
					return false;
				}
			}
			queries = copy;
		}
		for (Point p : queries) {
			int index = binarySearch(a, p);
			if (index >= 0) {
				return false;
			}
			index = ~index;
			if (index == 0 || index == a.length) {
				return false;
			}
			Point p1 = a[index - 1];
			Point p2 = a[index];
			if (index == a.length - 1 && p2.vmul(p) == 0) {
				return false;
			}
			if (index == 1 && p1.vmul(p) == 0) {
				return false;
			}
			Point p1p2 = p2.sub(p1);
			Point p1p = p.sub(p1);
			long vmul = p1p2.vmul(p1p);
			if (vmul <= 0) {
				return false;
			}
		}
		return true;
	}

	static class Point implements Comparable<Point> {
		final static Point ZERO = new Point(0, 0);
		final int x, y;

		private Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		Point sub(Point p) {
			return new Point(x - p.x, y - p.y);
		}

		long vmul(Point p) {
			return (long) x * p.y - (long) y * p.x;
		}

		long sqAbs() {
			return (long) x * x + (long) y * y;
		}

		@Override
		public int compareTo(Point o) {
			int cmp = -Long.signum(vmul(o));
			if (cmp != 0) {
				return cmp;
			}
			return Long.signum(sqAbs() - o.sqAbs());
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