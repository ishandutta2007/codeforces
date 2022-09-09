import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), cnt[] = new int[n], pos[] = new int[n];
			for (int i = 0; i < n; i++) {
				int a = scanInt() - 1;
				++cnt[a];
				pos[a] = i;
			}
			boolean ans[] = new boolean[n];
			int x = 0, y = n - 1;
			for (int i = 0; i < n; i++) {
				if (cnt[i] == 0) {
					break;
				}
				ans[n - i - 1] = true;
				if (cnt[i] > 1 || (pos[i] != x && pos[i] != y)) {
					break;
				}
				if (pos[i] == x) {
					++x;
				} else {
					--y;
				}
			}
			for (int i = 0;; i++) {
				if (i == n) {
					ans[0] = true;
					break;
				}
				if (cnt[i] == 0) {
					break;
				}
			}
			for (int i = 0; i < n; i++) {
				out.print(ans[i] ? '1' : '0');
			}
			out.println();
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