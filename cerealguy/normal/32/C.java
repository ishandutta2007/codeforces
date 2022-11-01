import java.io.*;
import java.util.*;

public class C implements Runnable {

	private void solve() throws IOException {
		int n = nextInt(), m = nextInt(), s = nextInt();
		out.println(get(n, s) * get(m, s));
	}
	
	long get(int n, int s) {
		long x = n % s;
		if (x == 0) return n;
		return (n/s + 1) * x;
	}

	public static void main(String[] args) {
		new Thread(new C()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}