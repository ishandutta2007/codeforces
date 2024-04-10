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

public class F {

	static void solve() throws Exception {
		long a[] = {scanInt(), scanInt(), scanInt()};
		out.println("First");
		long min = min(min(a[0], a[1]), a[2]);
		long max = max(max(a[0], a[1]), a[2]);
		long y = max - min;
		out.println(y);
		out.flush();
		int i = scanInt() - 1;
		if (i < 0) {
			return;
		}
		a[i] += y;
		long sum = a[0] + a[1] + a[2];
		y = 3 * a[i] - sum;
		out.println(y);
		out.flush();
		i = scanInt() - 1;
		if (i < 0) {
			return;
		}
		a[i] += y;
		y = min(a[i] - a[(i + 1) % 3], a[i] - a[(i + 2) % 3]);
		out.println(y);
		out.flush();
		i = scanInt() - 1;
		if (i < 0) {
			return;
		}
		throw new AssertionError();
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