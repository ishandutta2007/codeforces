import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void sort(int a[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (ca <= na) {
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
				j += (a[j + 2] > a[j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
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
		int n = scanInt();
		int a[] = new int[n];
		int xor = 0;
		for (int i = 0; i < n; i++) {
			xor ^= a[i] = scanInt();
		}
		sort(a);
		long asum[] = new long[n + 1];
		for (int i = 0; i < n; i++) {
			asum[i + 1] = asum[i] + a[i];
		}
		long min = 0, max = n;
		for (int i = 0, pos = n; i <= n; i++) {
			int cpos = min(i, pos);
			max = min(max, (n - i + 1L) * (n - i) + asum[cpos] + (n - i + 1L) * (i - cpos) - asum[n] + asum[i]);
			while (pos > 0 && a[pos - 1] > n - i) {
				--pos;
			}
			cpos = min(i, pos);
			long cmin = asum[n] - asum[i] - (n - i) * (n - i - 1L) - asum[cpos] - (n - i) * (long) (i - cpos);
			if (cmin > n - i) {
				min = max + 1;
			} else {
				min = max(min, cmin);
			}
		}
		if (((min ^ xor) & 1) != 0) {
			++min;
		}
		if (((max ^ xor) & 1) != 0) {
			--max;
		}
		if (min > max) {
			out.print(-1);
		} else {
			for (long x = min; x <= max; x += 2) {
				out.print(x + " ");
			}
		}
	}

	static int scanInt() throws IOException {
		int c;
		do {
			c = in.read();
			if (c < 0) {
				throw new AssertionError();
			}
		} while (!(c >= '0' && c <= '9'));
		int res = c - '0';
		while ((c = in.read()) >= '0' && c <= '9') {
			res = res * 10 + (c - '0');
		}
		return res;
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