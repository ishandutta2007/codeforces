import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int tests = scanInt();
		test: for (int test = 0; test < tests; test++) {
			int n = scanInt();
			String s = scanString();
			char ans[] = new char[n];
			start: for (int start = 0; start < 10; start++) {
				int cur1 = 0, cur2 = start;
				for (int i = 0; i < n; i++) {
					int c = s.charAt(i) - '0';
					if (c >= cur2) {
						ans[i] = '2';
						cur2 = c;
					} else if (c >= cur1 && c <= start) {
						ans[i] = '1';
						cur1 = c;
					} else {
						continue start;
					}
				}
				out.println(ans);
				continue test;
			}
			out.println('-');
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