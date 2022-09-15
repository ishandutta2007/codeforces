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
	
	static void solve() {
		String s = Input.nextString();
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (i > 0 && s.charAt(i) != s.charAt(i - 1)) {
				cnt = 0;
			}
			if (++ cnt >= 7) {
				out.print("YES");
				return;
			}
		}
		out.print("NO");
	}

	static class Pair implements Comparable<Pair> {
		int fi, se;
		public Pair(int fi, int se) {
			this.fi = fi;
			this.se = se;
		}
		public int compareTo(Pair oth) {
			if (fi > oth.fi) return +1;
			if (fi < oth.fi) return -1;
			if (se > oth.se) return +1;
			if (se < oth.se) return -1;
			return 0;
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