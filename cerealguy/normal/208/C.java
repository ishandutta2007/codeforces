import static java.lang.Math.max;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		
		
		int n = nextInt();
		int edges = nextInt();
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < edges; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			g[u][v] = true;
			g[v][u] = true;
		}
		out.println(solve(g));
	}
	
	static double solve(boolean[][] g) {
		int n = g.length;
		double[] ways1 = new double[n];
		double[] ways2 = new double[n];
		int[] d1 = new int[n];
		int[] d2 = new int[n];
		ways(g, 0, ways1, d1);
		ways(g, n - 1, ways2, d2);

		int distance = d1[n - 1];
		double total = ways1[n - 1];
		double best = total;
		for (int city = 1; city < n - 1; city++) {
			if (d1[city] + d2[city] != distance) {
				continue;
			}
			double cur = ways1[city] * ways2[city] * 2;
			best = max(best, cur);
		}
		double result = best / total;
		return result;
	}

	static void ways(boolean[][] g, int start, double[] ways, int[] distance) {
		int n = g.length;
		Queue<Integer> q = new ArrayDeque<Integer>();
		fill(distance, -1);
		distance[start] = 0;
		q.add(start);
		ways[start] = 1;
		while (!q.isEmpty()) {
			int u = q.poll();
			for (int v = 0; v < n; v++) {
				if (!g[u][v]) {
					continue;
				}
				if (distance[v] < 0) {
					distance[v] = distance[u] + 1;
					q.add(v);
					ways[v] = ways[u];
				} else {
					if (distance[v] == distance[u] + 1) {
						ways[v] += ways[u];
					}
				}
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