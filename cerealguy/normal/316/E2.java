import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class E {
	static class Fenwick {
		private final int[] s;

		public Fenwick(int n) {
			s = new int[n];
		}

		public Fenwick(int[] a) {
			s = new int[a.length];
			for (int i = 0; i < a.length; i++) {
				add(i, sub(a[i], i == 0 ? 0 : a[i - 1]));
			}
		}

		public int getSum(int i) {
			int res = 0;
			for (; i >= 0; i = (i & i + 1) - 1) {
				res += s[i];
				if (res >= MOD) {
					res -= MOD;
				}
			}
			return res;
		}

		public void add(int i, int val) {
			for (; i < s.length; i |= i + 1) {
				s[i] += val;
				if (s[i] >= MOD) {
					s[i] -= MOD;
				}
			}
		}
	}

	static void solve() throws IOException {
		int n = nextInt(), q = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		POWS = new int[n][4];
		POWS[0] = ONE;
		for (int i = 1; i < n; i++) {
			mul(POWS[i - 1], MATRIX, POWS[i]);
		}
		SUMPOWS = new int[n + 1][4];
		for (int i = 1; i <= n; i++) {
			add(SUMPOWS[i - 1], POWS[i - 1], SUMPOWS[i]);
		}

		POWS_1 = new int[n][4];
		POWS_1[0] = ONE;
		for (int i = 1; i < n; i++) {
			mul(POWS_1[i - 1], INV, POWS_1[i]);
		}

		Fenwick fenwick = new Fenwick(a);
		SegmentTree tree = new SegmentTree(a);
		int[] temp = new int[4];

		while (q-- > 0) {
			int type = nextInt();
			int left = 0, right = 0, value = 0;
			// System.err.println(Arrays.toString(tree.add));
			// for (int i = 0; i < 2*tree.n; i++) {
			// System.err.println(Arrays.toString(tree.sum[i]));
			// }
			if (type == 1) {
				int index = nextInt() - 1;
				int newValue = nextInt();
				int oldValue = fenwick.getSum(index);
				left = index;
				right = index + 1;
//				System.err.println("change: "+oldValue+"->"+newValue);
				value = sub(newValue, oldValue);
//				System.err.println("OK "+value);
			}
			if (type == 2) {
				left = nextInt() - 1;
				right = nextInt();
				int[] matrix = tree.getSum(left, right);
				mul(matrix, POWS_1[left], temp);
				value = add(temp[0], temp[2]);
			}
			if (type == 3) {
				left = nextInt() - 1;
				right = nextInt();
				value = nextInt();
			}
			if (type == 2) {
				out.println(value);
			} else {
				tree.addOnSegment(left, right, value);
				fenwick.add(left, value);
				fenwick.add(right, sub(0,value));
			}
		}

	}

	static int[][] POWS_1;
	static int[][] POWS;
	static int[][] SUMPOWS;

	static class SegmentTree {

		int n;
		int[][] sum;
		int[] add;

		SegmentTree(int n) {
			n = Integer.highestOneBit(2 * n - 1);
			this.n = n;
			sum = new int[2 * n][4];
			add = new int[2 * n];
		}

		SegmentTree(int[] x) {
			this(x.length);
			for (int i = 0; i < x.length; i++) {
				add[i + n] = x[i];
				mul(POWS[i], x[i], sum[i + n]);
			}
			for (int i = n - 1; i > 0; --i) {
				add(sum[2 * i], sum[2 * i + 1], sum[i]);
			}
		}

		int[] temp = new int[4];
		int[] temp2 = new int[4];

		void fix(int i, int from, int to) {
			if (add[i] == 0) {
				return;
			}

			sub(SUMPOWS[to], SUMPOWS[from], temp);
			mul(temp, add[i], temp2);
			addToThis(sum[i], temp2);
		}

		void addOnSegment(int l, int r, int val) {
			addOnSegmentInner(l, r, 1, 0, n, val);
		}

		void addOnSegmentInner(int l, int r, int i, int from, int to, int val) {
			if (from >= r || to <= l)
				return;
			if (from >= l && to <= r) {
				add[i] = add(add[i], val);
				if (i < n) {
					add(sum[2 * i], sum[2 * i + 1], sum[i]);
				} else {
					fill(sum[i], 0);
				}
				fix(i, from, to);
			} else {
				int m = (from + to) / 2;
				addOnSegmentInner(l, r, 2 * i, from, m, val);
				addOnSegmentInner(l, r, 2 * i + 1, m, to, val);
				add(sum[2 * i], sum[2 * i + 1], sum[i]);
				fix(i, from, to);
			}
		}

		int[] sumResult = new int[4];

		int[] getSum(int l, int r) {
			fill(sumResult, 0);
			getSumInner(l, r, 1, 0, n);
			return sumResult;
		}

		void getSumInner(int l, int r, int i, int from, int to) {
			if (from >= r || to <= l)
				return;
			if (from >= l && to <= r) {
				addToThis(sumResult, sum[i]);
			} else {
				int m = (from + to) / 2;
				getSumInner(l, r, 2 * i, from, m);
				getSumInner(l, r, 2 * i + 1, m, to);
				if (add[i] != 0) {
					sub(SUMPOWS[Math.min(r, to)], SUMPOWS[Math.max(l, from)], temp);
					mul(temp, add[i], temp2);
					addToThis(sumResult, temp2);
				}
			}
		}
	}

	static final int MOD = 1000 * 1000 * 1000;

	static final int[] ONE = { 1, 0, 0, 1 };

	static final int[] MATRIX = { 0, 1, 1, 1 };
	static final int[] INV = { MOD - 1, 1, 1, 0 };

	static void mul(int[] a, int[] b, int[] res) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				long ok = 0;
				for (int k = 0; k < 2; k++) {
					ok += (long) a[toInt(i, k)] * b[toInt(k, j)];
				}
				res[toInt(i, j)] = (int) (ok % MOD);
			}
		}
	}

	static void sub(int[] a, int[] b, int[] res) {
		for (int i = 0; i < 4; i++) {
			res[i] = sub(a[i], b[i]);
		}
	}

	static void add(int[] a, int[] b, int[] res) {
		for (int i = 0; i < 4; i++) {
			res[i] = add(a[i], b[i]);
		}
	}

	static void addToThis(int[] a, int[] b) {
		for (int i = 0; i < 4; i++) {
			a[i] = add(a[i], b[i]);
		}
	}

	static void mul(int[] a, int k, int[] res) {
		for (int i = 0; i < 4; i++) {
			res[i] = (int) ((long) a[i] * k % MOD);
		}
	}

	static int add(int a, int b) {
		a += b;
		if (a >= MOD) {
			a -= MOD;
		}
		return a;
	}

	static int sub(int i, int j) {
		i -= j;
		if (i < 0) {
			i += MOD;
		}
		return i;
	}

	static int toInt(int i, int j) {
		return (i << 1) | j;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("e.in");
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