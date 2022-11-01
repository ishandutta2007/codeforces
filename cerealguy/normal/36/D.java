import java.io.*;
import java.util.*;

public class D implements Runnable {

	private void solve() throws IOException {
		int t = nextInt(), k = nextInt();
		for (int i = 0; i < t; i++) {
			out.println(lose(nextInt() - 1, nextInt() - 1, k) ? "-" : "+");
		}
	}

	boolean lose(int n, int m, int k) {
		if (k == 1) {
			return (m % 2 == 0) && (n % 2 == 0);
		}
		if (m > n) {
			int tmp = m;
			m = n;
			n = tmp;
		}
		int m1 = m % (2 * k + 2);
		if (m1 == k || m1 == 2 * k + 1) {
			return false;
		}
		if (m1 < k) {
			return (m + n) % 2 == 0;
		} else {
			return (m + n) % 2 == 1;
		}
	}

	public static void main(String[] args) {
		new Thread(new D()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
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