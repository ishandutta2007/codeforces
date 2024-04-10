import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class D {

	static List<Integer>[] e;
	static int[] p;
	static int n;
	static int[] dist;
	static boolean found;

	private static void solve() throws IOException {
		n = nextInt();
		e = (List<Integer>[]) new List<?>[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			e[u].add(v);
			e[v].add(u);
		}
		p = new int[n];
		fill(p, -2);
		p[0] = -1;
		dist = new int[n];
		fill(dist, -1);
		found = false;
		dfs(0);
		Queue<Integer> q = new ArrayDeque<Integer>();
		for (int i = 0; i < n; i++) {
			if (dist[i] == 0) {
				q.add(i);
			}
		}
		while (!q.isEmpty()) {
			int u = q.poll();
			for (int v : e[u]) {
				if (dist[v] < 0) {
					dist[v] = dist[u] + 1;
					q.add(v);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(dist[i] + " ");
		}
	}

	static void dfs(int u) {
		for (int v : e[u]) {
			if (v == p[u]) {
				continue;
			}
			if (p[v] == -2) {
				p[v] = u;
				dfs(v);
				continue;
			}
			if (found) {
				continue;
			}
			for (int i = u; i != p[v]; i = p[i]) {
				dist[i] = 0;
			}
			found = true;
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