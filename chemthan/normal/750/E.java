import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
	
	Input in;
	PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = (double) Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		String s = in.nextString();
		int[][] st = new int[n << 1][25];
		for (int p = n; p < n + n; p++) {
			Arrays.fill(st[p], INF);
			for (int i = 0; i < 5; i++) st[p][i * 5 + i] = 0;
			if (s.charAt(p - n) == '2') {
				st[p][0 * 5 + 0] = 1;
				st[p][0 * 5 + 1] = 0;
			}
			else if (s.charAt(p - n) == '0') {
				st[p][1 * 5 + 1] = 1;
				st[p][1 * 5 + 2] = 0;
			}
			else if (s.charAt(p - n) == '1') {
				st[p][2 * 5 + 2] = 1;
				st[p][2 * 5 + 3] = 0;
			}
			else if (s.charAt(p - n) == '7') {
				st[p][3 * 5 + 3] = 1;
				st[p][3 * 5 + 4] = 0;
			}
			else if (s.charAt(p - n) == '6') {
				st[p][3 * 5 + 3] = 1;
				st[p][4 * 5 + 4] = 1;
			}
		}
		for (int p = n - 1; p > 0; p--) {
			st[p] = merge(st[p << 1], st[p << 1 | 1]);
		}
		while (q-- > 0) {
			int l = in.nextInt() - 1;
			int r = in.nextInt() - 1;
			int ans = query(st, l, r, n)[0 * 5 + 4];
			if (ans == INF) ans = -1;
			out.println(ans);
		}
	}
	
	int[] query(int[][]st, int l, int r, int n) {
		int[] lres = new int[25];
		int[] rres = new int[25];
		Arrays.fill(lres, INF);
		Arrays.fill(rres, INF);
		for (int i = 0; i < 5; i++) {
			lres[i * 5 + i] = rres[i * 5 + i] = 0;
		}
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if ((l & 1) == 1) {
				lres = merge(lres, st[l++]);
			}
			if ((r & 1) == 1) {
				rres = merge(st[--r], rres);
			}
		}
		return merge(lres, rres);
	}
	
	int[] merge(int[] l, int[] r) {
		int[] res = new int[25];
		Arrays.fill(res, INF);
		for (int i = 0; i < 5; i++) {
			for (int j = i; j < 5; j++) {
				for (int k = j; k < 5; k++) {
					res[i * 5 + k] = Math.min(res[i * 5 + k], l[i * 5 + j] + r[j * 5 + k]);
				}
			}
		}
		return res;
	}
	
	public static void main(String[] args) {
		(new Main()).run();
	}
	
	public void run() {
		in = new Input();
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
	
	public class Input {
		StringTokenizer token = null;
		BufferedReader in;
		public Input() {
			try {
				if (System.getProperty("ONLINE_JUDGE") == null) {
					in = new BufferedReader(new InputStreamReader(System.in));
					in = new BufferedReader(new FileReader("in.txt"));
				}
				else {
					in = new BufferedReader(new InputStreamReader(System.in));
				}
			}
			catch (Exception ex) {
			}
		}
		int nextInt() {
			return Integer.parseInt(nextString());
		}
		long nextLong() {
			return Long.parseLong(nextString());
		}
		double nextDouble() {
			return Double.parseDouble(nextString());
		}
		String nextString() {
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