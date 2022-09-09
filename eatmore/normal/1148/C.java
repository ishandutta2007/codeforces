import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int n = scanInt();
		int p[] = new int[n], pi[] = new int[n];
		for (int i = 0; i < n; i++) {
			pi[p[i] = scanInt() - 1] = i;
		}
		int ans[] = new int[6 * n], ansPos = 0;
		for (int i = 0; i < n / 2; i++) {
			int cur = n / 2 + i;
			if (p[cur] != cur) {
				int pCur = pi[cur];
				while (abs(pCur - cur) < n / 2) {
					int nCur = pCur >= n / 2 ? 0 : n - 1;
					ans[2 * ansPos] = pCur;
					ans[2 * ansPos + 1] = nCur;
					++ansPos;
					pi[p[pCur] = p[nCur]] = pCur;
					pi[p[nCur] = cur] = nCur;
					pCur = nCur;
				}
				ans[2 * ansPos] = pCur;
				ans[2 * ansPos + 1] = cur;
				++ansPos;
				pi[p[pCur] = p[cur]] = pCur;
				pi[p[cur] = cur] = cur;
			}
			cur = n / 2 - i - 1;
			if (p[cur] != cur) {
				int pCur = pi[cur];
				while (abs(pCur - cur) < n / 2) {
					int nCur = pCur >= n / 2 ? 0 : n - 1;
					ans[2 * ansPos] = pCur;
					ans[2 * ansPos + 1] = nCur;
					++ansPos;
					pi[p[pCur] = p[nCur]] = pCur;
					pi[p[nCur] = cur] = nCur;
					pCur = nCur;
				}
				ans[2 * ansPos] = pCur;
				ans[2 * ansPos + 1] = cur;
				++ansPos;
				pi[p[pCur] = p[cur]] = pCur;
				pi[p[cur] = cur] = cur;
			}
		}
		out.println(ansPos);
		for (int i = 0; i < ansPos; i++) {
			out.println((ans[2 * i] + 1) + " " + (ans[2 * i + 1] + 1));
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