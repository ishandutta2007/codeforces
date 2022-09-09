import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int n = scanInt(), a[] = new int[n], max = -1, min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
			min = min(min, a[i]);
			max = max(max, a[i]);
		}
		if (min * 2 >= max) {
			for (int i = 0; i < n; i++) {
				out.print("-1 ");
			}
			return;
		}
		int maxDeque[] = new int[3 * n], maxDequeStart = 0, maxDequeEnd = 0, ptr = 0;
		for (int i = 0; i < n; i++) {
			while (ptr == i || a[maxDeque[maxDequeStart] % n] <= 2 * a[ptr % n]) {
				while (maxDequeStart < maxDequeEnd && a[ptr % n] >= a[maxDeque[maxDequeEnd - 1] % n]) {
					--maxDequeEnd;
				}
				maxDeque[maxDequeEnd++] = ptr;
				++ptr;
			}
			out.print((ptr - i) + " ");
			if (maxDeque[maxDequeStart] == i) {
				++maxDequeStart;
			}
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