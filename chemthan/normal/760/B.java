import java.io.*;
import java.util.*;

public class Main {
	
	Input in;
	PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = (double) Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	long func(int mid, int d) {
		if (mid >= d) {
			return (long) (2 * mid - d + 1) * d / 2;
		}
		return (long) mid * (mid + 1) / 2 + d - mid;
	}
	
	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		int l = 0, r = m;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (func(mid, k) + func(mid, n - k + 1) - mid <= m) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		out.println(l);
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
		//long stime = System.currentTimeMillis();
		//int test = in.nextInt(); while (test-- > 0)
		solve();
		//if (System.getProperty("ONLINE_JUDGE") == null) {
		//	out.println("\nTime elapsed: " + (System.currentTimeMillis() - stime) + "ms");
		//}
		out.close();
	}
	
	public class Input {
		private StringTokenizer token = null;
		private BufferedReader in;
		public Input() {
			try {
				if (System.getProperty("ONLINE_JUDGE") == null) {
					in = new BufferedReader(new InputStreamReader(System.in));
					//in = new BufferedReader(new FileReader("in.txt"));
				}
				else {
					in = new BufferedReader(new InputStreamReader(System.in));
				}
			}
			catch (Exception ex) {
			}
		}
		public int nextInt() {
			return Integer.parseInt(nextString());
		}
		public long nextLong() {
			return Long.parseLong(nextString());
		}
		public double nextDouble() {
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