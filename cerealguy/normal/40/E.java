import java.io.*;
import java.util.*;

public class E implements Runnable {

	static class Pair implements Comparable<Pair> {
		int a, b;

		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Pair o) {
			if (a != o.a)
				return a - o.a;
			return b - o.b;
		}
	}

	static class Triple implements Comparable<Triple> {
		Pair a;
		int b;

		public Triple(Pair a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Triple o) {
			return a.compareTo(o.a);
		}

	}

	int p;

	int modPow(int a, int pow, int mod) {
		int res = 1;
		while (pow > 0) {
			if ((pow & 1) != 0) {
				res = (int) ((long) res * a % mod);
			}
			a = (int) ((long) a * a % mod);
			pow >>= 1;
		}
		return res;
	}

	private void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		if ((n + m) % 2 == 1) {
			out.println(0);
			return;
		}
		int k = nextInt();
		Triple[] a = new Triple[k];
		for (int i = 0; i < k; i++) {
			a[i] = new Triple(new Pair(nextInt() - 1, nextInt() - 1), nextInt());
		}
		if (n < m) {
			int t = n;
			n = m;
			m = t;
			for (int i = 0; i < k; i++) {
				t = a[i].a.a;
				a[i].a.a = a[i].a.b;
				a[i].a.b = t;
			}
		}
		int[][] x = new int[n][m];
		for (int i = 0; i < k; i++) {
			x[a[i].a.a][a[i].a.b] = a[i].b;
		}
		for (int i = 0; i < n; i++) {
			boolean ok = true;
			for (int j = 0; j < m; j++) {
				if (x[i][j] != 0) {
					ok = false;
					break;
				}
			}
			if (ok) {
				int[] tmp = x[i];
				x[i] = x[0];
				x[0] = tmp;
				break;
			}
		}
		p = nextInt();
		int res = 1;
		for (int i = 1; i < n; i++) {
			int cnt = 0;
			int p1 = 1;
			for (int j = 0; j < m; j++) {
				if (x[i][j] == 0)
					cnt++;
				else
					p1 *= x[i][j];
			}
			if (cnt == 0 && p1 == 1) {
				out.println(0);
				return;
			}
			if (cnt > 0)
				res = mul(res, modPow(2, cnt - 1, p), p);
		}

		out.println(res);
	}

	int mul(int a, int b, int p) {
		return (int) ((long) a * b % p);
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