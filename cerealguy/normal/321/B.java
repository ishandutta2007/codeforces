import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int enemyCards = nextInt();
		int ourCards = nextInt();
		boolean[] isAttack = new boolean[enemyCards];
		int[] enemyStrength = new int[enemyCards];
		int[] ourStrength = new int[ourCards];
		for (int i = 0; i < enemyCards; i++) {
			String type = nextToken();
			enemyStrength[i] = nextInt();
			isAttack[i] = "ATK".equals(type);
		}
		for (int i = 0; i < ourCards; i++) {
			ourStrength[i] = nextInt();
		}

		long answerToTheProblem = 0;

		{// use all enemy cards
			Graph graph = new Graph(ourCards + enemyCards + 2);
			int start = ourCards + enemyCards;
			int finish = ourCards + enemyCards + 1;

			for (int i = 0; i < ourCards; i++) {
				graph.addEdge(start, i, 1, ourStrength[i]);
			}
			for (int i = 0; i < enemyCards; i++) {
				graph.addEdge(ourCards + i, finish, 1, 0);
			}
			for (int i = 0; i < ourCards; i++) {
				for (int j = 0; j < enemyCards; j++) {
					if (isAttack[j]) {
						if (ourStrength[i] >= enemyStrength[j]) {
							graph.addEdge(i, j + ourCards, 1, enemyStrength[j]
									- ourStrength[i]);
						}
					} else {
						if (ourStrength[i] > enemyStrength[j]) {
							graph.addEdge(i, j + ourCards, 1, 0);
						}
					}
				}
			}

			long[] flowAndCost = graph.minCostFlow(start, finish);

			if (flowAndCost[0] == enemyCards) {
				long damageDealt = -flowAndCost[1];
				for (int i = 0; i < ourCards; i++) {
					damageDealt += ourStrength[i];
				}
				// System.err.println(damageDealt);
				answerToTheProblem = Math.max(answerToTheProblem, damageDealt);
			}
		}
		
		{//use not all enemy cards
			List<Integer> ourAttacks = new ArrayList<>();
			List<Integer> enemyAttacks = new ArrayList<>();
			for (int i : ourStrength) {
				ourAttacks.add(i);
			}
			for (int i = 0; i < enemyCards; i++) {
				if (isAttack[i]) {
					enemyAttacks.add(enemyStrength[i]);
				}
			}
			Collections.sort(ourAttacks);
			Collections.sort(enemyAttacks);
			for (int killEnemyCards = 1; killEnemyCards <= enemyAttacks.size()
					&& killEnemyCards <= ourAttacks.size(); ++killEnemyCards) {
				long curAnswer = 0;
				boolean ok = true;
				List<Integer> our = ourAttacks.subList(ourAttacks.size()
						- killEnemyCards, ourAttacks.size());
				List<Integer> enemy = enemyAttacks.subList(0, killEnemyCards);
				for (int i = 0; i < killEnemyCards; i++) {
					int diff = our.get(i) - enemy.get(i);
					if (diff < 0) {
						ok = false;
						break;
					}
					curAnswer += diff;
				}
				if (ok) {
					// System.err.println("our: "+our);
					// System.err.println("enemy: "+enemy);
					// System.err.println(curAnswer);
					answerToTheProblem = Math
							.max(answerToTheProblem, curAnswer);
				}
			}
		}
		out.println(answerToTheProblem);
	}

	public static class QItem implements Comparable<QItem> {
		long d;
		int v;

		public QItem(long d, int v) {
			this.d = d;
			this.v = v;
		}

		public int compareTo(QItem q) {
			return d < q.d ? -1 : d > q.d ? 1 : 0;
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

		// input: s - source, t - sink
		// output: maximum flow and minimum cost
		public long[] minCostFlow(int s, int t) {
			final long INF = 1L << 50;
			long flow = 0;
			long flowCost = 0;
			long[] u = new long[n];
			long[] d = new long[n];
			Edge[] p = new Edge[n];
			Queue<QItem> q = new PriorityQueue<QItem>();
			while (true) {
				q.clear();
				q.add(new QItem(0, s));
				Arrays.fill(d, INF);
				Arrays.fill(p, null);
				d[s] = 0;
				while (!q.isEmpty()) {
					QItem cur = q.poll();
					if (cur.d != d[cur.v]) {
						continue;
					}
					for (int i = 0; i < edges[cur.v].size(); i++) {
						Edge e = edges[cur.v].get(i);
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
				for (Edge e = p[t]; e != null; e = p[e.rev.to]) {
					e.flow += min;
					e.rev.flow -= min;
					flowCost += (long) min * e.cost;
				}
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
		File file = new File("b.in");
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