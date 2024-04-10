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
		int n = scanInt();
		String s = scanString();
		int a[] = new int[n];
		int b[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
			b[i] = scanInt();
		}
		int ans = 0;
		for (int i = 0; i < 1000; i++) {
			int cans = 0;
			for (int j = 0; j < n; j++) {
				if (i < b[j] ? s.charAt(j) == '1' : (s.charAt(j) == '1') ^ ((((i - b[j]) / a[j]) & 1) == 0)) {
					++cans;
				}
			}
			ans = max(ans, cans);
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