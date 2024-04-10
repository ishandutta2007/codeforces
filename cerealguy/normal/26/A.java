import java.io.*;
import java.util.*;

public class A implements Runnable {

	boolean check(int n) {
		int cnt = 0;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				cnt++;
				while (n % i == 0)
					n /= i;
			}
		}
		if (n > 1) cnt++;
		return cnt == 2;
	}

	private void solve() throws IOException {
		int ans = 0;
		int n = nextInt();
		for (int i = 1; i <= n;i ++) {
			if (check(i)) ans++;
		}
		out.println(ans);
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