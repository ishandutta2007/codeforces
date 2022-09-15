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
		int k = Input.nextInt();
		int[] a = new int[n];
		int tot = 0;
		for (int i = 0; i < n; i++) {
			a[i] = Input.nextInt() >= 0 ? 1 : 0;
			tot += a[i] == 0 ? 1 : 0;
		}
		if (tot > k) {
			out.println(-1);
			return;
		}
		k -= tot;
		int st = -1, cnt = 0;
		ArrayList<Integer> ar = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (a[i] != st) {
				if (st != -1) {
					if (st == 1) {
						ar.add(cnt);
					}
					else {
						ar.add(-1);
					}
				}
				st = a[i];
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		if (st == 1) {
			ar.add(cnt);
		}
		else {
			ar.add(-1);
		}
		int ans = ar.size() + (a[0] == 1 ? 0 : 1) - 1;
		int mx = 0;
		for (int it = 0; it < 2; it++) {
			ArrayList<Integer> heap = new ArrayList<>();
			for (int i = 1; i < ar.size() - 1; i++) {
				if (ar.get(i) > 0) {
					heap.add(ar.get(i));
				}
			}
			int kk = k, tmp = 0;
			if (it == 1 && ar.size() > 1 && ar.get(ar.size() - 1) > 0) {
				if (kk >= ar.get(ar.size() - 1)) {
					kk -= ar.get(ar.size() - 1);
					tmp++;
				}
			}
			Collections.sort(heap);
			for (int e : heap) {
				if (kk >= e) {
					kk -= e;
					tmp += 2;
				}
			}
			mx = Math.max(mx, tmp);
		}
		out.println(ans - mx);
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