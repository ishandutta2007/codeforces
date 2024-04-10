import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class H1 {

	static final int MOD = 998244353;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
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
		return pow(a, MOD - 2);
	}

	static final int HALF = (MOD + 1) / 2;

	static int dbl(int a) {
		return add(a, a);
	}

	static int half(int a) {
		return mul(a, HALF);
	}

	static int facts[], factsInv[], p2[];

	static int c(int n, int k) {
		return mul(facts[n], mul(factsInv[k], factsInv[n - k]));
	}

//	static int cN1, cK1, cSum1;
//
//	static int csum1(int n, int k) {
//		if (k < 0) {
//			k = 0;
//		}
//		if (k > n) {
//			return 0;
//		}
//		while (cK1 > k) {
//			cSum1 = add(cSum1, c(cN1, --cK1));
//		}
//		while (cN1 < n) {
//			cSum1 = add(cSum1, cSum1);
//			if (cK1 > 0) {
//				cSum1 = add(cSum1, c(cN1, cK1 - 1));
//			}
//			++cN1;
//		}
//		while (cN1 > n) {
//			--cN1;
//			if (cK1 > 0) {
//				cSum1 = sub(cSum1, c(cN1, cK1 - 1));
//			}
//			cSum1 = mul(cSum1, HALF);
//		}
//		while (cK1 < k) {
//			cSum1 = sub(cSum1, c(cN1, cK1++));
//		}
//		return cSum1;
//	}
//
//	static int csum1R(int n, int k) {
//		return sub(p2[n], csum1(n, k));
//	}
//
//	static int csum1E(int n, int k) {
//		if (n == 0) {
//			return k <= 0 && k % 2 == 0 ? 1 : 0;
//		}
//		return csum1(n - 1, k - 1);
//	}
//
//	static int csum1ER(int n, int k) {
//		if (n == 0) {
//			return k > 0 && k % 2 == 0 ? 1 : 0;
//		}
//		return csum1R(n - 1, k - 1);
//	}
//
//	static int cN2, cK2, cSum2;
//
//	static int csum2(int n, int k) {
//		if (k < 0) {
//			return add(csum2(n, 0), mul(p2[n], -k));
//		}
//		if (k > n) {
//			return add(csum2(n, n), mul(p2[n], k - n));
//		}
//		while (cK2 > k) {
//			cSum2 = add(cSum2, sub(dbl(csum1(cN2, cK2--)), p2[cN2]));
//		}
//		while (cN2 < n) {
//			cSum2 = dbl(cSum2);
//			cSum2 = add(cSum2, sub(dbl(csum1(cN2, cK2)), p2[cN2]));
//			++cN2;
//		}
//		while (cN2 > n) {
//			--cN2;
//			cSum2 = sub(cSum2, sub(dbl(csum1(cN2, cK2)), p2[cN2]));
//			cSum2 = half(cSum2);
//		}
//		while (cK2 < k) {
//			cSum2 = sub(cSum2, sub(dbl(csum1(cN2, ++cK2)), p2[cN2]));
//		}
//		return cSum1;
//	}

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		char s[] = scanString().toCharArray();
		int sum = 0, unks = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				++unks;
			} else {
				sum += (i % 2 != 0) ^ (s[i] == 'w') ? 1 : -1;
			}
		}
		facts = new int[2 * n + 1];
		facts[0] = 1;
		for (int i = 1; i < facts.length; i++) {
			facts[i] = mul(facts[i - 1], i);
		}
		factsInv = new int[facts.length];
		factsInv[facts.length - 1] = inv(facts[facts.length - 1]);
		for (int i = facts.length - 1; i > 0; i--) {
			factsInv[i - 1] = mul(factsInv[i], i);
		}
		p2 = new int[2 * n + 1];
		p2[0] = 1;
		for (int i = 1; i < p2.length; i++) {
			p2[i] = add(p2[i - 1], p2[i - 1]);
		}
//		cN1 = 0;
//		cK1 = 0;
//		cSum1 = 1;
		for (int qq = 0;; qq++) {
			int ans = 0;
			for (int i = 0; i <= unks; i++) {
				if ((sum + 2 * i - unks) % 4 == 0) {
					ans = add(ans, mul(c(unks, i), abs(sum + 2 * i - unks) / 4));
				}
			}
			out.println(mul(ans, inv(p2[unks - 1])));
			if (qq == m) {
				break;
			}
			int i = scanInt() - 1;
			if (s[i] == '?') {
				--unks;
			} else {
				sum -= (i % 2 != 0) ^ (s[i] == 'w') ? 1 : -1;
			}
			s[i] = scanString().charAt(0);
			if (s[i] == '?') {
				++unks;
			} else {
				sum += (i % 2 != 0) ^ (s[i] == 'w') ? 1 : -1;
			}
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