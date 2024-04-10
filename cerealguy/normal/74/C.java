import java.io.*;
import java.util.*;

public class C {

	int n, m;
	boolean[] used;

	private void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		--n;
		--m;
		if (n > m) {
			int t = n;
			n = m;
			m = t;
		}
		used = new boolean[n + 1];
		int res = 0;
		for (int i = 0; i < n + 1; i++) {
			if (!used[i]) {
				res++;
				go(i);
			}
		}
		out.println(res);
	}

	int get1(int u) {
		int v = u - 2 * m;
		int r = (v % n + n) % n;
		int block = (v - r) / n;
		if (block % 2 != 0) {
			r = n - r;
		}
		return r;
	}

	int get2(int u) {
		int v = u + 2 * m;
		int r = (v % n + n) % n;
		int block = (v - r) / n;
		if (block % 2 != 0) {
			r = n - r;
		}
		return r;
	}

	void go(int u) {
		if (used[u])
			return;
		used[u] = true;
		go(get1(u));
		go(get2(u));
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