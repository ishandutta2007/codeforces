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
		int n = scanInt();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				out.print(((i & 1) == 0 ? 0 : (1L << (i + j - 1))) + " ");
			}
			out.println();
		}
		out.flush();
		int q = scanInt();
		for (int qq = 0; qq < q; qq++) {
			long k = scanLong();
			out.println("1 1");
			for (int i = 0, j = 0; i + j < 2 * n - 2; ) {
				if (((k & (1L << (i + j))) != 0) ^ ((i & 1) != 0)) {
					++i;
				} else {
					++j;
				}
				out.println((i + 1) + " " + (j + 1));
			}
			out.flush();
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