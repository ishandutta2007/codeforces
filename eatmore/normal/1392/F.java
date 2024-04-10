import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void solve() throws Exception {
		int n = scanInt();
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += scanLong() - i;
		}
		long off = sum / n;
		int pref = (int) (sum % n);
		for (int i = 0; i < pref; i++) {
			out.print((off + i + 1) + " ");
		}
		for (int i = pref; i < n; i++) {
			out.print((off + i) + " ");
		}
	}

	static int scanInt() throws IOException {
		return (int) scanLong();
	}

	static long scanLong() throws IOException {
		int c;
		while ((c = in.read()) < '0' || c > '9') { }
		long v = c - '0';
		while ((c = in.read()) >= '0' && c <= '9') {
			v = v * 10 + c - '0';
		}
		return v;
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