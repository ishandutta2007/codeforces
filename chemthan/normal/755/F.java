import java.io.*;
import java.util.*;
import java.util.Map.*;

public class Main {
	
	Input in;
	PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = (double) Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	BitSet shiftLeft(BitSet a, int k) {
		long[] ar = a.toLongArray();
		int d = k >> 6;
		int r = k & 63;
		long[] rs = new long[Math.min(20000, ar.length + d + 1)];
		for (int i = d; i < rs.length; i++) {
			if (i - d < ar.length) {
				rs[i] = ar[i - d] << r;
			}
			if (i - d - 1 >= 0 && r > 0) {
				rs[i] |= ar[i - d - 1] >>> 64 - r;
			}
		}
		return BitSet.valueOf(rs);
	}
	
	void solvemin(TreeMap<Integer, Integer> hs, int n, int k) {
		BitSet can = new BitSet(1);
		can.set(0);
		for (Entry<Integer, Integer> e : hs.entrySet()) {
			int x = e.getKey();
			int y = e.getValue();
			can.or(shiftLeft(can, x));
			int dt = 1;
			for (int i = 31 - Integer.numberOfLeadingZeros(y) - 1; i >= 0; i--) {
				can.or(shiftLeft(can, dt * x));
				dt <<= 1;
				if (((y >> i) & 1) == 1) {
					can.or(shiftLeft(can, x));
					dt |= 1;
				}
			}
		}
		if (k < can.length() && can.get(k)) out.print(k + " ");
		else out.print((k + 1) + " ");
	}
	
	void solvemax(TreeMap<Integer, Integer> hs, int n, int k) {
		int res = 0, d = k;
		for (Entry<Integer, Integer> e : hs.entrySet()) {
			int x = e.getKey();
			int y = e.getValue();
			int z = Math.min(d, x / 2 * y);
			res += z << 1;
			d -= z;
		}
		res = Math.min(n, res + d);
		out.println(res);
	}
	
	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = in.nextInt() - 1;
		}
		boolean[] vis = new boolean[n];
		TreeMap<Integer, Integer> hs = new TreeMap<>();
		for (int i = 0; i < n; i++) if (!vis[i]) {
			int ptr = p[i], cnt = 1;
			vis[i] = true;
			while (ptr != i) {
				vis[ptr] = true;
				cnt++;
				ptr = p[ptr];
			}
			if (!hs.containsKey(cnt)) {
				hs.put(cnt, 1);
			}
			else {
				hs.put(cnt, hs.get(cnt) + 1);
			}
		}
		solvemin(hs, n, k);
		solvemax(hs, n, k);
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
		//int test = in.nextInt(); while (test-- > 0)
		solve();
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