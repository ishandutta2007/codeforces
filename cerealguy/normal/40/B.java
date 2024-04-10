import java.io.*;
import java.util.*;

public class B implements Runnable {

	private void solve() throws IOException {
		// for (int i = 1; i < 12; i++) {
		// for (int j = 1; j < 25; j++) {
		// for (int xx = 1; xx < 105; xx++) {
		// int a1 = get(i, j, xx);
		// int a2 = stupid(i, j, xx);
		// if (a1 != a2)
		// System.out.println(i + " " + j + " " + xx + " " + a1
		// + " " + a2);
		// }
		// }
		// }
		int n = nextInt(), m = nextInt(), x = nextInt();
		// System.out.println(stupid(n, m, x));
		out.println(get(n, m, x));
	}

	int get(int n, int m, int x) {
		if (x > m + n) {
			return (0);
		}
		n -= 2 * (x - 1);
		m -= 2 * (x - 1);
		boolean cornerblack = true;
		if (n <= 0 || m <= 0) {
			return (0);
		}
		return get1(n, m, cornerblack) - get1(n - 2, m - 2, cornerblack);
	}

	int stupid(int n, int m, int x) {
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2 == 0)
					a[i][j] = 0;
				else
					a[i][j] = -1;
			}
		}
		for (int it = 0; it < n + m; it++) {
			int[][] b = new int[n][];
			for (int i = 0; i < n; i++) {
				b[i] = a[i].clone();
			}
			for (int j = 1; j < n - 1; j++) {
				for (int k = 1; k < m - 1; k++) {
					if ((j + k) % 2 == 1) {
						continue;
					}
					if (a[j - 1][k - 1] == it && a[j - 1][k + 1] == it
							&& a[j + 1][k - 1] == it && a[j + 1][k + 1] == it) {
						b[j][k] = it + 1;
					} else {
						b[j][k] = a[j][k];
					}
				}
			}
			a = b;
		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == x - 1)
					ret++;
			}
		}
		return ret;
	}

	int get1(int n, int m, boolean cornerblack) {
		if (n <= 0 || m <= 0) {
			return 0;
		}
		if (n % 2 == 0 || m % 2 == 0)
			return m * n / 2;
		int ret = m * n / 2;
		if (cornerblack)
			ret++;
		return ret;
	}

	public static void main(String[] args) {
		new Thread(new B()).start();
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