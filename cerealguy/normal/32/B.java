import java.io.*;
import java.util.*;

public class B implements Runnable {

	private void solve() throws IOException {
		String s = nextToken();
		int pos = 0;
		while (pos < s.length()) {
			if (s.charAt(pos++) == '.') {
				out.print('0');
				continue;
			} else {
				if (s.charAt(pos++) == '.') {
					out.print('1');
				} else {
					out.print('2');
				}
			}
		}
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