import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
		int n = nextInt(), edges = nextInt(), k = nextInt();
		List<Integer>[] e = new List[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<>();
		}
		for (int i = 0; i < edges; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			e[u].add(v);
			e[v].add(u);
		}
		List<Integer> list = new ArrayList<>();
		int[] time = new int[n];
		fill(time, -1);
		int u = 0;
		go: for (int it = 0;; it++) {
			for (int v : e[u]) {
				if (time[v] < 0) {
					time[v] = it;
					list.add(v);
					u = v;
					continue go;
				}
				if (time[u] - time[v] >= k) {
					list.subList(0, time[v]).clear();
					break go;
				}
			}
			throw new AssertionError();
		}
		out.println(list.size());
		for (int i = 0; i < list.size(); i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(list.get(i) + 1);
		}
		out.println();
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
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