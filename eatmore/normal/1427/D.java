import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int n = scanInt();
		int a[] = new int[n], aInv[] = new int[n], na[] = new int[n];
		for (int i = 0; i < n; i++) {
			aInv[a[i] = scanInt() - 1] = i;
		}
		List<int[]> ans = new ArrayList<>();
		find: while (true) {
			int ci;
			for (ci = 0;; ci++) {
				if (ci >= n - 1) {
					break find;
				}
				if (aInv[ci + 1] < aInv[ci]) {
					break;
				}
			}
			int p1 = aInv[ci + 1], p3 = aInv[ci] + 1, p2;
			for (p2 = p1 + 1; a[p2 - 1] + 1 == a[p2]; p2++) { }
			int len = 2 + (p1 != 0 ? 1 : 0) + (p3 != n ? 1 : 0);
			int cans[] = new int[len], cpos = 0;
			if (p1 != 0) {
				cans[cpos++] = p1;
			}
			cans[cpos++] = p2 - p1;
			cans[cpos++] = p3 - p2;
			if (p3 != n) {
				cans[cpos++] = n - p3;
			}
			ans.add(cans);
			for (int pOld = 0, pNew = n, j = 0; j < len; j++) {
				int clen = cans[j];
				pNew -= clen;
				for (int jj = 0; jj < clen; jj++) {
					aInv[na[pNew + jj] = a[pOld + jj]] = pNew + jj;
				}
				pOld += clen;
			}
			int t[] = a;
			a = na;
			na = t;
			if (ans.size() == n) {
				throw new AssertionError();
			}
		}
		out.println(ans.size());
		for (int cans[]: ans) {
			out.print(cans.length);
			for (int v: cans) {
				out.print(" " + v);
			}
			out.println();
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