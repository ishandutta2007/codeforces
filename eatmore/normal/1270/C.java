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
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			long sum = 0, xor = 0;
			for (int i = 0; i < n; i++) {
				long a = scanLong();
				sum += a;
				xor ^= a;
			}
			out.println(3);
			if ((sum & 1) != 0) {
				out.print((1L << 59) + 1);
				sum += (1L << 59) + 1;
				xor ^= (1L << 59) + 1;
			} else {
				out.print(1L << 59);
				sum += 1L << 59;
				xor ^= 1L << 59;
			}
			out.print(" " + (2 * xor - sum) / 2);
			out.println(" " + (2 * xor - sum) / 2);
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