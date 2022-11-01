import java.io.*;
import java.util.*;

public class A implements Runnable {

	private void solve() throws IOException {
		int n = nextInt(), m= nextInt(), k = nextInt();
		int[] min = new int[m];
		Arrays.fill(min, Integer.MAX_VALUE);
		for (int i = 0; i < n; i++) {
			int r = nextInt(), c = nextInt();
			min[r-1] = Math.min(min[r-1], c);
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			ans += min[i];
		}
		ans = Math.min(ans, k);
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