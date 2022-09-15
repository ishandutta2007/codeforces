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
		int m = Input.nextInt();
		int mnx = +INF, mxx = -INF, mny = +INF, mxy = -INF;
		int tot = 0;
		for (int i = 0; i < n; i++) {
			String s = Input.nextString();
			for (int j = 0; j < m; j++) {
				if (s.charAt(j) == 'X') {
					mnx = Math.min(mnx, i);
					mxx = Math.max(mxx, i);
					mny = Math.min(mny, j);
					mxy = Math.max(mxy, j);
					tot++;
				}
			}
		}
		if (tot == (mxx - mnx + 1) * (mxy - mny + 1)) {
			out.println("YES");
		}
		else {
			out.println("NO");
		}
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