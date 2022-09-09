import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class F {

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static void solve() throws Exception {
		int n = scanInt();
		for (int i = 2; i * i < n; i++) {
			if (n % i == 0 && gcd(i, n / i) == 1) {
				int x = n / i - BigInteger.valueOf(i).modInverse(BigInteger.valueOf(n / i)).intValue();
				int y = (n - 1 - i * x) / (n / i);
				out.println("YES");
				out.println(2);
				out.println(x + " " + n / i);
				out.println(y + " " + i);
				return;
			}
		}
		out.println("NO");
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