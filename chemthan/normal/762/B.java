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
	
	void solve() {
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int m = in.nextInt();
		ArrayList<Integer> t1 = new ArrayList<>();
		ArrayList<Integer> t2 = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			int x = in.nextInt();
			String s = in.nextString();
			if (s.compareTo("USB") == 0) {
				t1.add(x);
			}
			else {
				t2.add(x);
			}
		}
		Collections.sort(t1);
		Collections.sort(t2);
		ArrayList<Integer> t3 = new ArrayList<>();
		long ans = 0, mn = 0;
		for (int i = 0; i < t1.size(); i++) {
			if (i < a) {
				ans++;
				mn += t1.get(i);
			}
			else {
				t3.add(t1.get(i));
			}
		}
		for (int i = 0; i < t2.size(); i++) {
			if (i < b) {
				ans++;
				mn += t2.get(i);
			}
			else {
				t3.add(t2.get(i));
			}
		}
		Collections.sort(t3);
		for (int i = 0; i < c && i < t3.size(); i++) {
			ans++;
			mn += t3.get(i);
		}
		out.println(ans + " " + mn);
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
		//long stime = System.currentTimeMillis();
		//int test = in.nextInt(); while (test-- > 0)
		solve();
		//if (System.getProperty("ONLINE_JUDGE") == null) {
		//	out.println("\nTime elapsed: " + (System.currentTimeMillis() - stime) + "ms");
		//}
		out.close();
	}
	
	public class Input {
		private StringTokenizer token = null;
		private BufferedReader in;
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
		public int nextInt() {
			return Integer.parseInt(nextString());
		}
		public long nextLong() {
			return Long.parseLong(nextString());
		}
		public double nextDouble() {
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
		public String nextLine() {
			try {
				return in.readLine();
			}
			catch (IOException e) {
				return "";
			}
		}
	}
}