import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int n = scanInt();
		for (int i = 0; i < n; i++) {
			String s = scanString();
			int sum = 0, cnt0 = 0, cnt = 0;
			for (int j = 0; j < s.length(); j++) {
				int d = s.charAt(j) - '0';
				sum += d;
				if (d == 0) {
					++cnt0;
				}
				if (d % 2 == 0) {
					++cnt;
				}
			}
			out.println(sum % 3 == 0 && cnt0 >= 1 && cnt >= 2 ? "red" : "cyan");
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