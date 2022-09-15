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
		long n = in.nextLong();
		int k = in.nextInt();
		ArrayList<Long> dvs= new ArrayList<>();
		for (long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				dvs.add(i);
				if (i * i < n) {
					dvs.add(n / i);
				}
			}
		}
		Collections.sort(dvs);
		if (dvs.size() < k) {
			out.println("-1");
		}
		else {
			out.println(dvs.get(k - 1));
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