import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C1 {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			char c[][] = new char[n][];
			for (int i = 0; i < n; i++) {
				c[i] = scanString().toCharArray();
			}
			int cnt[] = new int[3];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (c[i][j] != '.') {
						++cnt[(i + j) % 3];
					}
				}
			}
			int min = 0;
			for (int i = 1; i < 3; i++) {
				if (cnt[i] < cnt[min]) {
					min = i;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if ((i + j) % 3 == min && c[i][j] == 'X') {
						c[i][j] = 'O';
					}
				}
			}
			for (int i = 0; i < n; i++) {
				out.println(c[i]);
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