import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static void solve() throws Exception {
		long la = scanInt(), ra = scanInt() + 1, ta = scanInt();
		long lb = scanInt(), rb = scanInt() + 1, tb = scanInt();
		long gcd = gcd(ta, tb);
		long shift = ((lb - la) % gcd + gcd) % gcd;
		long sa = ra - la, sb = rb - lb;
		long ans = min(sa, sb + shift) - max(0, shift);
		shift -= gcd;
		ans = max(ans, min(sa, sb + shift) - max(0, shift));
		ans = max(ans, 0);
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