import static java.lang.Math.min;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class C {

	static int n;
	static List<Edge>[] e;
	static int[] d0, d1, d2;

	private static void solve() throws IOException {
		n = nextInt();
		e = new List[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<Edge>();
		}
		for (int i = 0; i < n - 1; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			Edge edge = new Edge(u, v);
			e[u].add(edge);
			e[v].add(edge);
		}
		d0 = new int[n];
		d1 = new int[n];
		d2 = new int[n];
		int answer = Integer.MAX_VALUE;
		for (int man1 = 0; man1 < n; man1++) {
			fill(d0, 0);
			fill(d1, 0);
			fill(d2, 0);
			dfs(man1, -1);
			answer = min(answer, d2[man1]);
		}
		out.println(answer);
	}

	static class Edge {
		final int u, v;

		private Edge(int u, int v) {
			this.u = u;
			this.v = v;
		}
	}

	static void dfs(int u, int p) {
		int bestSave1 = 0;
		int bestSave2 = 0;
		for (int i = 0; i < e[u].size(); i++) {
			Edge edge = e[u].get(i);
			int v = edge.u ^ edge.v ^ u;
			if (v == p) {
				continue;
			}
			dfs(v, u);
			int pay = edge.u == u ? 0 : 1;
			d0[u] += d0[v] + pay;
			int curSave1 = d1[v] - d0[v] - pay + (1 ^ pay);
			bestSave1 = min(bestSave1, curSave1);
			int curSave2 = d2[v] - d0[v];
			bestSave2 = min(bestSave2, curSave2);
		}
		d1[u] = d0[u] + bestSave1;
		d2[u] = min(d1[u], d0[u] + bestSave2);
	}
	
	static int min(int a, int b) {
		return a < b? a: b;
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