import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt(), a[] = new int[n], b[] = new int[n], c[] = new int[m], d[] = new int[m];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
			b[i] = scanInt();
		}
		int maxC = 0;
		for (int i = 0; i < m; i++) {
			c[i] = scanInt();
			d[i] = scanInt();
			maxC = max(maxC, c[i]);
		}
		int minShift[] = new int[maxC + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] <= c[j] && b[i] <= d[j]) {
					minShift[c[j] - a[i]] = max(minShift[c[j] - a[i]], d[j] - b[i] + 1);
				}
			}
		}
		int ans = maxC + 1;
		int cshift = 0;
		for (int i = maxC; i >= 0; i--) {
			cshift = max(cshift, minShift[i]);
			ans = min(ans, i + cshift);
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