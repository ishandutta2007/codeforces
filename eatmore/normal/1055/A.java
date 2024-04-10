import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int n = scanInt();
		int s = scanInt() - 1;
		boolean can1[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			can1[i] = scanInt() != 0;
		}
		boolean can2[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			can2[i] = scanInt() != 0;
		}
		if (!can1[0]) {
			out.print("NO");
			return;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (can1[i] && can2[i]) {
				for (i--; i >= 0; i--) {
					can1[i] |= can2[i];
				}
			}
		}
		out.print(can1[s] ? "YES" : "NO");
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