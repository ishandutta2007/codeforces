import java.io.*;
import java.util.*;

public class D implements Runnable {
	ArrayList<Integer> e[];
	int[] p;

	void dfs(int u) {
		for (int v : e[u]) {
			if (p[v] == -2) {
				p[v] = u;
				dfs(v);
			}
		}
	}

	private void solve() throws IOException {
		int n = nextInt();
		e = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<Integer>();
		}
		int r1 = nextInt() - 1, r2 = nextInt() - 1;
		int[] p0 = new int[n];
		for (int i = 0; i < n; i++) {
			if (i == r1)
				p0[i] = -1;
			else {
				p0[i] = nextInt() - 1;
				e[p0[i]].add(i);
				e[i].add(p0[i]);
			}
		}
		p = new int[n];
		Arrays.fill(p, -2);
		p[r2] = -1;
		dfs(r2);
		for (int i = 0; i < n; i++) {
			if (i != r2)
				out.print((p[i] + 1) + " ");
		}
	}

	public static void main(String[] args) {
		new Thread(new D()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
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

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}