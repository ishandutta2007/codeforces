import java.io.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = (double) Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	void solve() {
		int[][] f = new int[256][256];
		int[] g = new int[256];
		String s = Input.nextString();
		String t = Input.nextString();
		ArrayList<Integer> ax = new ArrayList<>();
		ArrayList<Integer> ay = new ArrayList<>();
		for (int i = 0; i < s.length(); i++) {
			int u = s.charAt(i);
			int v = t.charAt(i);
			if (g[u] != 0 && g[u] != v) {
				out.println(-1);
				return;
			}
			if (g[v] != 0 && g[v] != u) {
				out.println(-1);
				return;
			}
			g[u] = v;
			g[v] = u;
			if (u != v && f[u][v] == 0) {
				f[u][v] = f[v][u] = 1;
				g[u] = v;
				g[v] = u;
				ax.add(u);
				ay.add(v);
			}
		}
		out.println(ax.size());
		for (int i = 0; i < ax.size(); i++) {
			out.printf("%c %c\n", ax.get(i), ay.get(i));
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
		Main practice = new Main();
		practice.solve();
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
					//in = new BufferedReader(new FileReader("in.txt"));
					in = new BufferedReader(new InputStreamReader(System.in));
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