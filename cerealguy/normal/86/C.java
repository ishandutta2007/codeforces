import java.io.*;
import java.util.*;

public class C {

	final static int MOD = 1000 * 1000 * 1000 + 9;
	static char[] chars = "ACGT".toCharArray();

	static String[] s;
	static int m;
	static HashSet<String> hs;

	public int goodCount(String s, int start) {
		for (int i = start; i < s.length(); i++) {
			boolean ok = false;
			forl: for (int l = 0; l <= i; l++) {
				for (int r = i + 1; r <= s.length(); r++) {
					String s1 = s.substring(l, r);
					if (hs.contains(s1)) {
						ok = true;
						break forl;
					}
				}
			}
			if (!ok) {
				return i;
			}
		}
		return s.length();
	}

	private void solve() throws IOException {
		int n = nextInt();
		m = nextInt();
		hs = new HashSet<String>();
		for (int i = 0; i < m; i++) {
			hs.add(nextToken());
		}
		int len = 0;
		s = (String[]) hs.toArray(new String[hs.size()]);
		for (String s1 : s) {
			len = Math.max(len, s1.length());
		}
		m = s.length;
		int[][][] dp = new int[m][][];
		int[][][] next = new int[m][][];
		for (int i = 0; i < m; i++) {
			dp[i] = new int[s[i].length() + 1][];
			next[i] = new int[s[i].length() + 1][];
			for (int j = 0; j < dp[i].length; j++) {
				dp[i][j] = new int[dp[i].length + 1];
				next[i][j] = new int[dp[i].length + 1];
			}
		}
		dp[0][0][0] = 1;
		Pair[][][][] go = new Pair[m][][][];
		for (int i = 0; i < m; i++) {
			go[i] = new Pair[s[i].length() + 1][s[i].length() + 1][4];
			for (int l = 0; l <= s[i].length(); l++) {
				for (int ok = 0; ok <= l; ok++) {
					for (int j = 0; j < 4; j++) {
						String s1 = s[i].substring(0, l) + chars[j];
						Pair p = get(s1, ok);
						go[i][l][ok][j] = p;
					}
				}
			}
		}
		for (int it = 0; it < n; it++) {
			// System.err.println((it));
			for (int i = 0; i < m; i++) {
				for (int[] next1 : next[i])
					Arrays.fill(next1, 0);
			}
			for (int i = 0; i < m; i++) {
				// System.err.println(Arrays.toString(dp[i]));
				for (int j = 0; j <= s[i].length(); j++) {
					for (int ok = 0; ok <= j; ok++) {
						if (dp[i][j][ok] == 0)
							continue;
						for (int ch = 0; ch < 4; ch++) {
							Pair p = go[i][j][ok][ch];
							if (p == null)
								continue;
							next[p.a][p.b][p.c] += dp[i][j][ok];
							if (next[p.a][p.b][p.c] >= MOD) {
								next[p.a][p.b][p.c] -= MOD;
							}
						}
					}
				}
			}
			int[][][] tmp = dp;
			dp = next;
			next = tmp;
		}
		int res = 0;
		for (int i = 0; i < m; i++) {
			// System.err.println(Arrays.toString(dp[i]));
			for (int j = 0; j <= s[i].length(); j++) {
				res += dp[i][j][j];
				if (res >= MOD) {
					res -= MOD;
				}
			}
		}
		out.println(res);
	}

	static class Pair {
		int a, b, c;

		public Pair(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}
	}

	Pair get(String t, int ok) {
		for (int i = 0; i < t.length(); i++) {
			String t1 = t.substring(i);
			for (int j = 0; j < m; j++) {
				if (s[j].startsWith(t1)) {
					int len = t1.length();
					int goodcnt = goodCount(t, ok);
					goodcnt -= i;
					if (goodcnt < 0)
						return null;
					else
						return new Pair(j, len, goodcnt);
				}
			}
		}
		return null;
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}