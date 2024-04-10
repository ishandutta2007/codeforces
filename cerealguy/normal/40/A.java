import java.io.*;
import java.util.*;

public class A implements Runnable {

	private void solve() throws IOException {
		int x = nextInt(), y = nextInt();
		int t = x * x + y * y;
		int s = (int) Math.sqrt(t);
		while ((s + 1) * (s + 1) <= t)
			s++;
		while (s * s > t)
			s--;
		if (s * s == t || x == 0 || y == 0) {
			out.println("black");
			return;
		}
		boolean ok = Integer.signum(x) == Integer.signum(y);
		if ((s % 2 == 1) ^ ok) {
			out.println("black");
		} else {
			out.println("white");
		}
	}

	public static void main(String[] args) {
		new Thread(new A()).start();
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