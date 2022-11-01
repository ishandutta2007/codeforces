import java.io.*;
import java.util.*;

public class B implements Runnable {

	private void solve() throws IOException {
		String s = nextToken();
		int b = 0;
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				b++;
				res++;
			} else {
				if (b != 0) {
					b--;
					res++;
				}
			}
		}
		out.println(res - b);
	}

	public static void main(String[] args) {
		new Thread(new B()).start();
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