import java.io.*;
import java.util.*;

public class E {

	private static void solve() throws IOException {
		int n = nextInt(), queries = nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		SegmentTree tree = new SegmentTree(n);
		for (int i = 0; i < queries; i++) {
			int type = nextInt();
			if (type == 1) {
				int aPos = nextInt() - 1;
				int bPos = nextInt() - 1;
				int size = nextInt();
				tree.set(bPos, bPos + size, ((long) aPos << 32) + bPos);
			} else {
				int pos = nextInt() - 1;
				long what = tree.get(pos);
				if (what == SegmentTree.NULL) {
					out.println(b[pos]);
				} else {
					int bPos = (int) what;
					int aPos = (int) (what >>> 32);
					out.println(a[aPos + pos - bPos]);
				}
			}
		}
	}

	static class SegmentTree {
		final static long NULL = Long.MIN_VALUE;
		int n;
		long[] what;

		SegmentTree(int n) {
			n = Integer.highestOneBit(2 * n - 1);
			this.n = n;
			what = new long[2 * n];
			Arrays.fill(what, NULL);
		}

		void set(int l, int r, long val) {
			set1(l, r, 1, 0, n, val);
		}

		void set1(int l, int r, int i, int from, int to, long val) {
			if (from >= r || to <= l)
				return;
			if (from >= l && to <= r) {
				what[i] = val;
			} else {
				int m = (from + to) / 2;
				if (what[i] != NULL) {
					what[2 * i] = what[i];
					what[2 * i + 1] = what[i];
					what[i] = NULL;
				}
				set1(l, r, 2 * i, from, m, val);
				set1(l, r, 2 * i + 1, m, to, val);
			}
		}

		long get(int i) {
			long ret = NULL;
			for (i += n; i > 0; i >>= 1) {
				if (what[i] != NULL) {
					ret = what[i];
				}
			}
			return ret;
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