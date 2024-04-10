import static java.lang.System.currentTimeMillis;

import java.io.*;
import java.util.*;

public class C {

	static void print() {
		int n = 80, m = 80;
		int[] what = new int[n * m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				what[i * m + j] = i * m + j >> 1;
			}
		}
		Random rng = new Random();
		// for (int i = 0; i < what.length; i++) {
		// int j = rng.nextInt(i + 1);
		// what[i] = what[j];
		// what[j] = i;
		// }
		out.println(n + " " + m);
		for (int i = 0; i < what.length; i++) {
			out.println(what[i]);
		}
		out.flush();
	}

	static void solve() throws IOException {
		// print();
		long time = currentTimeMillis();
		int n = nextInt(), m = nextInt();
		int[][] what = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				what[i][j] = nextInt();
			}
		}
		Graph g = new Graph(n * m + 2);
		int[] dx = { 0, 0, 1, -1 };
		int[] dy = { 1, -1, 0, 0 };
		int start = n * m;
		int finish = n * m + 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int from = i * m + j;
				if (((i ^ j) & 1) != 0) {
					g.addEdge(from, finish, 1, 0);
					continue;
				} else {
					g.addEdge(start, from, 1, 0);
				}
				for (int dir = 0; dir < 4; dir++) {
					int ni = i + dx[dir];
					int nj = j + dy[dir];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
						continue;
					}
					int to = ni * m + nj;
					int cost = 1;
					if (what[i][j] == what[ni][nj]) {
						cost = 0;
					}
					g.addEdge(from, to, 1, cost);
				}
			}
		}
		long cost = g.minCostFlow(start, finish)[1];
		System.err.println(currentTimeMillis() - time);
		out.println(cost);
	}

	public static class QItem implements Comparable<QItem> {
		long d;
		int v;

		public QItem(long d, int v) {
			this.d = d;
			this.v = v;
		}

		public int compareTo(QItem q) {
			return Long.compare(d, q.d);
			// return d < q.d ? -1 : d > q.d ? 1 : 0;
		}
	}

	public static class Graph {
		public final int n;
		public List<Edge>[] edges;

		@SuppressWarnings("unchecked")
		public Graph(int n) {
			this.n = n;
			edges = new List[n];
			for (int i = 0; i < n; i++) {
				edges[i] = new ArrayList<Edge>();
			}
		}

		public void addEdge(int u, int v, int cap, int cost) {
			Edge e1 = new Edge(v, cap, cost);
			Edge e2 = new Edge(u, 0, -cost);
			e1.rev = e2;
			e2.rev = e1;
			edges[u].add(e1);
			edges[v].add(e2);
		}

		public void addUndirectedEdge(int u, int v, int cap, int cost) {
			Edge e1 = new Edge(v, cap, cost);
			Edge e2 = new Edge(u, cap, -cost);
			e1.rev = e2;
			e2.rev = e1;
			edges[u].add(e1);
			edges[v].add(e2);
		}

		public void clearFlow() {
			for (List<Edge> edgesList : edges) {
				for (Edge e : edgesList) {
					e.flow = 0;
				}
			}
		}

		public long[] minCostFlow(int s, int t) {
			final long INF = 1L << 50;
			long flow = 0;
			long flowCost = 0;

			long[] u = new long[n];
			Edge[] p = new Edge[n];
			long[] d = new long[n];
			Queue<QItem> q = new PriorityQueue<QItem>(n);

			long finalFlow = n - 2 >> 1;

			while (true) {
				q.clear();
				q.add(new QItem(0, s));
				Arrays.fill(d, INF);
				Arrays.fill(p, null);
				Arrays.fill(u, 0);
				d[s] = 0;
				while (!q.isEmpty()) {
					QItem cur = q.poll();
					if (cur.d != d[cur.v]) {
						continue;
					}
					if (cur.v == t) {
						break;
					}
					for (Edge e: edges[cur.v]) {
						long nd = d[cur.v] + e.cost + u[cur.v] - u[e.to];
						if (e.cap > e.flow && d[e.to] > nd) {
							d[e.to] = nd;
							p[e.to] = e;
							q.add(new QItem(nd, e.to));
						}
					}
				}
				if (p[t] == null) {
					break;
				}
				for (int i = 0; i < n; i++) {
					if (p[i] != null) {
						u[i] += d[i];
					}
				}
				int min = Integer.MAX_VALUE;
				for (Edge e = p[t]; e != null; e = p[e.rev.to]) {
					min = Math.min(min, e.cap - e.flow);
				}

				flow += min;
				long curCost = 0;
				for (Edge e = p[t]; e != null; e = p[e.rev.to]) {
					e.flow += min;
					e.rev.flow -= min;
					curCost += (long) min * e.cost;
				}
				flowCost += curCost;
				long okCost = (finalFlow - flow) * curCost / min + flowCost;
				if (okCost >= finalFlow) {
					flowCost = okCost;
					flow = finalFlow;
					break;
				}
				// if (flowCost > 0) {
				// break;
				// }
			}
			return new long[] { flow, flowCost };
		}
	}

	public static class Edge {
		public int to, cap, flow, cost;
		public Edge rev;

		public Edge(int to, int cap, int cost) {
			this.to = to;
			this.cap = cap;
			this.cost = cost;
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
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