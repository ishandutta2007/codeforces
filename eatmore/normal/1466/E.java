import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static void solve() throws Exception {
		int p2[] = new int[119];
		p2[0] = 1;
		for (int i = 1; i < 119; i++) {
			p2[i] = add(p2[i - 1], p2[i - 1]);
		}
		int cnt1[] = new int[60], cnt2[][] = new int[60][60];
		long agg2[][] = new long[60][4];
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			fill(cnt1, 0);
			for (int i = 0; i < 60; i++) {
				fill(cnt2[i], 0);
			}
			int c = 0;
			for (int i = 0; i < n; i++) {
				long x = scanLong();
				for (int j = 0; j < 60; j++) {
					if ((x & (1L << j)) != 0) {
						++cnt1[j];
						agg2[j][0] += x & 0x1111111111111111L;
						agg2[j][1] += x & 0x2222222222222222L;
						agg2[j][2] += x & 0x4444444444444444L;
						agg2[j][3] += x & 0x8888888888888888L;
					}
				}
				if (++c == 15) {
					c = 0;
					for (int j = 0; j < 60; j++) {
						for (int k = 0; k < j; k++) {
							cnt2[j][k] += (int) (agg2[j][k & 3] >> k) & 15;
						}
						agg2[j][0] = 0;
						agg2[j][1] = 0;
						agg2[j][2] = 0;
						agg2[j][3] = 0;
					}
				}
			}
			for (int j = 0; j < 60; j++) {
				for (int k = 0; k < j; k++) {
					cnt2[j][k] += (int) (agg2[j][k & 3] >> k) & 15;
				}
				agg2[j][0] = 0;
				agg2[j][1] = 0;
				agg2[j][2] = 0;
				agg2[j][3] = 0;
			}
			for (int i = 0; i < 60; i++) {
				cnt2[i][i] = cnt1[i];
				for (int j = 0; j < i; j++) {
					cnt2[j][i] = cnt2[i][j];
				}
			}
			int ans = 0;
			for (int i = 0; i < 60; i++) {
				for (int j = 0; j < 60; j++) {
					ans = add(ans, mul(mul(cnt1[i], sub(add(mul(cnt2[i][j], n), mul(cnt1[i], cnt1[j])), mul(cnt2[i][j], cnt1[j]))), p2[i + j]));
				}
			}
			out.println(ans);
		}
	}

	static int scanInt() throws IOException {
		return (int) scanLong();
	}

	static long scanLong() throws IOException {
		int c;
		while ((c = in.read()) < '0' || c > '9') { }
		long v = c - '0';
		while ((c = in.read()) >= '0' && c <= '9') {
			v = v * 10 + (c - '0');
		}
		return v;
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