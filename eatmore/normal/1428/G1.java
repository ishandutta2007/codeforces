import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

	static final long inf = Long.MAX_VALUE / 2;

	static void solve() throws Exception {
		int k = scanInt();
		long f[] = new long[6];
		for (int i = 0; i < 6; i++) {
			f[i] = scanLong();
		}
		long dyn[] = new long[1000000], ndyn[] = new long[1000000];
		fill(dyn, 1, 1000000, -inf);
		int p10 = 1;
		int smpos[] = new int[1000000];
		for (int p = 0; p < 6; p++) {
			fill(ndyn, -inf);
			long cf = f[p];
			int s = 3 * p10;
			for (int i = 0; i < 1000000; i++) {
				dyn[i] -= i / s * cf;
			}
			for (int m = 0; m < s; m++) {
				int smhead = 0, smtail = 0;
				for (int i = m; i < 1000000; i += s) {
					while (smtail > smhead && dyn[i] >= dyn[smpos[smtail - 1]]) {
						--smtail;
					}
					smpos[smtail++] = i;
					long v = dyn[smpos[smhead]] + i / s * cf;
					ndyn[i] = max(ndyn[i], v);
					if (i + p10 < 1000000) {
						ndyn[i + p10] = max(ndyn[i + p10], v);
					}
					if (i + 2 * p10 < 1000000) {
						ndyn[i + 2 * p10] = max(ndyn[i + 2 * p10], v);
					}
					if (smpos[smhead] == i - (long) (9 * k - 9) * p10) {
						++smhead;
					}
				}
			}
			for (int i = 0; i < 1000000; i++) {
				for (int ss = 9 * k - 6; ss <= 9 * k; ss++) {
					if (i - (long) ss * p10 >= 0) {
						ndyn[i] = max(ndyn[i], dyn[i - ss * p10] + ((i - ss * p10) / s + (ss % 3 == 0 ? ss / 3 : 3 * k - 3)) * cf);
					}
				}
			}
			p10 *= 10;
			long t[] = dyn;
			dyn = ndyn;
			ndyn = t;
		}
		int q = scanInt();
		for (int qq = 0; qq < q; qq++) {
			out.println(dyn[scanInt()]);
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