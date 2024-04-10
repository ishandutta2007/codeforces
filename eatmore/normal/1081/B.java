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
		int n = scanInt();
		int cur = 0;
		int cnts[] = new int[n + 1];
		int group[] = new int[n + 1];
		int b[] = new int[n];
		for (int i = 0; i < n; i++) {
			int a = n - scanInt();
			if (cnts[a] == 0) {
				group[a] = cur++;
				cnts[a] = a;
			}
			b[i] = group[a];
			--cnts[a];
		}
		for (int i = 0; i <= n; i++) {
			if (cnts[i] != 0) {
				out.print("Impossible");
				return;
			}
		}
		out.println("Possible");
		for (int i = 0; i < n; i++) {
			out.print((b[i] + 1) + " ");
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