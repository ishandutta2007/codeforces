import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class F {

	static int treeN;
	static long treeAdd[], treeMin[];

	static void treePush(int i) {
		if (i < treeN) {
			long v = treeAdd[i];
			if (v != 0) {
				treeAdd[i << 1] += v;
				treeMin[i << 1] += v;
				treeAdd[(i << 1) + 1] += v;
				treeMin[(i << 1) + 1] += v;
				treeAdd[i] = 0;
			}
		}
	}

	static void treeFix(int i) {
		treeMin[i] = min(treeMin[i << 1], treeMin[(i << 1) + 1]) + treeAdd[i];
	}

	static void treeAdd(int from, int to, long v) {
		if (from == to) {
			return;
		}
		from += treeN;
		to += treeN;
		int x = from;
		for (int i = 31 - Integer.numberOfLeadingZeros(x); i >= 0; i--) {
			treePush(x >> i);
		}
		int y = 0;
		while (x < to) {
			if ((x & ((1 << (y + 1)) - 1)) == 0 && x + (1 << (y + 1)) <= to) {
				++y;
			} else if (x + (1 << y) > to) {
				--y;
			} else {
				for (int i = Integer.numberOfTrailingZeros(x); i >= y; i--) {
					treePush(x >> i);
				}
				treeAdd[x >> y] += v;
				treeMin[x >> y] += v;
				for (int i = 1, l = 31 - Integer.numberOfLeadingZeros(x >> y); i <= l; i++) { // XXX
					treeFix(x >> (y + i));
				}
				x += 1 << y;
			}
		}
	}

	static long treeGet(int from, int to) {
		from += treeN;
		to += treeN;
		long res = Long.MAX_VALUE;
		int x = from;
		for (int i = 31 - Integer.numberOfLeadingZeros(x); i > 0; i--) {
			treePush(x >> i);
		}
		int y = 0;
		while (x < to) {
			if ((x & ((1 << (y + 1)) - 1)) == 0 && x + (1 << (y + 1)) <= to) {
				++y;
			} else if (x + (1 << y) > to) {
				--y;
			} else {
				for (int i = Integer.numberOfTrailingZeros(x); i >= y; i--) {
					treePush(x >> i);
				}
				res = min(res, treeMin[x >> y]);
				x += 1 << y;
			}
		}
		return res;
	}

	static class Edge {
		final int to;
		final long w;

		Edge(int to, long w) {
			this.to = to;
			this.w = w;
		}
	}

	static class Query {
		final int i, l, r;

		Query(int i, int l, int r) {
			this.i = i;
			this.l = l;
			this.r = r;
		}
	}

	static List<Edge> edges[];
	static int pos;
	static long depth[];
	static int left[], right[];
	static List<Query> queries[];
	static long ans[];

	static void solve() throws Exception {
		int n = scanInt();
		int q = scanInt();
//		int n = 500000;
//		int q = 500000;
		edges = new List[n];
		for (int i = 0; i < n - 1; i++) {
			int p = scanInt() - 1;
//			int p = i;
			if (edges[p] == null) {
				edges[p] = new ArrayList<>(1);
			}
			edges[p].add(new Edge(i + 1, scanLong()));
//			edges[i].add(new Edge(i + 1, 1000000000));
		}
		depth = new long[n];
		left = new int[n + 1];
		right = new int[n];
		pos = 0;
		dfs1(0, 0);
		left[n] = pos;
		treeN = pos;
		treeAdd = new long[2 * treeN];
		treeMin = new long[2 * treeN];
		for (int i = 0; i < pos; i++) {
			treeAdd[treeN + i] = treeMin[treeN + i] = depth[i];
		}
		for (int i = treeN - 1; i > 0; i--) {
			treeFix(i);
		}
		queries = new List[n];
		for (int qq = 0; qq < q; qq++) {
			int v = scanInt() - 1;
//			int v = qq;
			if (queries[v] == null) {
				queries[v] = new ArrayList<>(1);
			}
			queries[v].add(new Query(qq, scanInt() - 1, scanInt()));
//			queries[qq].add(new Query(qq, 0, n));
		}
		ans = new long[q];
		dfs2(0);
		for (int qq = 0; qq < q; qq++) {
			out.println(ans[qq]);
		}
	}

	static void dfs1(int cur, long curDepth) {
		left[cur] = pos;
		if (edges[cur] == null) {
			depth[pos] = curDepth;
			++pos;
		} else {
			List<Edge> ee = edges[cur];
			for (int i = 0; i < ee.size(); i++) {
				Edge e = ee.get(i);
				dfs1(e.to, curDepth + e.w);
			}
		}
		right[cur] = pos;
	}

	static void dfs2(int cur) {
		if (queries[cur] != null) {
			List<Query> qq = queries[cur];
			for (int i = 0; i < qq.size(); i++) {
				Query q = qq.get(i);
				ans[q.i] = treeGet(left[q.l], left[q.r]);
			}
		}
		if (edges[cur] != null) {
			List<Edge> ee = edges[cur];
			for (int i = 0; i < ee.size(); i++) {
				Edge e = ee.get(i);
				int next = e.to, el = left[next], er = right[next];
				long ew = e.w;
				treeAdd(0, treeN, ew);
				treeAdd(el, er, -2 * ew);
				dfs2(next);
				treeAdd(el, er, 2 * ew);
				treeAdd(0, treeN, -ew);
			}
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}