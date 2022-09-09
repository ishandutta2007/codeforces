import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		scanInt();
		int k = scanInt();
		int v1 = -1, cnt1 = 0, v2 = -1, cnt2 = 0;
		for (int i = 0; i < k + 1; i++) {
			out.print('?');
			for (int j = 0; j < k + 1; j++) {
				if (j != i) {
					out.print(" " + (j + 1));
				}
			}
			out.println();
			out.flush();
			scanInt();
			int v = scanInt();
			if (cnt1 == 0) {
				v1 = v;
				cnt1 = 1;
			} else if (v == v1) {
				++cnt1;
			} else if (cnt2 == 0) {
				v2 = v;
				cnt2 = 1;
			} else if (v == v2) {
				++cnt2;
			} else {
				throw new AssertionError();
			}
		}
		out.println("! " + (v1 < v2 ? cnt2 : cnt1));
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