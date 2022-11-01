import java.io.*;
import java.util.*;

public class b implements Runnable {

	private void solve() throws IOException {
		int n = nextInt();
		String s = nextToken();
		for (int i = 0; i < s.length() / 2 - 1; i++) {
			out.print(s.substring(2 * i, 2 * i + 2) + "-");
		}
		out.println(s.substring(2 * (s.length() / 2 - 1)));
	}

	public static void main(String[] args) {
		new Thread(new b()).start();
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