import java.io.*;
import java.util.*;

public class a implements Runnable {

	private void solve() throws IOException {
		int n = nextInt();
		int[] x = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			x[i] = nextInt();
		}
		int a = nextInt() - 1, b = nextInt() - 1;
		long ans = 0;
		for (int i = a; i < b; i++) {
			ans += x[i];
		}
		out.println(ans);
	}

	public static void main(String[] args) {
		new Thread(new a()).start();
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