import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class E {

	private static void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		int[] from = new int[m];
		int[] to = new int[m];
		List<Integer>[] e = new List[n];
		List<Integer>[] backE = new List[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<Integer>();
			backE[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			e[u].add(v);
			backE[v].add(u);
			from[i] = u;
			to[i] = v;
		}
		boolean[] v1 = new boolean[n];
		boolean[] v2 = new boolean[n];
		dfs(0, v1, e);
		dfs(n - 1, v2, backE);
		boolean[] v = new boolean[n];
		for (int i = 0; i < n; i++) {
			v[i] = v1[i] & v2[i];
		}
		boolean[] matters = new boolean[m];
		for (int i = 0; i < m; i++) {
			matters[i] = v[from[i]] & v[to[i]];
		}
		int[] answer = can(from, to, matters, n);
		if (answer == null) {
			out.println("No");
		} else {
			out.println("Yes");
			for (int i = 0; i < m; i++) {
				if (matters[i])
					out.println(answer[to[i]] - answer[from[i]]);
				else
					out.println(1);
			}
		}
	}

	static void dfs(int u, boolean[] visited, List<Integer>[] e) {
		visited[u] = true;
		for (int v : e[u]) {
			if (!visited[v]) {
				dfs(v, visited, e);
			}
		}
	}

	static int[] can(int[] from, int[] to, boolean[] matters, int n) {
		int[] low = new int[n];
		int[] high = new int[n];
		final int INF = Integer.MAX_VALUE / 2;
		fill(low, -INF);
		fill(high, INF);
		low[0] = 0;
		high[0] = 0;
		boolean change = true;
		while (change) {
			change = false;
			for (int i = 0; i < from.length; i++) {
				if (!matters[i]) {
					continue;
				}
				int u = from[i], v = to[i];
				if (low[v] < low[u] + 1) {
					change = true;
					low[v] = low[u] + 1;
				}
				if (low[v] > low[u] + 2) {
					change = true;
					low[u] = low[v] - 2;
				}
				if (high[v] > high[u] + 2) {
					change = true;
					high[v] = high[u] + 2;
				}
				if (high[v] < high[u] + 1) {
					change = true;
					high[u] = high[v] - 1;
				}
			}
			for (int i = 0; i < n; i++) {
				if (low[i] > high[i]) {
					return null;
				}
			}
		}
		return low;
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