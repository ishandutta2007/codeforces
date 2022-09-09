import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void sort(long a[]) {
		int n = a.length;
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
		int n = scanInt();
		long k = scanLong() - 1;
		long a[] = new long[n];
		for (int i = 1; i < n; i++) {
			a[i] = a[scanInt() - 1] ^ scanLong();
		}
		sort(a);
		long a2[] = a.clone();
		long tmp[] = new long[n];
		long prefix = 0;
		for (int bit = 61; bit >= 0; bit--) {
			long mask = (1L << 62) - (1L << bit);
			long cnt = 0;
			for (int i = 0, j, pos = 0; i < n; i = j) {
				long creq = a2[i] & mask;
				for (j = i + 1; j < n && (a2[j] & mask) == creq; j++) { }
				creq ^= prefix;
				long ccnt = j - i;
				for (; pos < n && a[pos] < creq; pos++) { }
				for (; pos < n && (a[pos] & mask) == creq; pos++) {
					cnt += ccnt;
				}
			}
			if (k >= cnt) {
				k -= cnt;
				long bb = 1L << bit;
				prefix |= bb;
				for (int i = 0, i2, i3; i < n;) {
					long v = a2[i] & mask;
					if ((v & bb) != 0) {
						++i;
						continue;
					}
					for (i2 = i + 1; i2 < n && (a2[i2] & mask) == v; i2++) { }
					long vv = v ^ bb;
					for (i3 = i2; i3 < n && (a2[i3] & mask) == vv; i3++) { }
					if (i3 == i2) {
						i = i2;
						continue;
					}
					arraycopy(a2, i, tmp, 0, i2 - i);
					arraycopy(a2, i2, a2, i, i3 - i2);
					arraycopy(tmp, 0, a2, i + i3 - i2, i2 - i);
					i = i3;
				}
			}
		}
		out.print(prefix);
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