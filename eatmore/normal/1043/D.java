import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
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
		int next[] = new int[n];
		int prev = -1;
		for (int i = 0; i < n; i++) {
			int cur = scanInt() - 1;
			if (prev >= 0) {
				next[prev] = cur;
			}
			prev = cur;
		}
		next[prev] = -1;
		for (int i = 0; i < m - 1; i++) {
			prev = -1;
			for (int j = 0; j < n; j++) {
				int cur = scanInt() - 1;
				if (prev >= 0 && next[prev] != cur) {
					next[prev] = -1;
				}
				prev = cur;
			}
			next[prev] = -1;
		}
		boolean start[] = new boolean[n];
		fill(start, true);
		for (int i = 0; i < n; i++) {
			if (next[i] >= 0) {
				start[next[i]] = false;
			}
		}
		long ans = 0;
		for (int i = 0; i < n; i++) {
			if (!start[i]) {
				continue;
			}
			int cnt = 0;
			for (int j = i; j >= 0; j = next[j]) {
				++cnt;
			}
			ans += (long) cnt * (cnt + 1) / 2;
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