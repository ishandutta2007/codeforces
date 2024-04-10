import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), l = scanInt(), a[] = new int[n + 2];
			a[n + 1] = l;
			for (int i = 0; i < n; i++) {
				a[i + 1] = scanInt();
			}
			double t1 = 0, t2 = 0;
			int i1 = 0, i2 = n + 1;
			while (true) {
				int s1 = i1 + 1, s2 = n + 2 - i2;
				double tMeet = (a[i2] + t1 * s1 + s2 * t2 - a[i1]) / (s1 + s2);
				double tNext1 = i1 < n + 1 ? t1 + (double) (a[i1 + 1] - a[i1]) / s1 : Double.POSITIVE_INFINITY;
				double tNext2 = i2 > 0 ? t2 + (double) (a[i2] - a[i2 - 1]) / s2 : Double.POSITIVE_INFINITY;
				if (tMeet <= tNext1 && tMeet <= tNext2) {
					out.printf(Locale.US, "%.12f\n", tMeet);
					break;
				} else if (tNext1 <= tNext2) {
					t1 = tNext1;
					++i1;
				} else {
					t2 = tNext2;
					--i2;
				}
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