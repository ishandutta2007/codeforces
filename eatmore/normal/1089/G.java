import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

	static void solve() throws Exception {
		int tests = scanInt();
		boolean a[] = new boolean[7];
		for (int test = 0; test < tests; test++) {
			int k = scanInt();
			int cnt = 0;
			for (int i = 0; i < 7; i++) {
				if (a[i] = scanInt() != 0) {
					++cnt;
				}
			}
			int full = (k - 1) / cnt, shift = (k - 1) % cnt;
			int ans = Integer.MAX_VALUE;
			for (int i = 0; i < 7; i++) {
				if (!a[i]) {
					continue;
				}
				int j, sh;
				for (j = (i + 1) % 7, sh = shift; sh > 0; j = (j + 1) % 7) {
					if (a[j]) {
						--sh;
					}
				}
				ans = min(ans, (j - i + 6) % 7 + 1 + 7 * full);
			}
			out.println(ans);
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