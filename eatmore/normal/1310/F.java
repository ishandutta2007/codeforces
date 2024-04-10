import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class F {

	static void sortBy(int a[], int n, long v[]) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			long cv = v[ca];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cv <= v[na]) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (v[a[j + 2]] > v[a[j + 1]]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			long cv = v[ca];
			while (j != 0 && v[a[j]] < cv) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static final long MUL_BIT_TABLE[] = new long[64 * 64];
	static long mulBits(int i, int j) {
		int key = i * 64 + j;
		long res = MUL_BIT_TABLE[key];
		if (res == 0) {
			res = 1;
			for (int k = 5; k >= 0; k--) {
				if (((i ^ j) & (1 << k)) != 0) {
					res <<= 1 << k;
				}
			}
			for (int k = 5; k >= 0; k--) {
				if ((i & j & (1 << k)) != 0) {
					res = mul(res, 3L << ((1 << k) - 1));
				}
			}
			MUL_BIT_TABLE[key] = res;
		}
		return res;
	}

	static long mulSlow(long a, long b) {
		long res = 0;
		for (int i = 0; i < 64; i++) {
			if ((a & (1L << i)) == 0) {
				continue;
			}
			for (int j = 0; j < 64; j++) {
				if ((b & (1L << j)) == 0) {
					continue;
				}
				res ^= mulBits(i, j);
			}
		}
		return res;
	}

	static long mulCached(int i, int vi, int j, int vj) {
		int key = ((i * 8 + j) * 256 + vi) * 256 + vj;
		long res = MUL_TABLE[key];
		if (res == 0) {
			if ((vi & 0xf) != 0 && (vi & 0xf0) != 0) {
				res = mulCached(i, vi & 0xf, j, vj) ^ mulCached(i, vi & 0xf0, j, vj);
			} else if ((vj & 0xf) != 0 && (vj & 0xf0) != 0) {
				res = mulCached(i, vi, j, vj & 0xf) ^ mulCached(i, vi, j, vj & 0xf0);
			} else {
				res = mulSlow((long) vi << (8 * i), (long) vj << (8 * j));
			}
			MUL_TABLE[key] = res;
		}
		return res;
	}

	static final long MUL_TABLE[] = new long[8 * 8 * 256 * 256];
	static long mul(long a, long b) {
		long res = 0;
		for (int i = 0; i < 8; i++) {
			int vi = (int) ((a >> (8 * i)) & 255);
			if (vi == 0) {
				continue;
			}
			for (int j = 0; j < 8; j++) {
				int vj = (int) ((b >> (8 * j)) & 255);
				if (vj == 0) {
					continue;
				}
				res ^= mulCached(i, vi, j, vj);
			}
		}
		return res;
	}

	static long pow(long a, long e) {
		if (e == 0) {
			return 1;
		}
		long r = a;
		for (int i = 62 - Long.numberOfLeadingZeros(e); i >= 0; i--) {
			r = mul(r, r);
			if ((e & (1L << i)) != 0) {
				r = mul(r, a);
			}
		}
		return r;
	}

	static final long PRE_TABLE[] = new long[16 * 16];
	static void preClear() {
		fill(PRE_TABLE, 0);
	}
	static long preMul(long a, long b) {
		long res = 0;
		for (int i = 0; i < 16; i++) {
			int vi = (int) ((a >> (4 * i)) & 15);
			if (vi == 0) {
				continue;
			}
			int pkey = i * 16 + vi;
			long pres = PRE_TABLE[pkey];
			if (pres == 0) {
				int ii = i >> 1, vii = (i & 1) == 0 ? vi : vi << 4;
				for (int j = 0; j < 8; j++) {
					int vj = (int) ((b >> (8 * j)) & 255);
					if (vj == 0) {
						continue;
					}
					pres ^= mulCached(ii, vii, j, vj);
				}
				PRE_TABLE[pkey] = pres;
			}
			res ^= pres;
		}
		return res;
	}

	static final long GEN = -Long.MAX_VALUE;
	static final int PRIMES[] = {3, 5, 17, 257, 641, 65537, 6700417};
	static final int PRIME_STEP[] = {1, 1, 1, 1, 1, 20, 200};
	static final long POW_VALS[][] = new long[PRIMES.length][];
	static final int POW_IDX[][] = new int[PRIMES.length][];
	static {
		for (int i = 0; i < PRIMES.length; i++) {
			int p = PRIMES[i];
			int s = PRIME_STEP[i];
			int l = (p + s - 1) / s;
			POW_VALS[i] = new long[l];
			POW_IDX[i] = new int[l];
			POW_VALS[i][0] = 1;
			long cgen = pow(GEN, Long.divideUnsigned(-1, p) * s);
			preClear();
			for (int j = 1; j < l; j++) {
				POW_VALS[i][j] = preMul(POW_VALS[i][j - 1], cgen);
				POW_IDX[i][j] = j;
			}
			sortBy(POW_IDX[i], l, POW_VALS[i]);
		}
	}

	static final BigInteger bMod = BigInteger.ONE.shiftLeft(64).subtract(BigInteger.ONE);

	static BigInteger dlog(long v) {
		BigInteger res = BigInteger.ZERO;
		for (int i = 0; i < PRIMES.length; i++) {
			int p = PRIMES[i];
			int s = PRIME_STEP[i];
			int len = POW_VALS[i].length;
			long vv = pow(v, Long.divideUnsigned(-1, p));
			long cgen = pow(GEN, -1 - Long.divideUnsigned(-1, p));
			int cres = -1;
			preClear();
			for (int j = 0; j < s; j++) {
				int l = 0, r = len;
				while (l < r) {
					int mid = (l + r) >> 1;
					if (POW_VALS[i][POW_IDX[i][mid]] < vv) {
						l = mid + 1;
					} else {
						r = mid;
					}
				}
				if (l < len && POW_VALS[i][POW_IDX[i][l]] == vv) {
					cres = POW_IDX[i][l] * s + j;
					break;
				}
				vv = preMul(vv, cgen);
			}
			if (cres < 0) {
				throw new AssertionError();
			}
			BigInteger bp = BigInteger.valueOf(p);
			BigInteger md = bMod.divide(bp);
			res = res.add(md.modInverse(bp).multiply(md).multiply(BigInteger.valueOf(cres)));
		}
		return res.mod(bMod);
	}

	static void solve() throws Exception {
		int tests = scanInt();
//		int tests = 100;
//		Random rng = new Random(42);
		for (int test = 0; test < tests; test++) {
			long a = new BigInteger(scanString()).longValue(),
			     b = new BigInteger(scanString()).longValue();
//			long a = test * 12345678901L + 12345678901234567L, b = pow(a, 1999);
//			long a = rng.nextLong(), b = rng.nextLong();
			BigInteger logA = dlog(a), logB = dlog(b);
			BigInteger x;
			if (logB.signum() == 0) {
				x = BigInteger.ZERO;
			} else {
				BigInteger gcd = logA.gcd(logB).gcd(bMod);
				logA = logA.divide(gcd);
				logB = logB.divide(gcd);
				BigInteger curMod = bMod.divide(gcd);
				if (logA.gcd(curMod).compareTo(BigInteger.ONE) != 0) {
					x = BigInteger.ONE.negate();
				} else {
					x = logA.modInverse(curMod).multiply(logB).mod(curMod);
				}
			}
//			if (x.signum() >= 0 && pow(a, x.longValue()) != b) {
//				throw new AssertionError();
//			}
			out.println(x);
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