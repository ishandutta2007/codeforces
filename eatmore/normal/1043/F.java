import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void solve() throws Exception {
		int n = scanInt();
		int a[] = new int[n];
		int max = 0;
		for (int i = 0; i < n; i++) {
			a[i] = scanInt();
			max = max(max, a[i]);
		}
		boolean have[] = new boolean[max + 1];
		for (int i = 0; i < n; i++) {
			have[a[i]] = true;
		}
		int mul[] = new int[max + 1];
		fill(mul, -1);
		for (int p = 2; p <= max; p++) {
			if (mul[p] >= 0) {
				continue;
			}
			mul[p] = p;
			if (p <= 46340) {
				for (int i = p * p; i <= max; i += p) {
					if (mul[i] < 0) {
						mul[i] = p;
					}
				}
			}
		}
		counts = new int[max + 1];
		factors = new int[10];
		for (int i = 1; i <= max; i++) {
			if (!have[i]) {
				continue;
			}
			int nFactors = 0;
			int prev = 0;
			for (int j = i; j != 1; j /= mul[j]) {
				if (prev != mul[j]) {
					prev = factors[nFactors++] = mul[j];
				}
			}
			go1(nFactors, 1);
		}
		int ans = Integer.MAX_VALUE;
		counts2 = new int[1 << 10];
		int counts3[] = new int[1 << 10];
		int signum[] = new int[1 << 10];
		for (int i = 0; i < signum.length; i++) {
			signum[i] = (Integer.bitCount(i) & 1) != 0 ? -1 : 1;
		}
		for (int i = 1; i <= max; i++) {
			if (!have[i]) {
				continue;
			}
			int nFactors = 0;
			int prev = 0;
			for (int j = i; j != 1; j /= mul[j]) {
				if (prev != mul[j]) {
					prev = factors[nFactors++] = mul[j];
				}
			}
			go2(nFactors, 1, 0);
			for (int j = 0; j < 1 << nFactors; j++) {
				int cur = 0;
				for (int k = j;; k = (k - 1) & j) {
					cur += signum[k] * counts2[k];
					if (k == 0) {
						break;
					}
				}
				int cval = Integer.MAX_VALUE;
				if (j == 0) {
					cval = 0;
				} else if (cur != 0) {
					cval = 1;
				} else {
					for (int k = (j - 1) & j; k != 0; k = (k - 1) & j) {
						if (counts3[k] != Integer.MAX_VALUE && counts3[k ^ j] != Integer.MAX_VALUE) {
							cval = min(cval, counts3[k] + counts3[k ^ j]);
						}
					}
				}
				counts3[j] = cval;
			}
			int v = counts3[(1 << nFactors) - 1];
			if (v != Integer.MAX_VALUE) {
				ans = min(ans, v + 1);
			}
		}
		out.print(ans == Integer.MAX_VALUE ? -1 : ans);
	}

	static int counts[], factors[], counts2[];

	static void go1(int i, int cur) {
		if (i == 0) {
			++counts[cur];
			return;
		}
		--i;
		go1(i, cur);
		go1(i, cur * factors[i]);
	}

	static void go2(int i, int curNum, int curSet) {
		if (i == 0) {
			counts2[curSet] = counts[curNum];
			return;
		}
		--i;
		go2(i, curNum, curSet);
		go2(i, curNum * factors[i], curSet | (1 << i));
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