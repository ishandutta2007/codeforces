import java.io.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	static void solve() {
		int n = Input.nextInt();
		String s = Input.nextString();
		if (n % 4 != 0) {
			out.println("===");
			return;
		}
		int[] cnt = new int[256];
		for (int i = 0; i < n; i++) {
			char c = s.charAt(i);
			cnt[c]++;
			if (c != '?' && cnt[c] > n / 4) {
				out.println("===");
				return;
			}
		}
		String ans = "";
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == '?') {
				if (cnt['A'] < n / 4) {
					cnt['A']++;
					ans += 'A';
				}
				else if (cnt['C'] < n / 4) {
					cnt['C']++;
					ans += 'C';
				}
				else if (cnt['G'] < n / 4) {
					cnt['G']++;
					ans += 'G';
				}
				else if (cnt['T'] < n / 4) {
					cnt['T']++;
					ans += 'T';
				}
			}
			else {
				ans += s.charAt(i);
			}
		}
		out.println(ans);
	}
	
	public static void main(String[] args) {
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
	
	static class Input {
		static StringTokenizer token = null;
		static BufferedReader in;
		static {
			try {
				if (System.getProperty("ONLINE_JUDGE") == null) {
					in = new BufferedReader(new FileReader("in.txt"));
				}
				else {
					in = new BufferedReader(new InputStreamReader(System.in));
				}
			}
			catch (Exception ex) {
			}
		}
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
			}
			catch (IOException e) {
			}
			return token.nextToken();
		}
	}
}