import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt(), edges = nextInt();
		List<Edge>[] graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		Edge[] allEdges = new Edge[edges];
		long[] sum = new long[n];
		for (int i = 0; i < edges; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			int cap = nextInt();
			Edge e = new Edge(u, v, cap, i);
			graph[u].add(e);
			graph[v].add(e);
			sum[u] += cap;
			sum[v] += cap;
			allEdges[i] = e;
		}
		sum[n - 1] *= 2;

		long[] in = new long[n];
		List<Integer> order = new ArrayList<>();
		
		int[] pos = new int[n];
		fill(pos, -1);
		order.add(0);
		for (int i = 0; i < order.size(); i++) {
			int u = order.get(i);
			pos[u] = i;
			for (Edge edge : graph[u]) {
				int v = edge.u ^ edge.v ^ u;
				if (pos[v] >= 0) {
					continue;
				}
				in[v] += edge.cap;
				if (in[v] * 2L == sum[v]) {
					order.add(v);
				}
			}
		}
		
		for (int i = 0; i < edges; i++) {
			Edge e = allEdges[i];
			if (pos[e.u] < pos[e.v]) {
				out.println(0);
			} else {
				out.println(1);
			}
		}
	}

	static class Edge {
		int u, v, cap, id;

		public Edge(int u, int v, int cap, int id) {
			this.u = u;
			this.v = v;
			this.cap = cap;
			this.id = id;
		}

	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		if (new File("c.in").exists()) {
			br = new BufferedReader(new FileReader("c.in"));
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