import java.io.*;
import java.util.*;

public class Main {
	
	static PrintWriter out;
	
	static void solve() {
		int n = Input.nextInt();
		String s = Input.nextString();
		out.println(s.replaceAll("o(go)+", "***"));
	}
	
	public static void main(String[] args) {
		try {
			out = new PrintWriter(System.out);
			//out = new PrintWriter(new FileWriter("a.out"));
		}
		catch (Exception ex) {
		}
		//long stime = System.currentTimeMillis();
		solve();
		//out.println("\nTime elapsed: " + (System.currentTimeMillis() - stime) + "ms");
		out.close();
	}
	
	static class Pair implements Comparable<Pair> {
		int fi, se;
		Pair(int fi, int se) {
			this.fi = fi;
			this.se = se;
		}
		public int compareTo(Pair rhs) {
			if (fi > rhs.fi) return +1;
			if (fi < rhs.fi) return -1;
			if (se > rhs.se) return +1;
			if (se < rhs.se) return -1;
			return 0;
		}
	}
	
	static class Input {
		static StringTokenizer token = null;
		static BufferedReader in;
		static {
			try {
				in = new BufferedReader(new InputStreamReader(System.in));
				//in = new BufferedReader(new FileReader("a.in"));
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