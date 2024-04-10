import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int n = scanInt();
		long a[] = new long[n];
		long b[] = new long[n];
		long ans = 0;
		for (int i = 0; i < n; i++) {
			a[i] = scanLong();
		}
		for (int i = 0; i < n; i++) {
			b[i] = scanLong();
			ans += b[i];
		}
		int goodCnt[] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && (a[i] & ~a[j]) == 0) {
					++goodCnt[i];
				}
			}
		}
		int stack[] = new int[n], stackSize = 0;
		for (int i = 0; i < n; i++) {
			if (goodCnt[i] == 0) {
				stack[stackSize++] = i;
			}
		}
		while (stackSize != 0) {
			int cur = stack[--stackSize];
			ans -= b[cur];
			for (int i = 0; i < n; i++) {
				if (i != cur && (a[i] & ~a[cur]) == 0 && --goodCnt[i] == 0) {
					stack[stackSize++] = i;
				}
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