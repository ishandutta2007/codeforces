import java.io.*;
import java.util.*;

public class A {

	private void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		int l = 1, r = n;
		for (int i = 0; i < m; i++) {
			nextToken();
			nextToken();
			String where = nextToken();
			nextToken();
			int k = nextInt();
			if ("left".equals(where)) {
				r = Math.min(r, k - 1);
			} else {
				l = Math.max(l, k + 1);
			}
		}
		if (l <= r) {
			out.println(r - l + 1);
		} else {
			out.println(-1);
		}
		        
	}

	public static void main(String[] args) {
		new A().run();
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