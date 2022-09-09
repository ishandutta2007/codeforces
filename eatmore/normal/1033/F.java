import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

	static void go(int bit, int cur) {
		if (bit < 0) {
			pats[cur] += goAdd;
		} else {
			go(bit - 1, cur + (((goV & (1 << bit)) != 0) ? p3[bit] : 0));
			go(bit - 1, cur + 2 * p3[bit]);
		}
	}

	static void go2(int bit, int curNum, int curPat) {
		if (bit < 0) {
			if (curPat < pats.length) {
				goAns += cnts[curNum] * pats[curPat];
			}
		} else {
			go2(bit - 1, curNum, curPat + pat0[bit]);
			go2(bit - 1, curNum + (1 << bit), curPat + pat1[bit]);
		}
	}

	static int goV, goAdd, cnts[], p3[], pats[], pat0[], pat1[], goAns;

	static void solve() throws Exception {
		int w = scanInt();
		int n = scanInt();
		int m = scanInt();
		cnts = new int[1 << w];
		for (int i = 0; i < n; i++) {
			++cnts[scanInt()];
		}
		p3 = new int[w];
		p3[0] = 1;
		for (int i = 1; i < w; i++) {
			p3[i] = 3 * p3[i - 1];
		}
		pats = new int[3 * p3[w - 1]];
		for (goV = 0; goV < 1 << w; goV++) {
			goAdd = cnts[goV];
			go(w - 1, 0);
		}
		pat0 = new int[w];
		pat1 = new int[w];
		for (int i = 0; i < m; i++) {
			String f = scanString();
			for (int j = 0; j < w; j++) {
				switch (f.charAt(w - j - 1)) {
				case 'A':
					pat0[j] = 2 * p3[j];
					pat1[j] = 0;
					break;
				case 'O':
					pat0[j] = 0;
					pat1[j] = pats.length;
					break;
				case 'X':
					pat0[j] = 0;
					pat1[j] = p3[j];
					break;
				case 'a':
					pat0[j] = pats.length;
					pat1[j] = p3[j];
					break;
				case 'o':
					pat0[j] = p3[j];
					pat1[j] = 2 * p3[j];
					break;
				case 'x':
					pat0[j] = p3[j];
					pat1[j] = 0;
					break;
				default:
					throw new AssertionError();
				}
			}
			goAns = 0;
			go2(w - 1, 0, 0);
			out.println(goAns);
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