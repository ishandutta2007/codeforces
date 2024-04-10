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
		int[][] a = new int[n][n];
		int[] r = new int[n];
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			String s = in.nextString();
			for (int j = 0; j < n; j++) {
				a[i][j] = s.charAt(j);
				r[i] += a[i][j] == '.' ? 1 : 0;
				c[j] += a[i][j] == '.' ? 1 : 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (r[i] + c[j] == 0) {
					out.println(-1);
					return;
				}
			}
		}
		boolean fr = true;
		for (int i = 0; i < n; i++) {
			if (r[i] == 0) fr = false;
		}
		if (fr) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (a[i][j] == '.') {
						out.println((i + 1) + " " + (j + 1));
						break;
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (a[j][i] == '.') {
						out.println((j + 1) + " " + (i + 1));
						break;
					}
				}
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
					//in = new BufferedReader(new FileReader("in.txt"));
					in = new BufferedReader(new InputStreamReader(System.in));
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