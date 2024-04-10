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
		int p[] = new int[n], pi[] = new int[n];
		for (int i = 0; i < n; i++) {
			pi[p[i] = scanInt() - 1] = i;
		}
		char ans[] = new char[n];
		i: for (int i = n - 1; i >= 0; i--) {
			for (int j = pi[i] % (i + 1); j < n; j += i + 1) {
				if (p[j] > i && ans[j] == 'B') {
					ans[pi[i]] = 'A';
					continue i;
				}
			}
			ans[pi[i]] = 'B';
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