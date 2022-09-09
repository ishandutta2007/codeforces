import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		long k = scanLong();
		long cur = 1;
		int curMul = 1, nextCnt = 0;
		while (cur < k) {
			cur = cur / curMul * (curMul + 1);
			if (++nextCnt == 10) {
				++curMul;
				nextCnt = 0;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0, l = i < nextCnt ? curMul + 1 : curMul; j < l; j++) {
				out.print("codeforces".charAt(i));
			}
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