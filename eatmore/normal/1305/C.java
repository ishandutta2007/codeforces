import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
//		int n = 997, m = 997;
		int a[] = new int[n];
		boolean have[] = new boolean[m];
		for (int i = 0; i < n; i++) {
			int v = scanInt();
//			int v = i;
			int c = v % m;
			if (have[c]) {
				out.print(0);
				return;
			}
			have[c] = true;
			a[i] = v;
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				ans = (int) (((long) ans * abs(a[i] - a[j])) % m);
			}
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