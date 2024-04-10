import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static final int inf = Integer.MAX_VALUE / 2;

	static void solve() throws Exception {
		int r = scanInt(), n = scanInt();
		int maxD = 2 * r - 2, cans = -inf, ptr = 0;
		int v[] = new int[6 * n + 6];
		v[0] = 0;
		v[1] = 2;
		v[2] = 0;
		v[3] = 0;
		v[4] = -2;
		v[5] = 0;
		for (int i = 6; i < v.length; i += 6) {
			int t = scanInt(), x = scanInt(), y = scanInt();
			int v1 = t + x + y, v2 = t + x - y, v3 = t - x + y, v4 = t - x - y;
			while (ptr < i && v[ptr] <= t - maxD) {
				cans = max(cans, v[ptr + 5]);
				ptr += 6;
			}
			v[i] = t;
			v[i + 1] = v1;
			v[i + 2] = v2;
			v[i + 3] = v3;
			v[i + 4] = v4;
			int ansi = cans;
			for (int j = ptr; j < i; j += 6) {
				if (v[j + 1] <= v1 && v[j + 2] <= v2 && v[j + 3] <= v3 && v[j + 4] <= v4) {
					ansi = max(ansi, v[j + 5]);
				}
			}
			v[i + 5] = ansi + 1;
		}
		while (ptr < v.length) {
			cans = max(cans, v[ptr + 5]);
			ptr += 6;
		}
		out.print(cans);
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