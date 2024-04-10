import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void solve() throws Exception {
		int n = scanInt();
		int adj[] = new int[n];
		for (int i = 0; i < n; i++) {
			String s = scanString();
			for (int j = 0; j < n; j++) {
				if (s.charAt(j) == '1') {
					adj[i] |= 1 << j;
				}
			}
		}
		int pop[] = new int[1 << n];
		for (int i = 0; i < 1 << n; i++) {
			pop[i] = Integer.bitCount(i);
		}
		long ans[] = new long[1 << (n - 1)];
		long dyn[] = new long[n << n];
		int cnt[] = new int[n + 1];
		for (int ai = 0; ai < 1 << (n - 1); ai++) {
			fill(cnt, 0);
			for (int cur = ai; cur != 0;) {
				++cnt[Integer.numberOfTrailingZeros(~cur)];
				cur &= cur + 1;
				cur >>= Integer.numberOfTrailingZeros(cur);
			}
			{
				int cur = 0;
				for (int i = 1; i <= n; i++) {
					for (int j = cnt[i]; j > 0; j--) {
						cur = (cur << (i + 1)) + (1 << i) - 1;
					}
				}
				if (ai != cur) {
//				if (true) {
					ans[ai] = ans[cur];
					continue;
				}
			}
			fill(dyn, 0);
			for (int i = 0; i < n; i++) {
				dyn[(i << n) | (1 << i)] = 1;
			}
			for (int set = 0; set < 1 << n; set++) {
				if ((ai & (1 << (pop[set] - 1))) != 0) {
					for (int cur = 0; cur < n; cur++) {
						if ((set & (1 << cur)) == 0) {
							continue;
						}
						long cdyn = dyn[(cur << n) | set];
						for (int next = 0; next < n; next++) {
							if ((set & (1 << next)) != 0) {
								continue;
							}
							if ((adj[cur] & (1 << next)) != 0) {
								dyn[(next << n) | set | (1 << next)] += cdyn;
							}
						}
					}
				} else {
					for (int cur = 0; cur < n; cur++) {
						if ((set & (1 << cur)) == 0) {
							continue;
						}
						long cdyn = dyn[(cur << n) | set];
						for (int next = 0; next < n; next++) {
							if ((set & (1 << next)) != 0) {
								continue;
							}
							dyn[(next << n) | set | (1 << next)] += cdyn;
						}
					}
				}
			}
			long cans = 0;
			for (int i = 0; i < n; i++) {
				cans += dyn[(i << n) + (1 << n) - 1];
			}
			ans[ai] = cans;
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1 << i; j < 1 << (n - 1); j = (j + 1) | (1 << i)) {
				ans[j - (1 << i)] -= ans[j];
			}
		}
		for (int i = 0; i < 1 << (n - 1); i++) {
			out.print(ans[i] + " ");
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