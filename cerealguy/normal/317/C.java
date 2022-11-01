import static java.lang.Math.min;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt();
		int v = nextInt();
		int edges = nextInt();
		boolean[][] can = new boolean[n][n];
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		for (int i = 0; i < edges; i++) {
			int u = nextInt() - 1, vv = nextInt() - 1;
			can[u][vv] = true;
			can[vv][u] = true;
		}
		// boolean[][] floyd = new boolean[n][];
		// for (int i = 0; i < n; i++) {
		// floyd[i] = can[i].clone();
		// }
		// for (int k = 0; k < n; k++) {
		// for (int i = 0; i < n; i++) {
		// if (!floyd[i][k]) {
		// continue;
		// }
		// for (int j = 0; j < n; j++) {
		// floyd[i][j] |= floyd[k][j];
		// }
		// }
		// }
		int[] parent = new int[n];
		fill(parent, -1);
		List<Integer> from = new ArrayList<>();
		List<Integer> to = new ArrayList<>();
		List<Integer> amount = new ArrayList<>();
		boolean good = true;
		for (int start = 0; start < n && good; start++) {
			if (parent[start] != -1) {
				continue;
			}
			Queue<Integer> queue = new ArrayDeque<>();
			queue.add(start);

			parent[start] = start;
			int[] out = new int[n];
			
			while (!queue.isEmpty()) {
				int u = queue.poll();
				for (int j = 0; j < n; j++) {
					if (!can[u][j]) {
						continue;
					}
					if (parent[j] == -1) {
						parent[j] = u;
						queue.add(j);
						++out[u];
					}
				}
			}
			
			long diff = 0;
			for (int i = 0; i < n; i++) {
				if (parent[i] >= 0) {
					diff += a[i] - b[i];
				}
			}
			
			if (diff != 0) {
				good = false;
				break;
			}
			queue.clear();
			for (int i = 0; i < n; i++) {
				if (out[i] == 0 && parent[i] >= 0) {
					queue.add(i);
				}
			}
			
			while (!queue.isEmpty()) {
				int leaf = queue.poll();
				if (--out[parent[leaf]] == 0) {
					queue.add(parent[leaf]);
				}
				if (a[leaf] == b[leaf]) {
					parent[leaf] = -2;
					continue;
				}
				
				int[] curParent = new int[n];
				Queue<Integer> curQueue = new ArrayDeque<>();
				fill(curParent, -1);
				
				curQueue.add(leaf);
				int[] curOut = new int[n];
				curParent[leaf] = leaf;
				while (!curQueue.isEmpty()) {
					int u = curQueue.poll();
					for (int i = 0; i < n; i++) {
						if (!can[u][i]) {
							continue;
						}
						if (parent[i] < 0 || curParent[i] >= 0) {
							continue;
						}
						++curOut[u];
						curParent[i] = u;
						curQueue.add(i);
					}
				}
				
				for (int i = 0; i < n; i++) {
					if (curOut[i] == 0 && curParent[i] >= 0) {
						curQueue.add(i);
					}
				}
				
				while (!curQueue.isEmpty() && a[leaf] != b[leaf]) {
					int x = curQueue.poll();
					int par = curParent[x];
					
					if (a[leaf] < b[leaf]) {
						int flow = min(v - a[par], a[x]);
						if (par == leaf) {
							flow = min(b[leaf] - a[leaf], flow);
						}
						from.add(x);
						to.add(par);
						amount.add(flow);
						a[x] -= flow;
						a[par] += flow;
					} else {
						int flow = min(v - a[x], a[par]);
						if (par == leaf) {
							flow = min(flow, a[leaf] - b[leaf]);
						}
						from.add(par);
						to.add(x);
						amount.add(flow);
						a[par] -= flow;
						a[x] += flow;
					}
					if (--curOut[par] == 0) {
						curQueue.add(par);
					}
				}
//				System.err.println(a[leaf]+"="+b[leaf]);
				parent[leaf] = -2;
			}
			
			
			for (int i = 0; i < n; i++) {
				if (parent[i] >= 0) {
					parent[i] = -2;
				}
			}
		}
//		System.err.println(Arrays.toString(a));
//		System.err.println(Arrays.toString(b));
		if (!good) {
			out.println("NO");
		} else {
			out.println(from.size());
			for (int i = 0; i < from.size(); i++) {
				out.println((from.get(i)+1)+" "+(to.get(i)+1)+" "+amount.get(i));
			}
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