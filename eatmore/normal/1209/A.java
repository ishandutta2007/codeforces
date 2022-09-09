import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int n = scanInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
		}
		sort(a);
		int ans = 0;
		ans: while (true) {
			for (int i = 0;; i++) {
				if (i == n) {
					break ans;
				}
				if (a[i] != 0) {
					++ans;
					int t = a[i];
					a[i] = 0;
					for (i++; i < n; i++) {
						if (a[i] % t == 0) {
							a[i] = 0;
						}
					}
					break;
				}
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