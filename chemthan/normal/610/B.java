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

	static int maxn = 200010;
	static int n;
	static int[] a = new int[maxn << 1];
	
	static void solve() {
		int n = Input.nextInt();
		long dmin = INF;
		for (int i = 0; i < n; i++) {
			a[i] = a[i + n] = Input.nextInt();
			dmin = Math.min(dmin, a[i]);
		}
		long ans = 0, cnt = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (a[i] == dmin) {
				ans = Math.max(ans, cnt);
				cnt = 0;
			}
			else cnt++;
		}
		out.print(dmin * n + ans);
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