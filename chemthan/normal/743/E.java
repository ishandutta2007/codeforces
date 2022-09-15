import java.io.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	static void solve() {
		int n = Input.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Input.nextInt() - 1;
		}
		int[][][] nxt = new int[n][n + 1][8];
		for (int[][] x : nxt) for (int[] y : x) Arrays.fill(y, n);
		for (int i = 0; i < n; i++) {
			int[] cnt = new int[8];
			for (int k = 0; k < 8; k++) {
				nxt[i][0][k] = i - 1;
			}
			for (int j = i; j < n; j++) {
				cnt[a[j]]++;
				for (int k = 0; k < 8; k++) {
					nxt[i][cnt[k]][k] = Math.min(nxt[i][cnt[k]][k], j);
				}
			}
		}
		int ans = 0;
		for (int k = 0; k <= n; k++) {
			int[][] dp = new int[n + 1][1 << 8];
			for (int[] x : dp) Arrays.fill(x, -INF);
			dp[0][0] = 0;
			for (int i = 0; i < n; i++) {
				for (int msk = 0; msk < (1 << 8); msk++) if (dp[i][msk] >= 0) {
					for (int j = 0; j < 8; j++) {
						if (((msk >> j) & 1) == 0) {
							int nmsk = msk ^ (1 << j);
							int ni = nxt[i][k][j];
							if (ni < n) {
								dp[ni + 1][nmsk] = Math.max(dp[ni + 1][nmsk], dp[i][msk] + k);
							}
							if (k < n) {
								ni = nxt[i][k + 1][j];
								if (ni < n) {
									dp[ni + 1][nmsk] = Math.max(dp[ni + 1][nmsk], dp[i][msk] + k + 1);
								}
							}
						}
					}
				}
			}
			for (int i = 0; i <= n; i++) {
				ans = Math.max(ans, dp[i][(1 << 8) - 1]);
			}
		}
		out.println(ans);
	}
	
	public static void main(String[] args) {
		try {
			out = new PrintWriter(System.out);
			//out = new PrintWriter(new FileWriter("a.out"));
		}
		catch (Exception ex) {
		}
		long stime = System.currentTimeMillis();
		solve();
		if (System.getProperty("ONLINE_JUDGE") == null) {
			out.println("\nTime elapsed: " + (System.currentTimeMillis() - stime) + "ms");
		}
		out.close();
	}
	
	static class Input {
		static StringTokenizer token = null;
		static BufferedReader in;
		static {
			try {
				if (System.getProperty("ONLINE_JUDGE") == null) {
					in = new BufferedReader(new FileReader("in.txt"));
				}
				else {
					in = new BufferedReader(new InputStreamReader(System.in));
				}
			}
			catch (Exception ex) {
			}
		}
		static int nextInt() {
			return Integer.parseInt(nextString());
		}
		static long nextLong() {
			return Long.parseLong(nextString());
		}
		static double nextDouble() {
			return Double.parseDouble(nextString());
		}
		static String nextString() {
			try {
				while (token == null || !token.hasMoreTokens()) {
					token = new StringTokenizer(in.readLine());
				}
			}
			catch (IOException e) {
			}
			return token.nextToken();
		}
	}
}