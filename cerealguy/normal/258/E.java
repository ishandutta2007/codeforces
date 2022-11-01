import static java.lang.Math.max;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class E {

	static List<Integer>[] edges;
	static List<Operation>[] ops;

	static class Operation {
		final int u, v;

		private Operation(int u, int v) {
			this.u = u;
			this.v = v;
		}
	}

	private static void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			edges[u].add(v);
			edges[v].add(u);
		}
		ops = new List[n];
		for (int i = 0; i < n; i++) {
			ops[i] = new ArrayList<Operation>();
		}

		for (int i = 0; i < m; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			Operation op = new Operation(u, v);
			ops[u].add(op);
			ops[v].add(op);
		}

		timeIn = new int[n];
		timeOut = new int[n];
		time = 0;
		dfs0(0, -1);
		problemAnswer = new int[n];
		curSegmentTree = new SegmentTree(n);
		dfs(0, -1);
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			int ok = n - 1 - problemAnswer[i];
			ok = max(ok, 0);
			out.print(ok);
		}
		out.println();
	}

	static SegmentTree curSegmentTree;

	static void dfs(int u, int p) {
		for (Operation op : ops[u]) {
			int v = op.u ^ op.v ^ u;
			curSegmentTree.add(timeIn[u], timeOut[u], 1);
			curSegmentTree.add(timeIn[v], timeOut[v], 1);
		}
		for (int v : edges[u]) {
			if (v == p) {
				continue;
			}
			dfs(v, u);
		}
		curSegmentTree.getMinAndCount(0, problemAnswer.length);
		problemAnswer[u] = curSegmentTree.retMin == 0 ? curSegmentTree.retCountMin : 0;
		for (Operation op : ops[u]) {
			int v = op.u ^ op.v ^ u;
			curSegmentTree.add(timeIn[u], timeOut[u], -1);
			curSegmentTree.add(timeIn[v], timeOut[v], -1);
		}
	}

	static int[] problemAnswer;

	static int[] timeIn;
	static int[] timeOut;
	static int time;

	static void dfs0(int u, int p) {
		timeIn[u] = time++;
		for (int v : edges[u]) {
			if (v == p) {
				continue;
			}
			dfs0(v, u);
		}
		timeOut[u] = time;
	}

	static class SegmentTree {

		final static int INF = Integer.MAX_VALUE / 2;
		int h, n;
		int[] min;
		int[] countMin;
		int[] add;

		SegmentTree(int n) {
			while (1 << h < n)
				h++;
			this.n = 1 << h;
			min = new int[1 << h + 1];
			add = new int[1 << h + 1];
			countMin = new int[1 << h + 1];
			fill(countMin, 1 << h, 1 << h + 1, 1);
			for (int i = (1 << h) - 1; i > 0; --i) {
				countMin[i] = countMin[2 * i] + countMin[2 * i + 1];
			}
		}

		void add(int l, int r, int val) {
			add1(l, r, 1, 0, 1 << h, val);
		}

		void add1(int l, int r, int i, int from, int to, int val) {
			if (from >= r || to <= l)
				return;
			if (from >= l && to <= r) {
				add[i] += val;
				min[i] += val;
			} else {
				int m = (from + to) / 2;
				add1(l, r, 2 * i, from, m, val);
				add1(l, r, 2 * i + 1, m, to, val);
				int u = min[2 * i], v = min[2 * i + 1];
				min[i] = Math.min(u, v) + add[i];
				if (u < v) {
					countMin[i] = countMin[2 * i];
				} else {
					if (u > v) {
						countMin[i] = countMin[2 * i + 1];
					} else {
						countMin[i] = countMin[2 * i] + countMin[2 * i + 1];
					}
				}
			}
		}

		void getMinAndCount(int l, int r) {
			retMin = INF;
			retCountMin = 0;
			get1(l, r, 1, 0, 1 << h, 0);
		}

		int retMin;
		int retCountMin;

		void get1(int l, int r, int i, int from, int to, int added) {
			if (from >= r || to <= l) {
				return;
			}
			if (from >= l && to <= r) {
				if (retMin > min[i] + added) {
					retMin = min[i] + added;
					retCountMin = 0;
				}
				if (retMin == min[i] + added) {
					retCountMin += countMin[i];
				}
			} else {
				int m = (from + to) / 2;
				get1(l, r, 2 * i, from, m, added + add[i]);
				get1(l, r, 2 * i + 1, m, to, added + add[i]);
			}
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