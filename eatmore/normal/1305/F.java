import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class F {

	static final int primes[] = new int[100000];
	static {
		primes[0] = 2;
		primes[1] = 3;
		long bitset[] = new long[7000];
		for (int i = 2, p = 1, dp = 4; i < primes.length; i++) {
			do {
				p += dp;
				dp = 6 - dp;
			} while ((bitset[(p / 3) >> 6] & (1L << (p / 3))) != 0);
			primes[i] = p;
			if (p <= 46340) {
				for (int q = p * p, dq = dp * p, l = 6 * p, j;
					(j = q / 3) >> 6 < bitset.length; q += dq, dq = l - dq) {
					bitset[j >> 6] |= 1L << j;
				}
			}
		}
	}

	static final long factors[] = new long[100];
	static int factorCount;

	static void addFactor(long p) {
		if (factorCount >= factors.length) {
			return;
		}
		for (int i = 0; i < factorCount; i++) {
			if (factors[i] == p) {
				return;
			}
		}
		factors[factorCount++] = p;
	}

	static void addFactors(long v) {
		for (long p: primes) {
			if (p * p > v) {
				break;
			}
			if (v % p == 0) {
				addFactor(p);
				do {
					v /= p;
				} while (v % p == 0);
			}
		}
		if (v > 1) {
			addFactor(v);
		}
	}

	static void solve() throws Exception {
//		System.err.println("START");
		int n = scanInt();
//		int n = 200000;
		long a[] = new long[n];
		long seed = 123;
//		Random trng = new Random();
		for (int i = 0; i < n; i++) {
			a[i] = scanLong();
//			a[i] = new BigInteger(40, 100, trng).longValue();
			seed = seed * 1000000009 ^ a[i];
		}
//		System.err.println("GEN");
		Random rng = new Random(seed);
		factorCount = 0;
		for (int i = 0; i < 100 && factorCount < factors.length; i++) {
			int j = rng.nextInt(n);
			addFactors(a[j]);
			addFactors(a[j] + 1);
			if (a[j] > 1) {
				addFactors(a[j] - 1);
			}
		}
//		System.err.println("FACT");
		long ans = n;
		i: for (int i = 0; i < factorCount; i++) {
			long p = factors[i];
			long cans = 0;
			for (int j = 0; j < n; j++) {
				long c = a[j], v;
				if (c < p) {
					v = p - c;
				} else {
					v = c % p;
					if (2 * v > p) {
						v = p - v;
					}
				}
				cans += v;
				if (cans >= ans) {
					continue i;
				}
			}
			ans = cans;
		}
//		System.err.println("CALC");
		out.print(ans);
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