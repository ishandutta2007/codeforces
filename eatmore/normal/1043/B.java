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

public class B {

	static void solve() throws Exception {
		int n = scanInt();
		int x[] = new int[n];
		int p[] = new int[n + 1];
		p[0] = -1;
		int prev = 0;
		for (int i = 0; i < n; i++) {
			x[i] = scanInt() - prev;
			prev += x[i];
			int cp = p[i];
			while (cp >= 0 && x[i] != x[cp]) {
				cp = p[cp];
			}
			p[i + 1] = cp + 1;
		}
		List<Integer> ans = new ArrayList<>();
		for (int cp = p[n]; cp >= 0; cp = p[cp]) {
			ans.add(n - cp);
		}
		out.println(ans.size());
		for (int i = 0; i < ans.size(); i++) {
			out.print(ans.get(i) + " ");
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