import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void sort(int a[], int n) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (ca <= na) {
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
				j += (a[j + 2] > a[j + 1]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
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

	static void sortBy(int a[], int n, int v[]) {
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

	static void solve() throws Exception {
		int n = scanInt();
		int s[] = new int[n];
		int sidx[] = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = scanInt();
			sidx[i] = i;
		}
		int t[] = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = scanInt();
		}
		sortBy(sidx, n, s);
		sort(t, n);
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += t[i] - s[sidx[i]];
			if (sum < 0) {
				out.print("NO");
				return;
			}
		}
		if (sum != 0) {
			out.print("NO");
			return;
		}
		int ansI[] = new int[n], ansJ[] = new int[n], ansD[] = new int[n], ansN = 0;
		for (int p1 = 0, p2 = 0;;) {
			while (p1 < n && t[p1] <= s[sidx[p1]]) {
				++p1;
			}
			while (p2 < n && t[p2] >= s[sidx[p2]]) {
				++p2;
			}
			if (p1 == n && p2 == n) {
				break;
			}
			int i = ansI[ansN] = sidx[p1];
			int j = ansJ[ansN] = sidx[p2];
			int d = ansD[ansN++] = min(t[p1] - s[i], s[j] - t[p2]);
			s[i] += d;
			s[j] -= d;
		}
		out.println("YES");
		out.println(ansN);
		for (int i = 0; i < ansN; i++) {
			out.println((ansI[i] + 1) + " " + (ansJ[i] + 1) + " " + ansD[i]);
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