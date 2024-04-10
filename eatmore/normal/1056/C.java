import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {

	static void solve() throws Exception {
		int n = scanInt();
		int m = scanInt();
		int strength[] = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			strength[i] = scanInt();
		}
		int pair[] = new int[2 * n];
		fill(pair, -1);
		for (int i = 0; i < m; i++) {
			int a = scanInt() - 1, b = scanInt() - 1;
			pair[a] = b;
			pair[b] = a;
		}
		boolean taken[] = new boolean[2 * n];
		int mustTake = -1;
		int remains = 2 * n;
		if (scanInt() == 2) {
			int theirTurn = scanInt() - 1;
			taken[theirTurn] = true;
			--remains;
			mustTake = pair[theirTurn];
		}
		while (remains > 0) {
			int myTurn;
			if (mustTake >= 0 && !taken[mustTake]) {
				myTurn = mustTake;
			} else {
				myTurn = -1;
				for (int i = 0; i < 2 * n; i++) {
					if (!taken[i] && pair[i] >= 0) {
						myTurn = strength[pair[i]] > strength[i] ? pair[i] : i;
						break;
					}
				}
				if (myTurn < 0) {
					for (int i = 0; i < 2 * n; i++) {
						if (!taken[i] && (myTurn < 0 || strength[i] > strength[myTurn])) {
							myTurn = i;
						}
					}
				}
			}
			out.println(myTurn + 1);
			out.flush();
			taken[myTurn] = true;
			--remains;
			if (remains == 0) {
				break;
			}
			int theirTurn = scanInt() - 1;
			taken[theirTurn] = true;
			--remains;
			mustTake = pair[theirTurn];
			if (mustTake >= 0 && taken[mustTake]) {
				mustTake = -1;
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