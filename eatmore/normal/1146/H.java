import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class H {

	static long vmul(int x1, int y1, int x2, int y2, int x3, int y3) {
		long x12 = (long) x2 - x1, y12 = (long) y2 - y1;
		long x13 = (long) x3 - x1, y13 = (long) y3 - y1;
		return y13 * x12 - x13 * y12;
	}

	static int pop(long v) {
		return Long.bitCount(v);
	}

	static void solve() throws Exception {
		int n = scanInt();
//		int n = 300;
		int x[] = new int[n], y[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = scanInt();
			y[i] = scanInt();
//			x[i] = i;
//			y[i] = i * i;
		}
		int l = (n + 63) >> 6;
		long dir[][][] = new long[n][n][l];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				for (int k = 0; k < n; k++) {
					if (vmul(x[i], y[i], x[j], y[j], x[k], y[k]) > 0) {
						dir[i][j][k >> 6] |= 1L << k;
					}
				}
			}
		}
		long ans = (long) n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 20;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == i) {
					continue;
				}
				long dij[] = dir[i][j];
				for (int k = 0; k < n; k++) {
					if ((dij[k >> 6] & (1L << k)) == 0) {
						continue;
					}
					long djk[] = dir[j][k], dki[] = dir[k][i];
					int cnt = 0, cntIn = 0;
					for (int ll = 0; ll < l; ll++) {
						long v = dij[ll] & djk[ll];
						cnt += pop(v);
						cntIn += pop(v & dki[ll]);
					}
					ans -= (long) cntIn * (cntIn - 1);
					ans -= (long) cntIn * (cnt - cntIn) * 3;
				}
			}
		}
		out.print(ans / 6);
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