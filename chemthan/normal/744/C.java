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
		char[] c = new char[n];
		int[] r = new int[n];
		int[] b = new int[n];
		int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			c[i] = Input.nextString().charAt(0);
			r[i] = Input.nextInt();
			b[i] = Input.nextInt();
			x += Math.max(r[i] - n, 0);
			y += Math.max(b[i] - n, 0);
			r[i] = Math.min(r[i], n);
			b[i] = Math.min(b[i], n);
		}
		int[] f = new int[1 << n];
		int[] g = new int[1 << n];
		for (int msk = 0; msk < (1 << n); msk++) {
			for (int i = 0; i < n; i++) {
				if (((msk >> i) & 1) == 1) {
					if (c[i] == 'R') {
						f[msk]++;
					}
					else {
						g[msk]++;
					}
				}
			}
		}
		int[][][] dp = new int[1 << n][2][n * n + 1];
		for (int msk = 0; msk < (1 << n); msk++) {
			for (int u = 0; u < 2; u++) {
				for (int v = 0; v <= n * n; v++) {
					dp[msk][u][v] = INF;
				}
			}
		}
		dp[0][0][0] = 0;
		int[][] submsk = new int[1 << n][];
		for (int msk = 0; msk < (1 << n); msk++) {
			int sz = Integer.bitCount(msk ^ ((1 << n) - 1));
			submsk[msk] = new int[sz];
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (((msk >> i) & 1) == 0) {
					submsk[msk][cnt++] = i;
				}
			}
		}
		for (int msk = 0; msk < (1 << n); msk++) {
			for (int u = 0; u < 2; u++) {
				for (int v = 0; v <= n * n; v++) if (dp[msk][u][v] < INF) {
					for (int j = 0; j < submsk[msk].length; j++) {
						int i = submsk[msk][j];
						int nmsk = msk ^ (1 << i);
						int cr = 0, cb = 0;
						if (u == 0) {
							cr = v;
						}
						else {
							cb = v;
						}
						int rr = Math.max(r[i] - f[msk], 0);
						int bb = Math.max(b[i] - g[msk], 0);
						int need = Math.max(rr - cr, Math.max(bb - cb, 0));
						int nr = cr + need - rr;
						int nb = cb + need - bb;
						int nu = nr > 0 ? 0 : 1;
						int nv = Math.max(nr, nb);
						if (nv <= n * n) {
							dp[nmsk][nu][nv] = Math.min(dp[nmsk][nu][nv], dp[msk][u][v] + need + 1);
						}
					}
				}
			}
		}
		int ans = INF;
		for (int u = 0; u < 2; u++) {
			for (int v = 0; v <= n * n; v++) {
				int cr = 0, cb = 0;
				if (u == 0) {
					cr = v;
				}
				else {
					cb = v;
				}
				ans = Math.min(ans, dp[(1 << n) - 1][u][v] + Math.max(Math.max(x - cr, y - cb), 0));
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