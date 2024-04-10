import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void sortBy(int a[], long v[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			long cv = v[ca];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cv <= v[na]) {
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
				j += (v[a[j + 2]] > v[a[j + 1]]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			long cv = v[ca];
			while (j != 0 && v[a[j]] < cv) {
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
		int m = scanInt();
		long x[] = new long[n];
		long ymx[] = new long[n];
		int order[] = new int[n];
		long sumx = 0;
		for (int i = 0; i < n; i++) {
			x[i] = scanInt();
			ymx[i] = scanInt() - x[i];
			order[i] = i;
			sumx += x[i];
		}
		sortBy(order, ymx);
		long ans[] = new long[n];
		long sumymx = 0;
		for (int i = 0; i < n; i++) {
			int ii = order[i];
			ans[ii] = x[ii] * (n - 2) + sumx + ymx[ii] * (n - i - 1) + sumymx;
			sumymx += ymx[ii];
		}
		for (int i = 0; i < m; i++) {
			int u = scanInt() - 1, v = scanInt() - 1;
			long cans = x[u] + x[v] + min(ymx[u], ymx[v]);
			ans[u] -= cans;
			ans[v] -= cans;
		}
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
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