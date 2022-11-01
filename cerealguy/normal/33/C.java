import java.io.*;
import java.util.*;

public class C implements Runnable {

	private void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		long sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			sum += a[i];
		}

		long[] p = new long[n + 1], s = new long[n + 1];
		p[0] = 0;
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] - 2 * a[i];
		}
		s[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			s[i] = s[i + 1] - 2 * a[i];
		}

		for (int i = 1; i <= n; i++) {
			p[i] = Math.max(p[i], p[i - 1]);
		}

		for (int i = n - 1; i >= 0; i--) {
			s[i] = Math.max(s[i], s[i + 1]);
		}

		long ans = 0;
		for (int i = 0; i <= n; i++) {
			ans = Math.max(s[i] + p[i], ans);
		}
		out.println(ans + sum);
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