import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = scanInt() - 1;
			}
			int cnts[] = new int[n];
			++cnts[a[0]];
			++cnts[a[n - 1]];
			int ans = 0;
			for (int i = 0; i < n - 1; i++) {
				if (a[i] == a[i + 1]) {
					++ans;
					cnts[a[i]] += 2;
				}
			}
			int cntTotal = 2 * ans + 2;
			int cntMax = 0;
			for (int i = 1; i < n; i++) {
				if (cnts[i] > cnts[cntMax]) {
					cntMax = i;
				}
			}
			int cnt = 0;
			for (int i = 0; i < n - 1; i++) {
				if (a[i] != a[i + 1] && a[i] != cntMax && a[i + 1] != cntMax) {
					++cnt;
				}
			}
			if (cnts[cntMax] > cntTotal / 2 + 1) {
				ans = cnts[cntMax] - (cntTotal / 2 + 1) > cnt ? -1 : ans + cnts[cntMax] - (cntTotal / 2 + 1);
			}
			out.println(ans);
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