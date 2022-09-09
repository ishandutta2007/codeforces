import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static int n, m, a[], b[], color[], cnt;
	static boolean have[][];

	static void solve() throws Exception {
		n = scanInt();
		m = scanInt();
		a = new int[m];
		b = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = scanInt() - 1;
			b[i] = scanInt() - 1;
		}
		color = new int[n];
		cnt = 0;
		have = new boolean[6][6];
		out.print(go(0));
	}

	static int go(int cur) {
		if (cur == n) {
			int res = 0;
			for (int i = 0; i < m; i++) {
				int ca = color[a[i]], cb = color[b[i]];
				if (!have[ca][cb]) {
					have[ca][cb] = have[cb][ca] = true;
					++res;
				}
			}
			for (int i = 0; i < m; i++) {
				int ca = color[a[i]], cb = color[b[i]];
				have[ca][cb] = have[cb][ca] = false;
			}
			return res;
		}
		int res = 0;
		for (int i = 0; i < cnt; i++) {
			color[cur] = i;
			res = max(res, go(cur + 1));
		}
		if (cnt < 6) {
			color[cur] = cnt;
			++cnt;
			res = max(res, go(cur + 1));
			--cnt;
		}
		return res;
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