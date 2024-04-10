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
	
	boolean next_permutation(int[] p) {
		for (int i = p.length - 2; i >= 0; i--) {
			if (p[i] < p[i + 1]) {
				for (int j = p.length - 1; j > i; j--) {
					if (p[i] < p[j]) {
						int t = p[i];
						p[i] = p[j];
						p[j] = t;
						for (i++, j = p.length - 1; i < j; i++, j--) {
							t = p[i];
							p[i] = p[j];
							p[j] = t;
						}
						return true;
					}
				}
			}
		}
		for (int i = 0, j = p.length - 1; i < j; i++, j--) {
			int t = p[i];
			p[i] = p[j];
			p[j] = t;
		}
		return false;
	}
	
	void solve() {
		int[] ar = new int[4];
		int cnt = 0;
		for (int i = 0; i <= 9; i++) {
			String qr = "";
			for (int j = 0; j < 4; j++) {
				qr += (char) ('0' + i);
			}
			out.println(qr);
			out.flush();
			int u = in.nextInt();
			int v = in.nextInt();
			if (u + v > 0) ar[cnt++] = i;
		}
		do {
			String qr = "";
			for (int i = 0; i < 4; i++) {
				qr += (char) ('0' + ar[i]);
			}
			out.println(qr);
			out.flush();
			int u = in.nextInt();
			int v = in.nextInt();
			if (u == 4) {
				return;
			}
		}
		while (next_permutation(ar));
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