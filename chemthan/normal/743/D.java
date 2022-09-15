import java.io.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	static int n;
	static int[] a;
	static ArrayList<Integer>[] adj;
	static long[] f;
	static long ans;
	
	static long dfs(int u, int p) {
		ArrayList<Long> heap = new ArrayList<>();
		long res = a[u];
		for (int v : adj[u]) {
			if (v != p) {
				res += dfs(v, u);
				heap.add(f[v]);
			}
		}
		Collections.sort(heap);
		if (heap.size() >= 2) {
			ans = Math.max(ans, heap.get(heap.size() - 1) + heap.get(heap.size() - 2));
		}
		f[u] = res;
		if (heap.size() >= 1) {
			f[u] = Math.max(f[u], heap.get(heap.size() - 1));
		}
		return res;
	}
	
	static void solve() {
		n = Input.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Input.nextInt();
		}
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int u = Input.nextInt() - 1;
			int v = Input.nextInt() - 1;
			adj[u].add(v);
			adj[v].add(u);
		}
		f = new long[n];
		ans = -LINF;
		dfs(0, -1);
		if (ans > -LINF) {
			out.println(ans);
		}
		else {
			out.println("Impossible");
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