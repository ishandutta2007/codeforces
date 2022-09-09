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
		String s = scanString();
		int n = s.length(), b = 0;
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) != 'a') {
				++b;
			}
		}
		if ((b & 1) != 0) {
			out.print(":(");
			return;
		}
		char arr[] = new char[b >> 1];
		for (int i = 0, j = 0; i < n - (b >> 1); i++) {
			char c = s.charAt(i);
			if (c != 'a') {
				if (j == arr.length) {
					out.print(":(");
					return;
				}
				arr[j++] = c;
			}
		}
		if (!new String(arr).equals(s.substring(n - (b >> 1)))) {
			out.print(":(");
			return;
		}
		out.print(s.substring(0, n - (b >> 1)));
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