import java.io.*;
import java.util.*;

public class D {

	@SuppressWarnings("unchecked")
	private static void solve() throws IOException {
		n = nextInt();
		k = nextInt();
		e = new List[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			e[u].add(v);
			e[v].add(u);
		}
		answer = 0;
		dfs(0, -1);
		out.println(answer);
	}

	static int[] dfs(int u, int p) {
		int[] d = new int[k];
		d[0] = 1;
		for (int v : e[u]) {
			if (v == p) {
				continue;
			}
			int[] cur = dfs(v, u);
			for (int i = k - 1; i >= 0; --i) {
				answer += (long) cur[i] * d[k - 1 - i];
			}
			for (int i = k - 2; i >= 0; --i) {
				d[i + 1] += cur[i];
			}
		}
		return d;
	}

	static long answer;
	static int k;
	static int n;
	static List<Integer>[] e;

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