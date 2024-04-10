import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int n = scanInt(), a[] = new int[n], b[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[scanInt() - 1] = i;
		}
		for (int i = 0; i < n; i++) {
			b[scanInt() - 1] = i;
		}
		int p[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[a[i]] = b[i];
		}
		int max = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			max = max(max, p[i]);
			if (max > p[i]) {
				++ans;
			}
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