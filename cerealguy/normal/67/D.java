import java.io.*;
import java.util.*;

public class D {

	int n;
	int[] x, y;
	int[] a;

	private void solve() throws IOException {
		n = nextInt();
		x = new int[n];
		y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt() - 1;
		}
		int[] start = new int[n];
		for (int i = 0; i < n; i++) {
			start[x[i]] = i;
		}
		a = new int[n];
		for (int i = 0; i < n; i++) {
			y[i] = nextInt() - 1;
			a[start[y[i]]] = i;
		}
		int res = get();
		out.println(res);
	}

	final int INF = Integer.MAX_VALUE;

	int get() {
		int[] d = new int[n + 1];
		Arrays.fill(d, -INF);
		d[0] = INF;
		for (int i = 0; i < n; i++) {
			int l = -1, r = i + 1;
			while (r - l > 1) {
				int m = (r + l) / 2;
				if (d[m] > a[i]) {
					l = m;
				} else {
					r = m;
				}
			}
			if (l == -1)
				continue;
			if (d[r] < a[i]) {
				d[r] = a[i];
			}
		}
		for (int i = n; i >= 0; i--) {
			if (d[i] != -INF)
				return i;
		}
		return -1;
	}

	public static void main(String[] args) {
		new D().run();
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