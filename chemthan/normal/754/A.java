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
	
	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		long sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			sum += a[i];
		}
		if (sum != 0) {
			out.println("YES");
			out.println(1);
			out.println(1 + " " + n);
		}
		else {
			int ix = -1;
			for (int i = 0; i < n; i++) {
				if (a[i] != 0) {
					ix = i + 1;
					break;
				}
			}
			if (ix != -1) {
				out.println("YES");
				out.println(2);
				out.println(1 + " " + ix);
				out.println((ix + 1) + " " + n);
			}
			else {
				out.println("NO");
			}
		}
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
					//in = new BufferedReader(new FileReader("in.txt"));
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