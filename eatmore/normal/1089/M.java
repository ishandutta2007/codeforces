import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class M {

	static void solve() throws Exception {
		int n = scanInt();
		boolean edge[][] = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				edge[i][j] = scanInt() != 0;
			}
		}
		out.println((6 * n - 1) + " " + (6 * n - 1) + " 3");
		for (int y = 0; y < 6 * n - 1; y++) {
			for (int x = 0; x < 6 * n - 1; x++) {
				if (y / 6 == x / 6 && y % 6 < 5 && x % 6 < 5) {
					out.print('.');
				} else if (y % 6 == 2) {
					out.print('.');
				} else if ((y % 6 == 1 || y % 6 == 3) && x % 6 >= 1 && x % 6 <= 3) {
					out.print('.');
				} else {
					out.print('#');
				}
			}
			out.println();
		}
		out.println();
		for (int y = 0; y < 6 * n - 1; y++) {
			for (int x = 0; x < 6 * n - 1; x++) {
				if (y / 6 == x / 6 && y % 6 < 5 && x % 6 < 5) {
					if (y % 6 == 2 && (x % 6 == 0 || x % 6 == 4)) {
						out.print('#');
					} else {
						out.print('.');
					}
				} else if (x % 6 == 2 && y % 6 == 2 && edge[y / 6][x / 6]) {
					out.print('.');
				} else {
					out.print('#');
				}
			}
			out.println();
		}
		out.println();
		for (int y = 0; y < 6 * n - 1; y++) {
			for (int x = 0; x < 6 * n - 1; x++) {
				if (y / 6 == x / 6 && y % 6 < 5 && x % 6 < 5) {
					if (y % 6 == 2 && x % 6 == 2) {
						out.print((char) ('1' + y / 6));
					} else if (y % 6 == 2) {
						out.print('#');
					} else {
						out.print('.');
					}
				} else if (x % 6 == 2) {
					out.print('.');
				} else {
					out.print('#');
				}
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