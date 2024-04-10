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
		int ans = 0, ansB = 0;
		for (int b = 1; b < n; b++) {
			int curAns = n - (n + b) / (b + 1) - b;
			if (ans < curAns) {
				ans = curAns;
				ansB = b;
			}
		}
		boolean on[] = new boolean[n];
		int have = 0;
		int move[] = new int[n];
		while (have < ans) {
			int moveSize = 0;
			for (int i = 0; i < n; i++) {
				if (i % (ansB + 1) != 0 && !on[i]) {
					move[moveSize++] = i;
					on[i] = true;
					++have;
				}
			}
			out.print(moveSize);
			for (int i = 0; i < moveSize; i++) {
				out.print(" " + (move[i] + 1));
			}
			out.println();
			out.flush();
			int x = scanInt() - 1;
			for (int i = 0; i < moveSize; i++) {
				if (on[(x + i) % n]) {
					on[(x + i) % n] = false;
					--have;
				}
			}
		}
		out.println("0");
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