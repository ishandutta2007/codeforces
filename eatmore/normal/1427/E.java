import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		long x = scanLong();
		List<String> ans = new ArrayList<>();
		if ((x & 2) != 0) {
			ans.add(x + " + " + x);
			ans.add(2 * x + " + " + x);
			x *= 3;
		}
		int k = 63 - Long.numberOfLeadingZeros(x);
		for (int i = 0; i < k; i++) {
			ans.add((x << i) + " + " + (x << i));
		}
		ans.add(x + " + " + (x << k));
		ans.add((x + (x << k)) + " ^ " + (x << k));
		ans.add(((x + (x << k)) ^ (x << k)) + " ^ " + x);
		long y = 1;
		for (int i = 0; i < 5; i++) {
			y *= 2 - x * y;
		}
		System.err.println((x * y) & ((1L << (k + 1)) - 1));
		y &= (1L << (k + 1)) - 1;
		long r = x;
		for (int i = 62 - Long.numberOfLeadingZeros(y); i >= 0; i--) {
			ans.add(r + " + " + r);
			r += r;
			if ((y & (1L << i)) != 0) {
				ans.add(r + " + " + x);
				r += x;
			}
		}
		System.err.println(r + " " + x * y);
		for (int i = k + 1; r != 1; i++) {
			if ((r & (1L << i)) != 0) {
				ans.add(r + " ^ " + (1L << i));
				r ^= 1L << i;
			}
			if (r == 1) {
				break;
			}
			ans.add((1L << i) + " + " + (1L << i));
		}
		out.println(ans.size());
		for (String s: ans) {
			out.println(s);
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