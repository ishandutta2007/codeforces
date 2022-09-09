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
		int n = scanInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
		}
		int ans[] = new int[4 * n], ansSize = 0;
		int v2[] = new int[n], v2p = 0;
		int v3 = -1;
		for (int i = n - 1; i >= 0; i--) {
			switch (a[i]) {
			case 1:
				ans[ansSize++] = i;
				ans[ansSize++] = i;
				v2[v2p++] = i;
				break;
			case 2:
				if (v2p == 0) {
					out.print(-1);
					return;
				}
				ans[ansSize++] = v2[--v2p];
				ans[ansSize++] = i;
				if (v3 < 0) {
					v3 = i;
				}
				break;
			case 3:
				if (v3 >= 0) {
					ans[ansSize++] = i;
					ans[ansSize++] = i;
					ans[ansSize++] = i;
					ans[ansSize++] = v3;
					v3 = i;
				} else if (v2p != 0) {
					ans[ansSize++] = i;
					ans[ansSize++] = i;
					ans[ansSize++] = i;
					ans[ansSize++] = v2[--v2p];
					v3 = i;
				} else {
					out.print(-1);
					return;
				}
			}
		}
		out.println(ansSize / 2);
		for (int i = 0; i < ansSize; i += 2) {
			out.println((ans[i] + 1) + " " + (ans[i + 1] + 1));
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