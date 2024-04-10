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
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt();
			boolean good = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					int a = scanInt();
					if (a > (i > 0 ? 1 : 0) + (i < n - 1 ? 1 : 0) + (j > 0 ? 1 : 0) + (j < m - 1 ? 1 : 0)) {
						good = false;
					}
				}
			}
			if (good) {
				out.println("YES");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						out.print(((i > 0 ? 1 : 0) + (i < n - 1 ? 1 : 0) + (j > 0 ? 1 : 0) + (j < m - 1 ? 1 : 0)) + " ");
					}
					out.println();
				}
			} else {
				out.println("NO");
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