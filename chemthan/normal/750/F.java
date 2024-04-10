import java.io.*;
import java.util.*;

public class Main {
	
	Input in;
	PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = (double) Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	ArrayList<Integer>[] adj;
	boolean[] vis;
	int[] from;
	int mx, ver;
	int left;
	
	int[] ask(int u) {
		vis[u] = true;
		if (left == 0) {
			int[] res = new int[2];
			return res;
		}
		left--;
		out.println("? " + u);
		out.flush();
		int k = in.nextInt();
		int[] res = new int[k];
		for (int i = 0; i < k; i++) {
			res[i] = in.nextInt();
			if (!adj[u].contains(res[i])) {
				adj[u].add(res[i]);
				adj[res[i]].add(u);
			}
		}
		return res;
	}
	
	boolean goleaf(int u, int p) {
		int[] res = ask(u);
		if (res.length == 2) {
			out.println("! " + u);
			out.flush();
			return true;
		}
		for (int e : res) {
			if (e != p) {
				return goleaf(e, u);
			}
		}
		return false;
	}
	
	void dfs(int u, int p, int lev) {
		if (mx < lev) {
			mx = lev;
			ver = u;
		}
		for (int v : adj[u]) {
			if (v != p) {
				from[v] = u;
				dfs(v, u, lev + 1);
			}
		}
	}
	
	int peek(int u) {
		mx = 0;
		ver = u;
		dfs(u, -1, 0);
		u = ver;
		mx = 0;
		dfs(u, -1, 0);
		u = ver;
		for (int i = 0; i < mx / 2; i++) {
			u = from[u];
		}
		return u;
	}
	
	boolean bruteforce(int u, int p, int limit) {
		int[] res = ask(u);
		if (res.length == 2) {
			out.println("! " + u);
			out.flush();
			return true;
		}
		if (limit == 0) return false;
		for (int e : adj[u]) {
			if (e != p && bruteforce(e, u, limit - 1)) {
				return true;
			}
		}
		return false;
	}
	
	void solve() {
		left = 16;
		int h = in.nextInt();
		int n = (1 << h) - 1;
		adj = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			adj[i] = new ArrayList<>();
		}
		vis = new boolean[n + 1];
		from = new int[n + 1];
		int[] res = ask(1);
		if (res.length == 2) {
			out.println("! " + 1);
			out.flush();
			return;
		}
		for (int i = 0; i < Math.min(res.length, 2); i++) {
			if (goleaf(res[i], 1)) {
				return;
			}
		}
		while (true) {
			int p = peek(1);
			int u = -1;
			for (int e : adj[p]) {
				if (!vis[e]) {
					u = e;
				}
			}
			if (mx / 2 + 1 == h - 1) {
				out.println("! " + u);
				out.flush();
				return;
			}
			if (mx / 2 + 1 >= h - 3) {
				bruteforce(u, p, h - mx / 2 - 2);
				return;
			}
			if (goleaf(u, p)) {
				return;
			}
		}
	}
	
	public static void main(String[] args) {
		(new Main()).run();
	}
	
	public void run() {
		in = new Input();
		try {
			out = new PrintWriter(System.out);
			//out = new PrintWriter(new FileWriter("a.out"));
		}
		catch (Exception ex) {
		}
		long stime = System.currentTimeMillis();
		int test = in.nextInt();
		while (test-- > 0) {
			solve();
		}
		if (System.getProperty("ONLINE_JUDGE") == null) {
			out.println("\nTime elapsed: " + (System.currentTimeMillis() - stime) + "ms");
		}
		out.close();
	}
	
	public class Input {
		StringTokenizer token = null;
		BufferedReader in;
		public Input() {
			try {
				if (System.getProperty("ONLINE_JUDGE") == null) {
					in = new BufferedReader(new InputStreamReader(System.in));
					//in = new BufferedReader(new FileReader("in.txt"));
				}
				else {
					in = new BufferedReader(new InputStreamReader(System.in));
				}
			}
			catch (Exception ex) {
			}
		}
		int nextInt() {
			return Integer.parseInt(nextString());
		}
		long nextLong() {
			return Long.parseLong(nextString());
		}
		double nextDouble() {
			return Double.parseDouble(nextString());
		}
		String nextString() {
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