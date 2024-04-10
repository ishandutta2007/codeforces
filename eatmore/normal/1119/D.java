import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {

	static void sort(long a[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			long ca = a[i];
			do {
				int nj = (j - 1) >> 1;
		long na = a[nj];
				if (ca <= na) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		long ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (a[j + 2] > a[j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			long na = a[i];
			a[i] = ca;
			ca = na;
			while (j != 0 && a[j] < ca) {
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

	static void sortBy(int a[], long v[]) {
		int n = a.length;
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

	static class Token implements Comparable<Token> {
		final int i;
		final long w;

		Token(int i, long w) {
			this.i = i;
			this.w = w;
		}

		public int compareTo(Token o) {
			return Long.compare(w, o.w);
		}
	}

	static void solve() throws Exception {
		int n = scanInt();
		long s[] = new long[n];
		for (int i = 0; i < n; i++) {
			s[i] = scanLong();
		}
		sort(s);
		long w[] = new long[n];
		int next[] = new int[n];
		int cnt = n;
		for (int i = 1; i < n; i++) {
			next[i - 1] = i;
		}
		next[n - 1] = -1;
		long sumW = 0;
		PriorityQueue<Token> tokens = new PriorityQueue<>();
		for (int i = 0; i < n - 1; i++) {
			tokens.add(new Token(i, s[i + 1] - s[i]));
		}
		int q = scanInt();
		long qw[] = new long[q];
		int idx[] = new int[q];
		for (int i = 0; i < q; i++) {
			qw[i] = 1 - scanLong() + scanLong();
			idx[i] = i;
		}
		sortBy(idx, qw);
		long ans[] = new long[q];
		for (int i: idx) {
			long cqw = qw[i];
			while (true) {
				Token cur = tokens.peek();
				if (cur == null || cur.w > cqw) {
					break;
				}
				tokens.remove();
				int i1 = cur.i, i2 = next[i1];
				if (i2 < 0) {
					continue;
				}
				if (s[i2] - s[i1] - w[i1] > cqw) {
					continue;
				}
				next[i1] = next[i2];
				next[i2] = Integer.MIN_VALUE;
				--cnt;
				sumW -= w[i2] + w[i1];
				w[i1] = w[i2] + (s[i2] - s[i1]);
				sumW += w[i1];
				if (next[i1] >= 0) {
					tokens.add(new Token(i1, s[next[i1]] - s[i1] - w[i1]));
				}
			}
//			System.err.println(sumW + " " + cqw + " " + cnt);
			ans[i] = sumW + cqw * cnt;
		}
		for (int i = 0; i < q; i++) {
			out.print(ans[i] + " ");
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