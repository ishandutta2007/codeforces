import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		String s[][] = new String[n][m];
		int len = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				s[i][j] = scanString();
				len += s[i][j].length();
			}
		}
		String t[][] = new String[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				t[i][j] = scanString();
			}
		}
		int c0[] = new int[n], c1[] = new int[n];
		int ans1[] = new int[4 * len];
		int ansPos = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				String cur = s[i][j];
				for (int k = cur.length() - 1; k >= 0; k--) {
					int dj = cur.charAt(k) - '0';
					int di = j == dj ? (i + 1) % n : i;
					ans1[ansPos++] = i;
					ans1[ansPos++] = j;
					ans1[ansPos++] = di;
					ans1[ansPos++] = dj;
					++(dj == 0 ? c0 : c1)[di];
				}
			}
		}
		int c2[] = new int[n], c3[] = new int[n];
		int ans2[] = new int[4 * len];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				String cur = t[i][j];
				for (int k = 0; k < cur.length(); k++) {
					int dj = cur.charAt(k) - '0';
					int di = j == dj ? (i + 1) % n : i;
					ans2[--ansPos] = j;
					ans2[--ansPos] = i;
					ans2[--ansPos] = dj;
					ans2[--ansPos] = di;
					++(dj == 0 ? c2 : c3)[di];
				}
			}
		}
		int ans3[] = new int[4 * len];
		for (int p1 = 0, p2 = 0;;) {
			while (p1 < n && c0[p1] <= c2[p1]) {
				++p1;
			}
			while (p2 < n && c0[p2] >= c2[p2]) {
				++p2;
			}
			if (p1 == n || p2 == n) {
				break;
			}
			while (c0[p1] > c2[p1] && c0[p2] < c2[p2]) {
				--c0[p1];
				++c0[p2];
				ans3[ansPos++] = p1;
				ans3[ansPos++] = 0;
				ans3[ansPos++] = p2;
				ans3[ansPos++] = 0;
			}
		}
		for (int p1 = 0, p2 = 0;;) {
			while (p1 < n && c1[p1] <= c3[p1]) {
				++p1;
			}
			while (p2 < n && c1[p2] >= c3[p2]) {
				++p2;
			}
			if (p1 == n || p2 == n) {
				break;
			}
			while (c1[p1] > c3[p1] && c1[p2] < c3[p2]) {
				--c1[p1];
				++c1[p2];
				ans3[ansPos++] = p1;
				ans3[ansPos++] = 1;
				ans3[ansPos++] = p2;
				ans3[ansPos++] = 1;
			}
		}
//		StringBuilder states[][] = new StringBuilder[n][m];
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				states[i][j] = new StringBuilder(s[i][j]);
//			}
//		}
		out.println(2 * len + ansPos / 4);
		for (int i = 0; i < 4 * len; i += 4) {
			out.println((ans1[i] + 1) + " " + (ans1[i + 1] + 1) + " " + (ans1[i + 2] + 1) + " " + (ans1[i + 3] + 1));
//			StringBuilder cs = states[ans1[i]][ans1[i + 1]];
//			char c = cs.charAt(cs.length() - 1);
//			cs.setLength(cs.length() - 1);
//			states[ans1[i + 2]][ans1[i + 3]].insert(0, c);
		}
		for (int i = 0; i < ansPos; i += 4) {
			out.println((ans3[i] + 1) + " " + (ans3[i + 1] + 1) + " " + (ans3[i + 2] + 1) + " " + (ans3[i + 3] + 1));
//			StringBuilder cs = states[ans3[i]][ans3[i + 1]];
//			char c = cs.charAt(cs.length() - 1);
//			cs.setLength(cs.length() - 1);
//			states[ans3[i + 2]][ans3[i + 3]].insert(0, c);
		}
		for (int i = 0; i < 4 * len; i += 4) {
			out.println((ans2[i] + 1) + " " + (ans2[i + 1] + 1) + " " + (ans2[i + 2] + 1) + " " + (ans2[i + 3] + 1));
//			StringBuilder cs = states[ans2[i]][ans2[i + 1]];
//			char c = cs.charAt(cs.length() - 1);
//			cs.setLength(cs.length() - 1);
//			states[ans2[i + 2]][ans2[i + 3]].insert(0, c);
		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (!states[i][j].toString().equals(t[i][j])) {
//					throw new AssertionError();
//				}
//			}
//		}
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