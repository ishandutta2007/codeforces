import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.lang.System.nanoTime;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	static void sortBy(int a[], int n, int v[]) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			int cv = v[ca];
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
			int cv = v[ca];
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
		int pa[] = new int[2 * n], pb[] = new int[2 * n], idxa[] = new int[2 * n], idxb[] = new int[2 * n];
		for (int i = 0; i < n; i++) {
			pa[2 * i] = 2 * scanInt();
			pa[2 * i + 1] = 2 * scanInt() + 1;
			pb[2 * i] = 2 * scanInt();
			pb[2 * i + 1] = 2 * scanInt() + 1;
			idxa[2 * i] = idxb[2 * i] = 2 * i;
			idxa[2 * i + 1] = idxb[2 * i + 1] = 2 * i + 1;
		}
		sortBy(idxa, 2 * n, pa);
		sortBy(idxb, 2 * n, pb);
		Random rng = new Random(nanoTime());
		long v[] = new long[n];
		for (int i = 0; i < n; i++) {
			v[i] = rng.nextLong() | 1;
		}
		long ans = 0, cur = 0;
		for (int i: idxa) {
			if ((i & 1) == 0) {
				ans += v[i >> 1] * cur;
				cur += v[i >> 1];
			} else {
				cur -= v[i >> 1];
			}
		}
		for (int i: idxb) {
			if ((i & 1) == 0) {
				ans -= v[i >> 1] * cur;
				cur += v[i >> 1];
			} else {
				cur -= v[i >> 1];
			}
		}
		out.print(ans == 0 ? "YES" : "NO");
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