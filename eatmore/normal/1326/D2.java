import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			String s = scanString();
			int n = s.length();
			int poly[] = new int[2 * n + 1];
			int maxC = 0, maxR = 0;
			for (int curC = 1; curC <= 2 * n; curC++) {
				int curR = (curC + 1) / 2;
				if (2 * maxR > curC) {
					curR = min((curC + poly[2 * maxC - curC]) / 2, maxR);
				}
				int curL = curC - curR;
				while (curR < n && curL > 0 && s.charAt(curR) == s.charAt(curL - 1)) {
					++curR;
					--curL;
				}
				poly[curC] = curR - curL;
				if (curR > maxR) {
					maxC = curC;
					maxR = curR;
				}
			}
			int match = 0;
			for (int i = 0, j = n - 1; i < j && s.charAt(i) == s.charAt(j); i++, j--) {
				match = i + 1;
			}
			int ansLen = 2 * match, ansC = 2 * match;
			for (int curC = 2 * match + 1; curC < 2 * (n - match); curC++) {
				int l = min(curC - 2 * match, 2 * (n - match) - curC);
				if (poly[curC] >= l && ansLen < 2 * match + l) {
					ansLen = 2 * match + l;
					ansC = curC;
				}
			}
			out.print(s.substring(0, match));
			out.print(s.substring((ansC - ansLen + 2 * match) / 2, (ansC + ansLen - 2 * match) / 2));
			out.print(s.substring(n - match));
			out.println();
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