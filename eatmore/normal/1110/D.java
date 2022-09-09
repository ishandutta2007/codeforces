import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int n = scanInt();
		int m = scanInt();
//		int n = 1000000;
//		int m = 1000000;
		int c[] = new int[m];
		for (int i = 0; i < n; i++) {
			++c[scanInt() - 1];
//			++c[i];
		}
		int dyn[][] = new int[3][3];
		for (int i = 0; i < 3; i++) {
			fill(dyn[i], Integer.MIN_VALUE);
		}
		dyn[0][0] = 0;
		int ndyn[][] = new int[3][3];
		for (int i = 0; i < m; i++) {
			int cur = c[i];
			for (int j1 = 0; j1 < 3; j1++) {
				for (int j2 = 0; j2 < 3; j2++) {
					int v = Integer.MIN_VALUE;
					for (int j3 = 0; j3 < 3; j3++) {
						if (cur >= j1 + j2 + j3 && dyn[j2][j3] != Integer.MIN_VALUE) {
							v = max(v, dyn[j2][j3] + (cur - j1 - j2 - j3) / 3 + j3);
						}
					}
					ndyn[j1][j2] = v;
				}
			}
			int t[][] = dyn;
			dyn = ndyn;
			ndyn = t;
		}
		out.print(dyn[0][0]);
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