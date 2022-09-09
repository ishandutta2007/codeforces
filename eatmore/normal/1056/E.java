import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class E {

	static int mod1(int a, int b, int c) {
		long r = (long) a * b + c;
		long h = r >>> 31, l = r & 0x7fffffffL;
		r = l + h;
		h = r >>> 31; l = r & 0x7fffffffL;
		r = l + h;
		return (int) r;
	}

	static int mod2(int a, int b, int c) {
		long r = (long) a * b + c;
		long h = r >>> 31, l = r & 0x7fffffffL;
		r = l + h + (h << 1) + (h << 4);
		h = r >>> 31; l = r & 0x7fffffffL;
		r = l + h + (h << 1) + (h << 4);
		return (int) r;
	}

	static final int MUL1 = 65537, MUL2 = 65537;
	static final int MOD1 = Integer.MIN_VALUE - 1, MOD2 = Integer.MIN_VALUE - 19;
	static final int POWS1[] = new int[1000001],
	                 POWS2[] = new int[1000001];
	static {
		POWS1[0] = POWS2[0] = 1;
		for (int i = 1; i < POWS1.length; i++) {
			POWS1[i] = mod1(POWS1[i - 1], MUL1, 0);
			POWS2[i] = mod2(POWS2[i - 1], MUL2, 0);
		}
	}

	static void solve() throws Exception {
		String s = scanString();
		String t = scanString();
		int sLen = s.length(), tLen = t.length();
		int n0 = 0, n1 = 0;
		for (int i = 0; i < sLen; i++) {
			if (s.charAt(i) == '0') {
				++n0;
			} else {
				++n1;
			}
		}
		int hash1[] = new int[tLen + 1];
		int hash2[] = new int[tLen + 1];
		for (int i = 0; i < tLen; i++) {
			int c = t.charAt(i);
			hash1[i + 1] = mod1(c, POWS1[i], hash1[i]);
			hash2[i + 1] = mod2(c, POWS2[i], hash2[i]);
		}
		int ans = 0;
		len: for (int l0 = 1; l0 <= tLen / n0; l0++) {
			int left = tLen - n0 * l0;
			if (left == 0 || left % n1 != 0) {
				continue;
			}
			int l1 = left / n1;
			int h01 = -1, h02 = -1, h11 = -1, h12 = -1;
			for (int i = 0, j = 0; i < sLen; i++) {
				if (s.charAt(i) == '0') {
					int nh1 = mod1((int) ((((long) hash1[j + l0] - hash1[j]) % MOD1 + MOD1) % MOD1), POWS1[tLen - j], 0);
					int nh2 = mod2((int) ((((long) hash2[j + l0] - hash2[j]) % MOD2 + MOD2) % MOD2), POWS2[tLen - j], 0);
					if (h01 == -1) {
						h01 = nh1;
						h02 = nh2;
					} else if (h01 != nh1 || h02 != nh2) {
						continue len;
					}
					j += l0;
				} else {
					int nh1 = mod1((int) ((((long) hash1[j + l1] - hash1[j]) % MOD1 + MOD1) % MOD1), POWS1[tLen - j], 0);
					int nh2 = mod2((int) ((((long) hash2[j + l1] - hash2[j]) % MOD2 + MOD2) % MOD2), POWS2[tLen - j], 0);
					if (h11 == -1) {
						h11 = nh1;
						h12 = nh2;
					} else if (h11 != nh1 || h12 != nh2) {
						continue len;
					}
					j += l1;
				}
			}
			if (l0 == l1 && h01 == h11 && h02 == h12) {
				continue;
			}
			++ans;
		}
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