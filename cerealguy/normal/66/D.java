import java.io.*;
import java.util.*;

public class D {

	private void solve() throws IOException {
		int n = nextInt();
		if (n == 2) {
			out.println(-1);
			return;
		}
		long[] res = new long[n];
		res[0] = 6;
		res[1] = 10;
		res[2] = 15;
		for (int i = 3; i < n; i++) {
			res[i] = 30 * i;
		}
		for (int i = 0; i < res.length; i++) {
			out.println(res[i]);
		}
	}

	public static void main(String[] args) {
		new D().run();
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
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}