import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

	static final int MOD = 998244353;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static int dsuGet(int dsu[], int i) {
		return dsu[i] == i ? i : (dsu[i] = dsuGet(dsu, dsu[i]));
	}

	static void solve() throws Exception {
		int n = scanInt();
//		int n = 1500;
		int nn = n * (n - 1) / 2;
		int ai[] = new int[nn];
		int aj[] = new int[nn];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a = scanInt();
//				a[i][j] = i < j ? j * (j - 1) / 2 + 1 + i : i > j ? i * (i - 1) / 2 + 1 + j : 0;
				if (i != j) {
					ai[a - 1] = i;
					aj[a - 1] = j;
				}
			}
		}
		int dsu[] = new int[n];
		int curNode[] = new int[n];
		int nextNode = n;
		int nVertices[] = new int[2 * n - 1];
		int nEdges[] = new int[2 * n - 1];
		int ans[][] = new int[2 * n - 1][];
		for (int i = 0; i < n; i++) {
			dsu[i] = i;
			curNode[i] = i;
			nVertices[i] = 1;
			ans[i] = new int[1];
		}
		for (int i = 0; i < nn; i++) {
			int ci = dsuGet(dsu, ai[i]), cj = dsuGet(dsu, aj[i]);
			if (ci != cj) {
				int ni = curNode[ci];
				int vi = nVertices[ni], ei = nEdges[ni];
				if (ei == vi * (vi - 1) / 2) {
					ans[ni][0] = 1;
				}
				int nj = curNode[cj];
				int vj = nVertices[nj], ej = nEdges[nj];
				if (ej == vj * (vj - 1) / 2) {
					ans[nj][0] = 1;
				}
				dsu[ci] = cj;
				int nk = nextNode++;
				curNode[cj] = nk;
				nVertices[nk] = vi + vj;
				nEdges[nk] = ei + ej;
				int ansk[] = ans[nk] = new int[vi + vj];
				int ansi[] = ans[ni], ansj[] = ans[nj];
				for (int ii = 0; ii < vi; ii++) {
					for (int jj = 0; jj < vj; jj++) {
						ansk[ii + jj + 1] = add(ansk[ii + jj + 1], mul(ansi[ii], ansj[jj]));
					}
				}
			}
			++nEdges[curNode[cj]];
		}
		ans[2 * n - 2][0] = 1;
		for (int i = 0; i < n; i++) {
			out.print(ans[2 * n - 2][i] + " ");
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