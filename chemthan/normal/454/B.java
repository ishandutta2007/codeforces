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
	
	static int maxn = 100010;
	static int n;
	static int a[] = new int[maxn];

	static void solve() {
		n = Input.nextInt();
		int cur = INF, cnt = 0, last = 0;
		int dmin = INF, dmax = -INF;
		for (int i = 0; i < n; i++) {
			a[i] = Input.nextInt();
			if (a[i] < cur) {
				cur = a[i];
				cnt++;
				last = 1;
			}
			else {
				cur = a[i];
				last++;
			}
			if (cnt == 1) {
				dmin = Math.min(dmin, a[i]);
			}
			if (cnt == 2) {
				dmax = Math.max(dmax, a[i]);
			}
		}
		if (cnt > 2) {
			out.print(-1);
		}
		else if (cnt == 2) {
			if (dmin < dmax) out.print(-1);
			else out.print(last);
		}
		else out.print(0);
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