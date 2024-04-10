import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class E {

	private static void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		final int MOD = nextInt();
		int[] lArray = new int[n];
		int maxL = 0;
		for (int i = 0; i < n; i++) {
			lArray[i] = nextInt();
			maxL = Math.max(maxL, lArray[i]);
		}
		int[][] s = precalcS(maxL, MOD);
		maxL = min(maxL, m);
		int[] a = precalcA(MOD, m, maxL);
		int[] d = new int[maxL + 1];
		int[] fact = precalcFact(maxL, MOD);
		int last = 0;
		for (int l : lArray) {
			long sum = 0;
			for (int i = 1; i <= last; i++) {
				sum += modMul(d[i], a[i], MOD);
			}
			if (last == 0) {
				sum = 1;
			}
			sum %= MOD;
			int[] cur = s[l];
			for (int i = 1; i <= min(l, m); i++) {
				int ok = (int) sum;
				if (i <= last) {
					ok -= modMul(d[i], fact[i], MOD);
					if (ok < 0) {
						ok += MOD;
					}
				}
				d[i] = modMul(cur[i], ok, MOD);
			}
			last = min(m, l);
		}
		long answer = 0;
		for (int i = 1; i <= last; i++) {
			answer += modMul(d[i], a[i], MOD);
		}
		answer %= MOD;
		out.println(answer);
	}

	static int[] precalcFact(int max, int MOD) {
		int[] f = new int[max + 1];
		f[0] = 1;
		for (int i = 0; i < max; i++) {
			f[i + 1] = modMul(f[i], i + 1, MOD);
		}
		return f;
	}

	static int[][] precalcS(int max, int MOD) {
		int[][] s = new int[max + 1][];
		for (int i = 0; i <= max; i++) {
			s[i] = new int[i + 1];
		}
		s[1][1] = 1;
		for (int l = 1; l < max; l++) {
			int[] cur = s[l];
			int[] next = s[l + 1];
			for (int colors = l; colors > 0; --colors) {
				next[colors + 1] += cur[colors];
				if (next[colors + 1] >= MOD) {
					next[colors + 1] -= MOD;
				}
				next[colors] = modMul(cur[colors], colors - 1, MOD);
			}
		}
		return s;
	}

	static int[] precalcA(int mod, int m, int max) {
		int[] a = new int[max + 1];
		a[0] = 1;
		for (int i = 1; i <= max; i++) {
			a[i] = modMul(a[i - 1], m - i + 1, mod);
		}
		return a;
	}

	static int modMul(int a, int b, int mod) {
		return (int) ((long) a * b % mod);
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static PrintWriter out;

	static int nextInt() throws IOException {
		int m = 0;
		int c = br.read();
		while (c < '0' || c > '9')
			c = br.read();
		while (c >= '0' && c <= '9') {
			m = m * 10 + c - '0';
			c = br.read();
		}
		return m;
	}
}