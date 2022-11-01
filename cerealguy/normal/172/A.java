import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		int n = nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextToken();
		}
		int ans = 0;
		ok: for (; ans < s[0].length(); ans++) {
			for (int i = 1; i < n; i++) {
				if (s[i].length() <= ans || s[i].charAt(ans) != s[0].charAt(ans)) {
					break ok;
				}
			}
		}
		out.println(ans);
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}