import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		long ta = scanInt(), tb = scanInt();
		int k = scanInt();
		if (k >= n || k >= m) {
			out.print(-1);
			return;
		}
		long a[] = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
		}
		long b[] = new long[m];
		for (int i = 0; i < m; i++) {
			b[i] = scanInt();
		}
		long ans = 0;
		for (int i = 0; i <= k; i++) {
			int p = binarySearch(b, a[i] + ta);
			if (p < 0) {
				p = ~p;
			}
			if (p + k - i >= m) {
				out.print(-1);
				return;
			}
			ans = max(ans, b[p + k - i] + tb);
		}
		out.print(ans);
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