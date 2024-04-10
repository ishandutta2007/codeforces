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
		int x[] = new int[n], y[] = new int[n];
		int bits1 = 0, bits2 = 0;
		for (int i = 0; i < n; i++) {
			x[i] = scanInt();
			y[i] = scanInt();
			bits1 |= (x[i] ^ x[0]) | (y[i] ^ y[0]);
			bits2 |= x[i] ^ y[i] ^ x[0] ^ y[0];
		}
		int ans[] = new int[n], ansCnt = 0;
		int l = Integer.lowestOneBit(bits1);
		if ((bits2 & l) != 0) {
			for (int i = 0; i < n; i++) {
				if (((x[i] ^ y[i]) & l) == 0) {
					ans[ansCnt++] = i;
				}
			}
		} else {
			for (int i = 0; i < n; i++) {
				if ((x[i] & l) == 0) {
					ans[ansCnt++] = i;
				}
			}
		}
		out.println(ansCnt);
		for (int i = 0; i < ansCnt; i++) {
			out.print((ans[i] + 1) + " ");
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