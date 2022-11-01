import java.io.*;
import java.util.*;

public class E implements Runnable {

	class Pair implements Comparable<Pair> {
		int x, c;

		public Pair(int x, int c) {
			this.x = x;
			this.c = c;
		}

		@Override
		public int compareTo(Pair o) {
			if (x != o.x)
				return x - o.x;
			return c - o.c;
		}

	}

	private void solve() throws IOException {
		int n = nextInt();
		Pair[] a = new Pair[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Pair(nextInt(), nextInt());
		}
		Arrays.sort(a);
		long[][] d = new long[n][n];
		d[0][0] = a[0].c;
		for (int i = 1; i < n; i++) {
			long min = Long.MAX_VALUE;
			for (int j = 0; j < i; j++) {
				min = Math.min(min, d[i - 1][j]);
				d[i][j] = d[i - 1][j] + a[i].x - a[j].x;
			}
			d[i][i] = min + a[i].c;
		}

		long ans = Long.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			ans = Math.min(ans, d[n - 1][i]);
		}
		out.println(ans);
	}

	public static void main(String[] args) {
		new Thread(new E()).start();
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