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

	static int maxn = 1000010;
	static int n;
	static String s, t;
	
	static char reverse(char c) {
		if (c == 'W') return 'E';
		if (c == 'E') return 'W';
		if (c == 'N') return 'S';
		return 'N';
	}
	
	static void solve() {
		n = Input.nextInt() - 1;
		s = Input.nextString();
		t = Input.nextString();
		long hashs = 0, hasht = 0, p = 2311, pw = 1;
		for (int i = n - 1; i >= 0; i--) {
			hashs = (hashs * p + s.charAt(i)) % MOD;
			hasht = (hasht + reverse(t.charAt(i)) * pw) % MOD;
			pw = pw * p % MOD;
			if (hashs == hasht) {
				out.print("NO");
				return;
			}
		}
		out.print("YES");
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