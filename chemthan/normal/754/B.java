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
		int[][] a = new int[4][4];
		for (int i = 0; i < 4; i++) {
			String s = in.nextString();
			for (int j = 0; j < 4; j++) {
				a[i][j] = s.charAt(j);
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) if (a[i][j] == '.') {
				a[i][j] = 'x';
				for (int ii = 0; ii < 4; ii++) {
					for (int jj = 0; jj < 2; jj++) {
						if (a[ii][jj] == 'x' && a[ii][jj + 1] == 'x' && a[ii][jj + 2] == 'x') {
							out.println("YES");
							return;
						}
						if (a[jj][ii] == 'x' && a[jj + 1][ii] == 'x' && a[jj + 2][ii] == 'x') {
							out.println("YES");
							return;
						}
					}
				}
				for (int ii = 0; ii < 2; ii++) {
					for (int jj = 0; jj < 2; jj++) {
						if (a[ii][jj] == 'x' && a[ii + 1][jj + 1] == 'x' && a[ii + 2][jj + 2] == 'x') {
							out.println("YES");
							return;
						}
					}
					for (int jj = 3; jj > 1; jj--) {
						if (a[ii][jj] == 'x' && a[ii + 1][jj - 1] == 'x' && a[ii + 2][jj - 2] == 'x') {
							out.println("YES");
							return;
						}
					}
				}
				a[i][j] = '.';
			}
		}
		out.println("NO");
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