import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static void solve() throws Exception {
		int r = scanInt(), c = scanInt();
		if (r == 1 && c == 1) {
			out.print(0);
		} else if (c == 1) {
			for (int i = 0; i < r; i++) {
				out.println(i + 2);
			}
		} else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					out.print(((i + 1) / gcd(i + 1, j + r + 1) * (j + r + 1)) + " ");
				}
				out.println();
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