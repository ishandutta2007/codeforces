import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static int mod;

	static int add(int a, int b) {
		int res = a + b;
		return res >= mod ? res - mod : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + mod : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % mod);
		return res < 0 ? res + mod : res;
	}

	static int sqr(int a) {
		return mul(a, a);
	}

	static int pow(int a, int e) {
		if (e == 0) {
			return 1;
		}
		int r = a;
		for (int i = 30 - Integer.numberOfLeadingZeros(e); i >= 0; i--) {
			r = mul(r, r);
			if ((e & (1 << i)) != 0) {
				r = mul(r, a);
			}
		}
		return r;
	}

	static int inv(int a) {
		return pow(a, mod - 2);
	}

	static void solve() throws Exception {
		int n = scanInt();
		mod = scanInt();
		int ansNum = 0, ansDen = 1;
		int curNum = 1, curDen = 1;
		for (int i = 2; i <= n; i++) {
			curNum = mul(curNum, i);
		}
		for (int i = 1; i <= n; i++) {
			curNum = mul(curNum, i);
			curDen = mul(curDen, n - i + 1);
			ansNum = add(mul(ansNum, curDen), mul(ansDen, mul(curNum, sqr(n - i + 1))));
			ansDen = mul(ansDen, curDen);
		}
		out.print(mul(ansNum, inv(ansDen)));
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