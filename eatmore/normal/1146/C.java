import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			int ans = 0;
			for (int bit = 0, bits = 32 - Integer.numberOfLeadingZeros(n - 1); bit < bits; bit++) {
				int c0 = 0, c1 = 0;
				for (int i = 0; i < n; i++) {
					if ((i & (1 << bit)) != 0) {
						++c1;
					} else {
						++c0;
					}
				}
				out.print(c0 + " " + c1);
				for (int i = 0; i < n; i++) {
					if ((i & (1 << bit)) == 0) {
						out.print(" " + (i + 1));
					}
				}
				for (int i = 0; i < n; i++) {
					if ((i & (1 << bit)) != 0) {
						out.print(" " + (i + 1));
					}
				}
				out.println();
				out.flush();
				ans = max(ans, scanInt());
			}
			out.println("-1 " + ans);
			out.flush();
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