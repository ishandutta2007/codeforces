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
		int tests = scanInt();
//		int tests = 40;
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), m = scanInt(), a[][] = new int[n][m];
//			int n = 12, m = 2000, a[][] = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					a[i][j] = scanInt();
				}
			}
			int bestCols[] = new int[min(m, n)];
			for (int i = 0; i < bestCols.length; i++) {
				bestCols[i] = i;
			}
			if (m > n) {
				int bestColMax[] = new int[n];
				for (int i = 0; i < n; i++) {
					int cmax = 0;
					for (int j = 0; j < n; j++) {
						cmax = max(cmax, a[j][i]);
					}
					bestColMax[i] = cmax;
				}
				for (int i = n; i < m; i++) {
					int cmax = 0;
					for (int j = 0; j < n; j++) {
						cmax = max(cmax, a[j][i]);
					}
					int minBC = 0, minBCM = Integer.MAX_VALUE;
					for (int j = 0; j < n; j++) {
						if (bestColMax[j] < minBCM) {
							minBC = j;
							minBCM = bestColMax[j];
						}
					}
					if (cmax > minBCM) {
						bestCols[minBC] = i;
						bestColMax[minBC] = cmax;
					}
				}
			}
			int dyn[] = new int[1 << n], dynNext[] = new int[1 << n], sums[] = new int[1 << n], csums[] = new int[1 << n];
			for (int i: bestCols) {
				fill(dynNext, 0);
				fill(sums, 0);
				for (int j = 0; j < n; j++) {
					for (int k = 1, bit = 0; k < 1 << n; k++) {
						if (k == 1 << (bit + 1)) {
							++bit;
						}
						sums[k] = max(sums[k], csums[k] = csums[k ^ (1 << bit)] + a[(bit + j) % n][i]);
					}
				}
				for (int mask1 = 0; mask1 < 1 << n; mask1++) {
					int cdyn = dynNext[mask1];
					for (int mask2 = mask1;; mask2 = (mask2 - 1) & mask1) {
						cdyn = max(cdyn, dyn[mask2] + sums[mask1 ^ mask2]);
						if (mask2 == 0) {
							break;
						}
					}
					dynNext[mask1] = cdyn;
				}
				int t[] = dyn;
				dyn = dynNext;
				dynNext = t;
			}
			out.println(dyn[(1 << n) - 1]);
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