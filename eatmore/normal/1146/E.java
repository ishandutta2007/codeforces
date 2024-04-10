import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int n = scanInt();
		int q = scanInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
		}
		int vals[] = new int[q];
		boolean sign[] = new boolean[q];
		int cnt = 0;
		boolean inv = false;
		for (int qq = 0; qq < q; qq++) {
			boolean gt = scanString().charAt(0) == '>';
			int x = scanInt();
			if (gt) {
				if (x < 0) {
					inv = !inv;
					x = -x - 1;
				}
				++x;
			} else {
				if (x > 0) {
					inv = !inv;
				} else {
					x = -x + 1;
				}
			}
			while (cnt > 0 && vals[cnt - 1] >= x) {
				--cnt;
			}
			vals[cnt] = x;
			sign[cnt] = gt ^ inv;
			++cnt;
		}
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				out.print(' ');
			}
			int c = a[i];
			int p = binarySearch(vals, 0, cnt, abs(c));
			if (p < 0) {
				p = ~p - 1;
			}
			if ((p >= 0 && (c < 0) != sign[p]) ^ inv) {
				c = -c;
			}
			out.print(c);
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