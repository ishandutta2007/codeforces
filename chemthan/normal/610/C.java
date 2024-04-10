import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	static PrintWriter out;

	static double EPS = 1e-9;
	static int INF = (int) 1e9;
	static long LINF = (long) 1e18;
	static int MOD = (int) 1e9 + 7;
	static double PI = 2 * Math.acos(0);

	static int maxn = 1010;
	static int[][] a = new int[maxn][maxn];
	
	static void go(int k) {
		if (k == 0) {
			a[0][0] = 1;
			return;
		}
		go(k - 1);
		int m = 1 << (k - 1);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j + m] = a[i][j];
				a[i + m][j] = a[i][j];
				a[i + m][j + m] = 1 - a[i][j];
			}
		}
	}
	
	static void solve() {
		int k = Input.nextInt();
		go(k);
		int m = 1 << k;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) out.print("+");
				else out.print("*");
			}
			out.println();
		}
	}

	public static void main(String[] args) {
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	static class Input {
		static StringTokenizer token = null;
		static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		static BufferedReader in;
//		static {
//			try {
//				in = new BufferedReader(new FileReader("in.txt"));
//			} catch (IOException e) {
//			}
//		}

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
			} catch (IOException e) {
			}
			return token.nextToken();
		}
	}
}