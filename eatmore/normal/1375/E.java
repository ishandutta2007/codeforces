import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void sort(long a[], int n) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			long ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				long na = a[nj];
				if (ca <= na) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		long ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (a[j + 2] > a[j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			long na = a[i];
			a[i] = ca;
			ca = na;
			while (j != 0 && a[j] < ca) {
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
		int n = scanInt(), m = 0;
		long a[] = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = (long) n * scanInt() + i;
			for (int j = 0; j < i; j++) {
				if (a[j] > a[i]) {
					++m;
				}
			}
		}
		long sa[] = a.clone();
		sort(sa, n);
		int pos[] = new int[n];
		for (int i = 0; i < n; i++) {
			pos[binarySearch(sa, a[i])] = i;
		}
		out.println(m);
		for (int i = n - 1; i >= 0; i--) {
			while (pos[i] != i) {
				int p = binarySearch(sa, a[i]);
				int j = pos[p + 1];
				out.println((j + 1) + " " + (i + 1));
				long t = a[i];
				a[i] = a[j];
				a[j] = t;
				pos[p] = j;
				pos[p + 1] = i;
			}
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