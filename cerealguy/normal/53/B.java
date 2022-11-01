import java.io.*;
import java.util.*;

public class B implements Runnable {

	private void solve() throws IOException {
		long h = nextLong(), w = nextLong();
		long ansH = 1, ansW = 1, ansSize = 1;
		for (int i = 0; i < 50; i++) {
			{
				long h1 = 1L << i;
				if (h1 > h)
					continue;
				long w1 = Math.min(w, h1 * 5 / 4);
				w1 = Math.max(w1, (h1 * 4 + 4) / 5);
				if (w1 > w)
					continue;
				long size = h1 * w1;
				if (size > ansSize || size == ansSize && h1 > ansH) {
					ansH = h1;
					ansW = w1;
					ansSize = size;
				}
			}
			{
				long w1 = 1L << i;
				if (w1 > w)
					continue;
				long h1 = Math.min(h, w1 * 5 / 4);
				h1 = Math.max(h1, (w1 * 4 + 4) / 5);
				if (h1 > h)
					continue;
				long size = h1 * w1;
				if (size > ansSize || size == ansSize && h1 > ansH) {
					ansH = h1;
					ansW = w1;
					ansSize = size;
				}
			}
		}
		out.println(ansH+" "+ansW);
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