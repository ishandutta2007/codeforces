import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int q = scanInt();
		q: for (int qq = 0; qq < q; qq++) {
			int a = scanInt();
			if ((a & (a + 1)) == 0) {
				for (int i = 2; i * i <= a; i++) {
					if (a % i == 0) {
						out.println(a / i);
						continue q;
					}
				}
				out.println(1);
			} else {
				out.println((Integer.highestOneBit(a) << 1) - 1);
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