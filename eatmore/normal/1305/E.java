import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		int a[] = new int[n];
		int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			if (m >= i / 2) {
				a[i] = i + 1;
				m -= i / 2;
			} else if (x == 0) {
				x = 2 * i - 2 * m;
				a[i] = x + 1;
				m = 0;
				y = 2 * x;
			} else {
				a[i] = y + 1;
				y += x;
			}
		}
		if (m != 0) {
			out.print(-1);
		} else {
			for (int i = 0; i < n; i++) {
				out.print(a[i] + " ");
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