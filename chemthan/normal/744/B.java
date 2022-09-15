import java.io.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	final static int INF = (int) 1e9 + 5;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18 + 5;
	final static double PI = Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	static void solve() {
		int n = Input.nextInt();
		int[][] quest = new int[20][1 << 10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < (1 << 10); j++) {
				if (j % (1 << (i + 1)) < (1 << i)) {
					quest[i << 1][j] = 1;
				}
				else {
					quest[i << 1 | 1][j] = 1;
				}
			}
		}
		int[] ans = new int[n];
		Arrays.fill(ans, INF);
		for (int e[] : quest) {
			int sz = 0;
			for (int i = 0; i < n; i++) {
				if (e[i] == 1) {
					sz++;
				}
			}
			if (sz > 0) {
				out.println(sz);
				int cnt = 0;
				for (int i = 0; i < n; i++) {
					if (e[i] == 1) {
						out.print((i + 1));
						if (cnt++ < sz - 1) out.print(" ");
						else out.println();
					}
				}
				out.flush();
				for (int i = 0; i < n; i++) {
					int k = Input.nextInt();
					if (e[i] == 0) {
						ans[i] = Math.min(ans[i], k);
					}
				}
			}
		}
		out.println("-1");
		for (int i = 0; i < n; i++) {
			out.print(ans[i]);
			if (i < n - 1) out.print(" ");
			else out.println();
		}
		out.flush();
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