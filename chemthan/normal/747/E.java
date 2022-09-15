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
		String s = Input.nextString();
		String[] ss = s.split(",");
		ArrayList<String>[] ans = new ArrayList[1000010];
		for (int i = 0; i < 1000010; i++) {
			ans[i] = new ArrayList<>();
		}
		Stack<Integer> st = new Stack<>();
		int cur = 0, mx = 0;
		while (cur < ss.length) {
			if (st.isEmpty()) {
				String word = ss[cur++];
				int k = Integer.parseInt(ss[cur++]);
				ans[0].add(word);
				if (k > 0) {
					st.add(0);
					st.add(k);
				}
			}
			else {
				int k = st.lastElement();
				st.pop();
				int lev = st.lastElement();
				st.pop();
				if (k > 1) {
					st.add(lev);
					st.add(k - 1);
				}
				String word = ss[cur++];
				int kk = Integer.parseInt(ss[cur++]);
				ans[lev + 1].add(word);
				if (kk > 0) {
					st.add(lev + 1);
					st.add(kk);
				}
				mx = Math.max(mx, lev + 1);
			}
		}
		out.println(mx + 1);
		for (int i = 0; i <= mx; i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				out.print(ans[i].get(j));
				if (j < ans[i].size() - 1) out.print(" ");
				else out.println();
			}
		}
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