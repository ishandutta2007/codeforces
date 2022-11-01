import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		String s = nextToken(), t = nextToken();
		int answer = get(s, t);
		out.println(answer);
	}

	static final int MOD = 1000000007;

	static int get(String s, String t) {
		int[] dp = new int[t.length() + 1];
		int[] next = new int[t.length() + 1];
		fill(dp, 1);
		long answer = 0;
		for (int sPos = 0; sPos < s.length(); sPos++) {
			char sCur = s.charAt(sPos);
			for (int tPos = 0; tPos < t.length(); tPos++) {
				char tCur = t.charAt(tPos);
				if (tCur == sCur) {
					next[tPos + 1] += dp[tPos];
					if (next[tPos + 1] >= MOD) {
						next[tPos + 1] -= MOD;
					}
				}
			}
			next[0] = 1;
			for (int i = 0; i < t.length(); i++) {
				next[i + 1] += next[i];
				if (next[i + 1] >= MOD) {
					next[i + 1] -= MOD;
				}
			}
			answer += next[t.length()] - 1;
			int[] tmp = dp;
			dp = next;
			next = tmp;
			fill(next, 0);
		}
		answer %= MOD;
		if (answer < 0) {
			answer += MOD;
		}
		return (int) answer;
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