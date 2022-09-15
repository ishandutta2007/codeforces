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
	static String a, b;
	static int[] cnt = new int[maxn];
	
	static void solve() {
		a = Input.nextString();
		b = Input.nextString();
		for (int i = 0; i < b.length(); i++) {
			if (i > 0) cnt[i] = cnt[i - 1];
			if (b.charAt(i) == '1') cnt[i]++;
		}
		long ans = 0;
		for (int i = 0; i < a.length(); i++) {
			int t = cnt[b.length() - a.length() + i];
			if (i > 0) t -= cnt[i - 1];
			if (a.charAt(i) == '0') {
				ans += t;
			}
			else {
				ans += b.length() - a.length() - t + 1;
			}
		}
		out.print(ans);
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