import java.io.*;
import java.util.*;

public class C {

	int n;
	int[][] e;
	int[] p;
	int[] key;
	int[] depth;
	long[] sumError;
	int[] low, high;

	void dfs1(int u) {
		if (e[u].length == 0) {
			low[u] = high[u] = key[u];
		} else {
			int v1 = e[u][0], v2 = e[u][1];
			depth[v1] = depth[v2] = depth[u] + 1;
			for (int v : e[u]) {
				dfs1(v);
			}
			low[u] = low[v1];
			high[u] = high[v2];
		}
	}

	void dfs2(int u) {
		if (e[u].length == 0) {
			return;
		}
		int v1 = e[u][0], v2 = e[u][1];
		sumError[v1] = sumError[u] + low[v2];
		sumError[v2] = sumError[u] + high[v1];
		dfs2(v1);
		dfs2(v2);
	}

	private void solve() throws IOException {
		n = nextInt();
		int[] ecnt = new int[n];
		p = new int[n];
		key = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
			key[i] = nextInt();
			if (p[i] >= 0) {
				ecnt[p[i]]++;
			}
		}
		e = new int[n][];
		for (int i = 0; i < n; i++) {
			e[i] = new int[ecnt[i]];
		}
		Arrays.fill(ecnt, 0);
		int root = -1;
		for (int i = 0; i < n; i++) {
			int par = p[i];
			if (par < 0) {
				root = i;
				continue;
			}
			e[par][ecnt[par]++] = i;
		}
		for (int i = 0; i < n; i++) {
			if (e[i].length == 0)
				continue;
			int u = e[i][0], v = e[i][1];
			if (key[u] > key[v]) {
				e[i][0] = v;
				e[i][1] = u;
			}
		}
		low = new int[n];
		high = new int[n];
		depth = new int[n];
		dfs1(root);
		sumError = new long[n];	
		dfs2(root);
		TreeSet<Integer> allvalues = new TreeSet<Integer>();
		TreeMap<Integer, Integer> leafvalues = new TreeMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			allvalues.add(key[i]);
			if (e[i].length == 0) {
				leafvalues.put(key[i], i);
			}
		}
		int k = nextInt();
		for (int i = 0; i < k; i++) {
			int x = nextInt();
			Integer a = allvalues.lower(x);
			Integer b = allvalues.higher(x);
			int leaf = -1;
			if (a != null && leafvalues.containsKey(a)) {
				leaf = leafvalues.get(a);
			} else {
				leaf = leafvalues.get(b);
			}
			double res = sumError[leaf] * 1. / depth[leaf];
			out.println(res);
		}
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}