import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int n = scanInt();
		int c[] = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = scanInt();
		}
		int a;
		if (c[0] != c[n - 1]) {
			a = n - 1;
		} else {
			a = 0;
			for (int i = 1; i < n - 1; i++) {
				if (c[i] != c[0]) {
					a = max(a, max(i, n - i - 1));
				}
			}
		}
		out.print(a);
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