import java.io.*;
import java.util.*;

public class A implements Runnable {

	private void solve() throws IOException {
		String s = nextToken();
		String ans = null;
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			String cur = nextToken();
			if (cur.startsWith(s) && (ans == null || ans.compareTo(cur) > 0))
				ans = cur;
		}
		out.println(ans == null? s: ans);
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