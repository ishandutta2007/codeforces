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
		int n = scanInt() / 2;
//		int n = 100000;
		long ans[] = new long[2 * n];
		long cur = 0;
		for (int i = 0; i < n; i++) {
			long x = scanInt();
//			long x = 200000;
			long next = -1;
			for (long d = 1; d * d < x; d++) {
				if (x % d != 0 || (d + x / d) % 2 != 0) {
					continue;
				}
				if ((x / d - d) / 2 > cur) {
					next = (d + x / d) / 2;
				}
			}
			if (next < 0) {
				out.print("No");
				return;
			}
			ans[2 * i] = next * next - cur * cur - x;
			ans[2 * i + 1] = x;
			cur = next;
		}
		out.println("Yes");
		for (int i = 0; i < 2 * n; i++) {
			out.print(ans[i] + " ");
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