import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void solve() throws Exception {
		int n = scanInt();
		int val[] = new int[n];
		long mask[] = new long[n];
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += val[i] = scanInt();
			mask[i] = scanLong();
		}
		int sgn = Long.signum(sum);
		long s = 0;
		for (int bit = 0; bit < 62; bit++) {
			long sum0 = 0, sum1 = 0;
			for (int i = 0; i < n; i++) {
				if (mask[i] >> bit == 0) {
					sum0 += val[i];
				} else if (mask[i] >> bit == 1) {
					sum1 += val[i];
				}
			}
			int sgn0 = Long.signum(sum0 + sum1), sgn1 = Long.signum(sum0 - sum1);
			if (sgn1 * sgn < sgn0 * sgn) {
				s |= 1L << bit;
				for (int i = 0; i < n; i++) {
					if ((mask[i] & (1L << bit)) != 0) {
						val[i] = -val[i];
					}
				}
			}
		}
		out.print(s);
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