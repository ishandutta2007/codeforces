import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static int dsuGet(int dsu[], int i) {
		return dsu[i] == i ? i : (dsu[i] = dsuGet(dsu, dsu[i]));
	}

	static boolean dsuMerge(int dsu[], int i, int j) {
		i = dsuGet(dsu, i);
		j = dsuGet(dsu, j);
		if (i == j) {
			return false;
		}
		dsu[j] = i;
		return true;
	}

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt(), dsu[] = new int[m], ans = 1, ansV[] = new int[n], ansCnt = 0;
		for (int i = 0; i < m; i++) {
			dsu[i] = i;
		}
		boolean have[] = new boolean[m];
		for (int i = 0; i < n; i++) {
			switch (scanInt()) {
			case 1:
			{
				int a = dsuGet(dsu, scanInt() - 1);
				if (!have[a]) {
					ans = add(ans, ans);
					have[a] = true;
					ansV[ansCnt++] = i;
				}
			}
			break;
			case 2:
			{
				int a = dsuGet(dsu, scanInt() - 1), b = dsuGet(dsu, scanInt() - 1);
				if (a != b && !(have[a] & have[b])) {
					ans = add(ans, ans);
					dsuMerge(dsu, a, b);
					have[a] |= have[b];
					ansV[ansCnt++] = i;
				}
			}
			break;
			default:
				throw new AssertionError();
			}
		}
		out.println(ans + " " + ansCnt);
		for (int i = 0; i < ansCnt; i++) {
			out.print(ansV[i] + 1);
			out.print(' ');
		}
	}

	static int scanInt() throws IOException {
		return (int) scanLong();
	}

	static long scanLong() throws IOException {
		int c;
		while ((c = in.read()) < '0' || c > '9') { }
		long v = c - '0';
		while ((c = in.read()) >= '0' && c <= '9') {
			v = v * 10 + (c - '0');
		}
		return v;
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