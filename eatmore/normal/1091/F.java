import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void solve() throws Exception {
		int n = scanInt();
		long l[] = new long[n];
		for (int i = 0; i < n; i++) {
			l[i] = scanLong();
		}
		long e1 = 0, e2 = 0, ans = 0;
		boolean water = false;
		String types = scanString();
		for (int i = 0; i < n; i++) {
			long li = l[i], cur;
			switch (types.charAt(i)) {
			case 'G':
				cur = min(e1, li);
				e1 -= cur;
				li -= cur;
				e2 += 2 * cur;
				ans += 2 * cur;
				e2 += li;
				ans += 3 * li;
				break;
			case 'W':
				water = true;
				e1 += li;
				ans += 2 * li;
				break;
			case 'L':
				cur = min(e1, li);
				e1 -= cur;
				li -= cur;
				ans += 2 * cur;
				cur = min(e2, li);
				e2 -= cur;
				li -= cur;
				ans += 3 * cur;
				ans += (water ? 4 : 6) * li;
				break;
			default:
				throw new AssertionError();
			}
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