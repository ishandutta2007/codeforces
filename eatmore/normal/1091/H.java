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

public class H {

	static final int primes[] = new int[20000];
	static {
		primes[0] = 2;
		primes[1] = 3;
		for (int i = 2, p = 5, dp = 2; i < primes.length; p += dp, dp = 6 - dp) {
			for (int j = 0;; j++) {
				int q = primes[j];
				if (q * q > p) {
					primes[i++] = p;
				} else if (p % q != 0) {
					continue;
				}
				break;
			}
		}
	}

	static void solve() throws Exception {
		final int MAX = 200000;
		long can[] = new long[(MAX + 63) / 64];
		for (int i = 0; primes[i] < MAX; i++) {
			int pi = primes[i];
			can[pi >> 6] |= 1L << pi;
			if (primes[i] <= 40000) {
				for (int j = i; primes[i] * primes[j] < MAX; j++) {
					int pij = primes[i] * primes[j];
					can[pij >> 6] |= 1L << pij;
				}
			}
		}
		int n = scanInt();
		int f = scanInt();
		can[f >> 6] &= ~(1L << f);
		int grundy[] = new int[MAX];
		List<long[]> mex = new ArrayList<>();
		for (int i = 0; i < MAX; i++) {
			int v;
			for (v = 0; v < mex.size() && (mex.get(v)[i >> 6] & (1L << i)) != 0; v++) { }
			grundy[i] = v;
			if (v == mex.size()) {
				mex.add(new long[(MAX + 63) / 64]);
			}
			long cmex[] = mex.get(v);
			if ((i & 63) == 0) {
				for (int j = 0; j < (MAX + 63) / 64 - (i >> 6); j++) {
					cmex[(i >> 6) + j] |= can[j];
				}
			} else {
				cmex[i >> 6] |= can[0] << i;
				for (int j = 0; j < (MAX + 63) / 64 - (i >> 6) - 1; j++) {
					cmex[(i >> 6) + j + 1] |= (can[j] >>> -i) | (can[j + 1] << i);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a = scanInt(), b = scanInt(), c = scanInt();
			ans ^= grundy[b - a - 1] ^ grundy[c - b - 1];
		}
		out.println(ans == 0 ? "Bob\nAlice" : "Alice\nBob");
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