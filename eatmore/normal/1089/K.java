import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class K {

	static void sortBy(int a[], int v[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			int cv = v[ca];
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
			int cv = v[ca];
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

	static int treeN;
	static long treeAdd[], treeMax[];

	static void treePush(int i) {
		if (i < treeN) {
			long v = treeAdd[i];
			if (v != 0) {
				treeAdd[i << 1] += v;
				treeMax[i << 1] += v;
				treeAdd[(i << 1) + 1] += v;
				treeMax[(i << 1) + 1] += v;
				treeAdd[i] = 0;
			}
		}
	}

	static void treeFix(int i) {
		treeMax[i] = max(treeMax[i << 1], treeMax[(i << 1) + 1]) + treeAdd[i];
	}

	static void treeAdd(int from, int to, long v) {
		if (from == to) {
			return;
		}
		from += treeN;
		to += treeN;
		int x = from;
		for (int i = 31 - Integer.numberOfLeadingZeros(x); i >= 0; i--) {
			treePush(x >> i);
		}
		int y = 0;
		while (x < to) {
			if ((x & ((1 << (y + 1)) - 1)) == 0 && x + (1 << (y + 1)) <= to) {
				++y;
			} else if (x + (1 << y) > to) {
				--y;
			} else {
				for (int i = Integer.numberOfTrailingZeros(x); i >= y; i--) {
					treePush(x >> i);
				}
				treeAdd[x >> y] += v;
				treeMax[x >> y] += v;
				for (int i = 1, l = 31 - Integer.numberOfLeadingZeros(x >> y); i <= l; i++) { // XXX
					treeFix(x >> (y + i));
				}
				x += 1 << y;
			}
		}
	}

	static long treeGet(int from, int to) {
		from += treeN;
		to += treeN;
		long res = Long.MIN_VALUE;
		int x = from;
		for (int i = 31 - Integer.numberOfLeadingZeros(x); i > 0; i--) {
			treePush(x >> i);
		}
		int y = 0;
		while (x < to) {
			if ((x & ((1 << (y + 1)) - 1)) == 0 && x + (1 << (y + 1)) <= to) {
				++y;
			} else if (x + (1 << y) > to) {
				--y;
			} else {
				for (int i = Integer.numberOfTrailingZeros(x); i >= y; i--) {
					treePush(x >> i);
				}
				res = max(res, treeMax[x >> y]);
				x += 1 << y;
			}
		}
		return res;
	}

	static void solve() throws Exception {
		int q = scanInt();
		int type[] = new int[q];
		int t[] = new int[q];
		int d[] = new int[q];
		int idx[] = new int[q];
		for (int i = 0; i < q; i++) {
			idx[i] = i;
			switch (scanString().charAt(0)) {
			case '+':
				type[i] = 0;
				t[i] = 2 * scanInt();
				d[i] = scanInt();
				break;
			case '-':
				type[i] = 1;
				t[i] = scanInt() - 1;
				break;
			case '?':
				type[i] = 2;
				t[i] = 2 * scanInt() + 1;
			}
		}
		sortBy(idx, t);
		int pos[] = new int[q];
		for (int i = 0; i < q; i++) {
			pos[idx[i]] = i;
		}
		treeN = q;
		treeAdd = new long[2 * treeN];
		treeMax = new long[2 * treeN];
		fill(treeMax, Long.MIN_VALUE / 2);
		for (int i = 0; i < q; i++) {
			if (type[i] == 0 || type[i] == 2) {
				treeMax[treeN + pos[i]] = t[i] >> 1;
			}
		}
		for (int i = treeN - 1; i > 0; i--) {
			treeFix(i);
		}
		for (int i = 0; i < q; i++) {
			switch (type[i]) {
			case 0:
				treeAdd(pos[i] + 1, q, -d[i]);
				break;
			case 1:
				treeAdd(pos[t[i]] + 1, q, d[t[i]]);
				break;
			case 2:
				out.println(treeGet(0, pos[i] + 1) - treeGet(pos[i], pos[i] + 1));
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