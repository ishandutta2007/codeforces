import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class D {

	@SuppressWarnings("unchecked")
	static void solve() throws IOException {
		n = nextInt();
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			Edge e = new Edge(u, v);
			edges[u].add(e);
			edges[v].add(e);
		}
		badEdges = new int[n];
		totalEdges = new int[n];
		dfs0(0, -1);
		answerForTheProblem = new int[n];
		answerForTheProblem[0] = badEdges[0];
		dfs1(0, -1);
		int ans = Integer.MAX_VALUE;
		for (int i : answerForTheProblem) {
			ans = min(ans, i);
		}
		out.println(ans);
		for (int i = 0; i < n; i++) {
			if (answerForTheProblem[i] == ans) {
				out.print((i + 1) + " ");
			}
		}
		out.println();
	}

	static int[] answerForTheProblem;

	static void dfs1(int u, int p) {
		for (Edge edge : edges[u]) {
			int v = edge.u ^ edge.v ^ u;
			if (v == p) {
				continue;
			}
			int bad = answerForTheProblem[u] - badEdges[v];
			if (u != edge.u) {
				bad--;
			} else {
				bad++;
			}
			answerForTheProblem[v] = badEdges[v] + bad;
			dfs1(v, u);
		}
	}

	static void dfs0(int u, int p) {
		for (Edge edge : edges[u]) {
			int v = edge.u ^ edge.v ^ u;
			if (v == p) {
				continue;
			}
			totalEdges[u]++;
			if (u != edge.u) {
				badEdges[u]++;
			}
			dfs0(v, u);
			totalEdges[u] += totalEdges[v];
			badEdges[u] += badEdges[v];
		}
	}

	static int[] badEdges, totalEdges;

	static class Edge {
		final int u, v;

		public Edge(int u, int v) {
			this.u = u;
			this.v = v;
		}
	}

	static int n;
	static List<Edge>[] edges;

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
	}

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		File inputFile = new File("fn.in");
		if (inputFile.canRead()) {
			input = new FileInputStream(inputFile);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}
}