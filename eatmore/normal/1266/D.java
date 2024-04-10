import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		long bal[] = new long[n];
		for (int i = 0; i < m; i++) {
			int u = scanInt() - 1, v = scanInt() - 1, d = scanInt();
			bal[u] += d;
			bal[v] -= d;
		}
		int ansU[] = new int[n], ansV[] = new int[n];
		long ansD[] = new long[n];
		int ansCnt = 0;
		for (int p1 = 0, p2 = 0;;) {
			while (p1 < n && bal[p1] <= 0) {
				++p1;
			}
			while (p2 < n && bal[p2] >= 0) {
				++p2;
			}
			if (p1 == n || p2 == n) {
				break;
			}
			ansU[ansCnt] = p1;
			ansV[ansCnt] = p2;
			long d = ansD[ansCnt] = min(bal[p1], -bal[p2]);
			bal[p1] -= d;
			bal[p2] += d;
			++ansCnt;
		}
		out.println(ansCnt);
		for (int i = 0; i < ansCnt; i++) {
			out.println((ansU[i] + 1) + " " + (ansV[i] + 1) + " " + ansD[i]);
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