import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int n = scanInt();
		int orderL[] = new int[n];
		for (int i = 0; i < n; i++) {
			int curL = scanInt();
			if (curL > i) {
				out.print("NO");
				return;
			}
			arraycopy(orderL, i - curL, orderL, i - curL + 1, curL);
			orderL[i - curL] = i;
		}
		int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = scanInt();
			if (r[i] > n - i - 1) {
				out.print("NO");
				return;
			}
		}
		int orderR[] = new int[n];
		for (int i = 0; i < n; i++) {
			int curR = r[n - i - 1];
			arraycopy(orderR, i - curR, orderR, i - curR + 1, curR);
			orderR[i - curR] = n - i - 1;
		}
		int orderLI[] = new int[n], orderRI[] = new int[n];
		for (int i = 0; i < n; i++) {
			orderLI[orderL[i]] = i;
			orderRI[orderR[i]] = i;
		}
		int ans[] = new int[n];
		int pos = 0;
		for (int it = 0; pos < n; it++) {
			for (int npos = pos + 1; pos < npos; pos++) {
				int i = orderL[pos];
				ans[i] = it;
				npos = max(npos, orderRI[i] + 1);
				i = orderR[pos];
				ans[i] = it;
				npos = max(npos, orderLI[i] + 1);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if ((orderL[i] > orderL[i + 1] && ans[orderL[i]] == ans[orderL[i + 1]]) ||
				(orderR[i] < orderR[i + 1] && ans[orderR[i]] == ans[orderR[i + 1]])) {
				out.print("NO");
				return;
			}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				out.print(' ');
			}
			out.print(ans[i] + 1);
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