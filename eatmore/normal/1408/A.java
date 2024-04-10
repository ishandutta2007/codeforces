import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[][] = new int[3][n];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = scanInt();
				}
			}
			int p[] = new int[n];
			for (int i = 0; i < n; i++) {
				for (int j = 0;; j++) {
					if (a[j][i] != p[(i + 1) % n] && a[j][i] != p[(i + n - 1) % n]) {
						out.print((p[i] = a[j][i]) + " ");
						break;
					}
				}
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