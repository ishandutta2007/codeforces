import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	interface IntComparator {
		public int compare(int o1, int o2);
	}

	static void sort(int a[], int n, IntComparator cmp) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cmp.compare(na, ca) >= 0) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (cmp.compare(a[j + 1], a[j + 2]) < 0) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			while (j != 0 && cmp.compare(a[j], ca) < 0) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static void solve() throws Exception {
		int n = scanInt();
		final int x[] = new int[n], y[] = new int[n], z[] = new int[n];
		int idx[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = scanInt();
			y[i] = scanInt();
			z[i] = scanInt();
			idx[i] = i;
		}
		sort(idx, n, new IntComparator() {
			public int compare(int o1, int o2) {
				return x[o1] != x[o2] ? x[o1] - x[o2] : y[o1] != y[o2] ? y[o1] - y[o2] : z[o1] - z[o2];
			}
		});
		boolean taken[] = new boolean[n];
		for (int ii = 0, i, jj, j; ii < n; ii++) {
			if (taken[i = idx[ii]]) {
				continue;
			}
			taken[i] = true;
			for (jj = ii + 1;; jj++) {
				if (!taken[j = idx[jj]]) {
					break;
				}
			}
			if (x[i] != x[j]) {
				int yi = y[i], zi = z[i], xj = x[j], zd = abs(y[j] - yi) + abs(z[j] - zi);
				for (++jj; jj < n; jj++) {
					int j2 = idx[jj], zt;
					if (x[j2] != xj) {
						break;
					}
					if (!taken[j2] && (zt = abs(y[j2] - yi) + abs(z[j2] - zi)) < zd) {
						j = j2;
						zd = zt;
					}
				}
			} else if (y[i] != y[j]) {
				int zi = z[i], zd = abs(z[j] - z[i]), xj = x[j], yj = y[j];
				for (++jj; jj < n; jj++) {
					int j2 = idx[jj], zt;
					if (x[j2] != xj || y[j2] != yj) {
						break;
					}
					if (!taken[j2] && (zt = abs(z[j2] - zi)) < zd) {
						j = j2;
						zd = zt;
					}
				}
			}
			taken[j] = true;
			out.println((i + 1) + " " + (j + 1));
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}