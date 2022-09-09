import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int n = scanInt();
		int m = scanInt();
		long l = scanInt();
		long a[] = new long[n + 2];
		for (int i = 0; i < n; i++) {
			a[i + 1] = scanInt();
		}
		int cnt = 0;
		for (int i = 0; i <= n; i++) {
			if ((a[i] > l) != (a[i + 1] > l)) {
				++cnt;
			}
		}
		for (int qq = 0; qq < m; qq++) {
			if (scanInt() == 0) {
				out.println(cnt >> 1);
			} else {
				int p = scanInt() - 1;
				long d = scanInt();
				if ((a[p] > l) != (a[p + 1] > l)) {
					--cnt;
				}
				if ((a[p + 1] > l) != (a[p + 2] > l)) {
					--cnt;
				}
				a[p + 1] += d;
				if ((a[p] > l) != (a[p + 1] > l)) {
					++cnt;
				}
				if ((a[p + 1] > l) != (a[p + 2] > l)) {
					++cnt;
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