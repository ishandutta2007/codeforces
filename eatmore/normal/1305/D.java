import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static int query(int a, int b) throws IOException {
		out.println("? " + (a + 1) + " " + (b + 1));
		out.flush();
		return scanInt() - 1;
	}

	static void solve() throws Exception {
		int n = scanInt();
		boolean e[][] = new boolean[n][n];
		int deg[] = new int[n];
		for (int i = 0; i < n - 1; i++) {
			int a = scanInt() - 1, b = scanInt() - 1;
			e[a][b] = e[b][a] = true;
			++deg[a];
			++deg[b];
		}
		int cur = 0;
		while (true) {
			if (deg[cur] == 0) {
				out.println("! " + (cur + 1));
				return;
			}
			if (deg[cur] == 1) {
				int next;
				for (next = 0; !e[cur][next]; next++) { }
				if (deg[next] == 1) {
					--deg[cur];
					--deg[next];
					e[cur][next] = e[next][cur] = false;
					cur = query(cur, next);
					continue;
				}
				cur = next;
			}
			int n1, n2;
			for (n1 = 0; !e[cur][n1]; n1++) { }
			for (n2 = n1 + 1; !e[cur][n2]; n2++) { }
			deg[cur] -= 2;
			--deg[n1];
			--deg[n2];
			e[cur][n1] = e[n1][cur] = e[cur][n2] = e[n2][cur] = false;
			cur = query(n1, n2);
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