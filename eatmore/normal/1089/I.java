import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class I {

	static void solve() throws Exception {
		int tests = scanInt();
		int mod = scanInt();
		int facts[] = new int[401];
		facts[0] = 1;
		for (int i = 1; i <= 400; i++) {
			facts[i] = (int) ((long) facts[i - 1] * i % mod);
		}
		int factsInv[] = new int[401];
		factsInv[400] = BigInteger.valueOf(facts[400]).modInverse(BigInteger.valueOf(mod)).intValue();
		for (int i = 400; i > 0; i--) {
			factsInv[i - 1] = (int) ((long) factsInv[i] * i % mod);
		}
		int f2[] = new int[401];
		for (int i = 1; i <= 400; i++) {
			f2[i] = facts[i];
			for (int j = 1; j < i; j++) {
				f2[i] -= (long) f2[j] * facts[i - j] % mod;
				if (f2[i] < 0) {
					f2[i] += mod;
				}
			}
		}
		int cnt[][] = new int[401][401];
		cnt[0][0] = 1;
		int ans[] = new int[401];
		for (int i = 1; i <= 400; i++) {
			int cans = facts[i];
			for (int j = 1; j <= i; j++) {
				int v = 0;
				for (int k = 1; k <= i; k++) {
					v = (int) ((v + (long) cnt[i - k][j - 1] * facts[k]) % mod);
				}
				cnt[i][j] = v;
			}
			for (int j = 3; j < i; j++) {
				cans -= (long) ans[j] * cnt[i][j] % mod;
				if (cans < 0) {
					cans += mod;
				}
			}
			if (i != 2) {
				for (int j = 1; j < i; j++) {
					cans -= 2L * f2[j] * facts[i - j] % mod;
					if (cans < 0) {
						cans += mod;
					}
				}
			}
			ans[i] = cans;
		}
		for (int test = 0; test < tests; test++) {
			out.println(ans[scanInt()]);
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