import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt(), a[] = new int[n], cnt[] = new int[n + 1];
			for (int i = 0; i < n; i++) {
				++cnt[a[i] = scanInt()];
			}
			int ans[] = new int[2 * n], ansLen = 0;
			solve: while (true) {
				for (int i = 0; i < n; i++) {
					if (cnt[i] == 0) {
						ans[ansLen++] = i;
						--cnt[a[i]];
						++cnt[a[i] = i];
						continue solve;
					}
				}
				for (int i = 0; i < n; i++) {
					if (a[i] != i) {
						for (int j = 0;; j++) {
							if (a[j] == i) {
								ans[ansLen++] = j;
								--cnt[i];
								++cnt[a[j] = n];
								ans[ansLen++] = i;
								--cnt[a[i]];
								++cnt[a[i] = i];
								continue solve;
							}
						}
					}
				}
				break;
			}
			out.println(ansLen);
			for (int i = 0; i < ansLen; i++) {
				out.print((ans[i] + 1) + " ");
			}
			out.println();
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