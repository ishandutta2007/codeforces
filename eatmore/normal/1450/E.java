import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		int d[][] = new int[n][n];
		for (int a[]: d) {
			fill(a, Integer.MAX_VALUE);
		}
		for (int i = 0; i < n; i++) {
			d[i][i] = 0;
		}
		int u[] = new int[m], v[] = new int[m], b[] = new int[m];
		for (int i = 0; i < m; i++) {
			u[i] = scanInt() - 1;
			v[i] = scanInt() - 1;
			b[i] = scanInt();
			d[u[i]][v[i]] = 1;
			d[v[i]][u[i]] = b[i] == 0 ? 1 : -1;
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				for (int k = 0; k < n; k++) {
					if (d[i][j] != Integer.MAX_VALUE && d[j][k] != Integer.MAX_VALUE) {
						d[i][k] = min(d[i][k], max(d[i][j] + d[j][k], Integer.MIN_VALUE / 2));
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (d[i][i] < 0) {
				out.print("NO");
				return;
			}
		}
		int maxI = -1, maxV = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] > maxV) {
					maxV = d[i][j];
					maxI = i;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			int cd = d[maxI][v[i]] - d[maxI][u[i]];
			if (cd != 1 && (b[i] != 0 || cd != -1)) {
				out.print("NO");
				return;
			}
		}
		out.println("YES");
		out.println(maxV);
		for (int i = 0; i < n; i++) {
			if (d[maxI][i] < 0) {
				throw new AssertionError();
			}
			out.print(d[maxI][i] + " ");
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