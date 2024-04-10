import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class H1 {

	static int solve(int n, int m, String pl, String pr, String pu, String pd) {
		int cr = 0, cb = 0;
		for (int i = 0; i < n; i++) {
			if (pl.charAt(i) == 'B') {
				++cr;
			} else {
				++cb;
			}
		}
		for (int i = 0; i < m; i++) {
			if (pu.charAt(i) == 'B') {
				++cr;
			} else {
				++cb;
			}
			if (pd.charAt(i) == 'B') {
				++cr;
			} else {
				++cb;
			}
			cr = min(cr, cb + n);
			cb = min(cb, cr + n);
		}
		for (int i = 0; i < n; i++) {
			if (pr.charAt(i) == 'B') {
				++cr;
			} else {
				++cb;
			}
		}
		return min(cr, cb);
	}

	static void solve() throws Exception {
		int n = scanInt();
		int m = scanInt();
		scanInt();
		String pl = scanString(), pr = scanString(), pu = scanString(), pd = scanString();
		out.print(min(solve(n, m, pl, pr, pu, pd), solve(m, n, pu, pd, pl, pr)));
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