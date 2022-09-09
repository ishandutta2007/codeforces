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
		int n = scanInt();
		int t = scanInt();
		boolean val[] = new boolean[n];
		int cnt = 0;
		int curT = t;
		for (int i = 1; i < n; i++) {
			int plen, slen;
			if (2 * i <= n) {
				slen = n - i;
				plen = n % 2 == slen % 2 ? n - 1 : n;
			} else {
				plen = i;
				slen = n % 2 == plen % 2 ? n - 1 : n;
			}
			boolean flipPrefix = false, flipSuffix = false, hasAns = false;
			while (flipPrefix || flipSuffix || !hasAns) {
				out.println("? " + (n + 1 - slen) + " " + plen);
				out.flush();
				int o = scanInt();
				if ((o + curT + plen) % 2 == 0) {
					flipPrefix = !flipPrefix;
				} else {
					flipSuffix = !flipSuffix;
				}
				if ((plen == i ? (flipPrefix && !flipSuffix) : (flipSuffix && !flipPrefix)) && !hasAns) {
					int newCnt = plen == i ? (t + i - o) / 2 : (t + o + i - n) / 2;
					val[i - 1] = newCnt != cnt;
					cnt = newCnt;
					hasAns = true;
				}
				curT = o;
			}
		}
		val[n - 1] = t != cnt;
		out.print("! ");
		for (int i = 0; i < n; i++) {
			out.print(val[i] ? '1' : '0');
		}
		out.println();
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