import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int n = nextInt();
		int edges = nextInt();
		int[] deg = new int[n];
		for (int i = 0; i < edges; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			++deg[u];
			++deg[v];
		}
		Arrays.sort(deg);
		if (deg[0] == 2 && deg[n - 1] == 2) {
			out.println("ring topology");
		} else {
			if (deg[0] == 1 && deg[1] == 1 && deg[2] == 2 && deg[n - 1] == 2) {
				out.println("bus topology");
			} else {
				if (deg[n - 1] == n - 1 && deg[n - 2] == 1) {
					out.println("star topology");
				} else {
					out.println("unknown topology");
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