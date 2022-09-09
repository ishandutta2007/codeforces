import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static void solve() throws Exception {
		int m = scanInt() + 1, a = scanInt(), b = scanInt();
		int cnt[] = new int[a + b];
		for (int i = 0, j = 0;;) {
			++cnt[j];
			if (i >= b) {
				i -= b;
			} else {
				i += a;
			}
			if (i == 0) {
				break;
			}
			j = max(j, i);
		}
		for (int i = 1; i < a + b; i++) {
			cnt[i] += cnt[i - 1];
		}
		long ans = 0;
		for (int i = 0; i < a + b && i < m; i++) {
			ans += cnt[i];
		}
		if (m > a + b) {
			int g = gcd(a, b);
			int from = (a + b) / g, to = m / g;
			ans += (long) (from + to + 1) * (to - from) / 2 * g;
			ans += (long) (m % g) * (to + 1);
		}
		out.print(ans);
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