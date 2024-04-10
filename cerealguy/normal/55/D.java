import java.io.*;
import java.util.*;

public class D {

	final static int[] a = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14,
			15, 18, 20, 21, 24, 28, 30, 35, 36, 40, 42, 45, 56, 60, 63, 70, 72,
			84, 90, 105, 120, 126, 140, 168, 180, 210, 252, 280, 315, 360, 420,
			504, 630, 840, 1260, 2520 };

	long[][][] d;
	long[] pows;
	final static int MAXLEN = 20;
	final static int MOD = 2520;

	int gcd(int a, int b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	int lcm(int a, int b) {
		if (b == 0 || a == 0)
			return a | b;
		return a / gcd(a, b) * b;
	}

	void precalc() {
		pows = new long[MAXLEN];
		pows[0] = 1;
		for (int i = 1; i < pows.length; i++) {
			pows[i] = pows[i - 1] * 10;
		}
		d = new long[MAXLEN][a.length][MOD];
		d[0][0][0] = 1;
		int pow = 1;
		for (int len = 0; len < MAXLEN - 1; len++) {
			for (int it = 0; it < a.length; it++) {
				int lcm0 = a[it];
				for (int digit = 0; digit < 10; digit++) {
					int lcm1 = lcm(digit, lcm0);
					int ind = Arrays.binarySearch(a, lcm1);
					int r1 = digit * pow % MOD;
					for (int r = 0; r < MOD; r++) {
						d[len + 1][ind][r1] += d[len][it][r];
						r1++;
						if (r1 == MOD)
							r1 = 0;
					}
				}
			}
			pow = (pow * 10) % MOD;
		}
	}

	void solve() throws IOException {
		precalc();
		long t = nextLong();
		for (int i = 0; i < t; i++) {
			long l = nextLong(), r = nextLong();
			System.out.println(get(r) - get(l - 1));
		}
	}

	long get(long max) {
		if (max == 0)
			return 0;
		String s = Long.toString(max);
		int len = s.length();

		long res = -1;
		int lcm = 1;
		for (int it = 0; it < len; it++) {
			long n1 = it == 0 ? 0 : max - (max % pows[len - it]);
			int curdigit = s.charAt(it) - '0';
			for (int digit = 0; digit < curdigit; digit++) {
				long n2 = n1 + digit * pows[len - it - 1];
				int lcm1 = lcm(lcm, digit);
				int r = (int) ((MOD - n2 % MOD) % MOD);

				for (int i = 0; i < a.length; i++) {
					int l = lcm(lcm1, a[i]);
					for (int j = r % l; j < MOD; j += l) {
						res += d[len - it - 1][i][j];
					}
				}
			}
			lcm = lcm(lcm, curdigit);
		}
		if (max % lcm == 0)
			res++;
		return res;
	}

	public static void main(String[] args) {
		try {
			new D().solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static long nextLong() throws IOException {
		long m = 0;
		int c = System.in.read();
		while (c < '0' || c > '9')
			c = System.in.read();
		while (c >= '0' && c <= '9') {
			m = m * 10 + (c - '0');
			c = System.in.read();
		}
		return m;
	}
}