import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int n = scanInt();
		int m = scanInt();
		boolean rows[] = new boolean[n];
		boolean cols[] = new boolean[m];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (scanInt() != 0) {
						rows[j] ^= true;
						cols[k] ^= true;
					}
				}
			}
		}
		boolean can = true;
		for (int i = 0; i < n; i++) {
			if (rows[i]) {
				can = false;
			}
		}
		for (int i = 0; i < m; i++) {
			if (cols[i]) {
				can = false;
			}
		}
		out.print(can ? "Yes" : "No");
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