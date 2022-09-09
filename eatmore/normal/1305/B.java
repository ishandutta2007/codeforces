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
		String s = scanString();
		int n = s.length();
		int a[] = new int[n / 2], b[] = new int[n / 2], c = 0;
		for (int i = 0, j = n - 1; i < j; ++i, --j) {
			while (i < j && s.charAt(i) == ')') {
				++i;
			}
			while (i < j && s.charAt(j) == '(') {
				--j;
			}
			if (i < j) {
				a[c] = i;
				b[c] = j;
				++c;
			}
		}
		if (c == 0) {
			out.print(0);
		} else {
			out.println(1);
			out.println(2 * c);
			for (int i = 0; i < c; i++) {
				out.print((a[i] + 1) + " ");
			}
			for (int i = c - 1; i >= 0; i--) {
				out.print((b[i] + 1) + " ");
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