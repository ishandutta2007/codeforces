import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int n = scanInt();
		int i = 0, j = 0;
		boolean seen[] = new boolean[8];
		int t = 1;
		int l = 8;
		for (; n > 0; --n) {
			out.print("" + (char) (j + 'a') + (i + 1) + " ");
			seen[j] = true;
			--l;
			if (i != 7) {
				if (n == 2) {
					i = 7;
					fill(seen, false);
					l = 8;
					continue;
				}
			}
			if (l > 1) {
				for (int ii = 0;; ii++) {
					if (ii != t && !seen[ii]) {
						j = ii;
						break;
					}
				}
			} else if (l == 1) {
				j = t;
			} else {
				++i;
				fill(seen, false);
				l = 8;
				if (i == 7) {
					t = 7;
				} else {
					t = t == 0 ? 1 : 0;
				}
			}
			if (i != 7 && n == 3 && j == 7) {
				j = t;
			}
		}
		out.print("h8");
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