import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class E {

	private static void solve() throws IOException {
		int n = nextInt(), edges = nextInt();
		int goFrom = nextInt() - 1, goTo = nextInt() - 1;
		boolean[][] can = new boolean[n][n];
		for (int i = 0; i < edges; i++) {
			int from = nextInt() - 1, to = nextInt() - 1;
			can[from][to] = true;
		}
		int[][] dist = new int[n][n];
		final int INF = Integer.MAX_VALUE / 2;
		for (int i = 0; i < n; i++) {
			fill(dist[i], INF);
			for (int j = 0; j < n; j++) {
				if (can[i][j]) {
					dist[i][j] = 1;
				}
			}
			dist[i][i] = 0;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		int buses = nextInt();
		int[] s = new int[buses];
		int[] t = new int[buses];
		for (int i = 0; i < buses; i++) {
			s[i] = nextInt() - 1;
			t[i] = nextInt() - 1;
		}
		
		boolean[][] haveBus = new boolean[n][buses];
		
		for (int dontUse = 0; dontUse < n; dontUse++) {
			int[][] d = new int[n][n];
			for (int[] dd: d) {
				fill(dd, INF);
			}
			for (int i = 0; i < n; i++) {
				if (i == dontUse) {
					continue;
				}
				d[i][i] = 0;
				for (int j = 0; j < n; j++) {
					if (i == dontUse || j == dontUse) {
						continue;
					}
					if (can[i][j]) {
						d[i][j] = 1;
					}
				}
			}
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
			for (int i = 0; i < buses; i++) {
				haveBus[dontUse][i] = dist[s[i]][t[i]] != INF && dist[s[i]][t[i]] != d[s[i]][t[i]];
			}
		}

		int[] isGood = new int[n];
		fill(isGood, INF);
		isGood[goTo] = 0;
		boolean change = true;

		int[][] distUsingBad = new int[n][n];
		int iterations = 0;
		recalcDistUsingBad(n, can, INF, isGood, distUsingBad);
		while (change) {
			++iterations;
			change = false;
			for (int from = 0; from < n; from++) {
				if (isGood[from] != INF) {
					continue;
				}
				boolean haveGoodBus = false;
				for (int bus = 0; bus < buses; bus++) {
					boolean havePath = haveBus[from][bus];
					if (!havePath) {
						continue;
					}
					if (distUsingBad[from][t[bus]] != dist[from][t[bus]]) {
						haveGoodBus = true;
						break;
					}
				}
				if (haveGoodBus) {
					change = true;
					isGood[from] = iterations;
				}
			}
			recalcDistUsingBad(n, can, INF, isGood, distUsingBad);
		}
		if (isGood[goFrom] == INF) {
			out.println(-1);
		} else {
			out.println(isGood[goFrom]);
		}
	}

	private static void recalcDistUsingBad(int n, boolean[][] can, final int INF, int[] isGood,
			int[][] distUsingBad) {
		for (int[] dd : distUsingBad) {
			fill(dd, INF);
		}
		for (int i = 0; i < n; i++) {
			if (isGood[i] != INF) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (isGood[j] != INF) {
					continue;
				}
				if (can[i][j]) {
					distUsingBad[i][j] = 1;
				}
			}
			distUsingBad[i][i] = 0;
		}
		for (int k = 0; k < n; k++) {
			int[] dubk = distUsingBad[k];
			for (int i = 0; i < n; i++) {
				int[] dubi = distUsingBad[i];
				for (int j = 0; j < n; j++) {
					dubi[j] = min(dubi[j], dubi[k] + dubk[j]);
				}
			}
		}
	}

	static int min(int a, int b) {
		return a < b ? a : b;
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