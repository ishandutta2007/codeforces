import java.io.*;
import java.util.*;

public class B implements Runnable {
	boolean[][] a;
	int n;

	private void solve() throws IOException {
		n = nextInt();
		int k = nextInt();
		a = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < n; j++) {
				a[i][j] = s.charAt(j) == '*';
			}
		}
		boolean[][] res = a;
		for (int i = 0; i < k - 1; i++) {
			res = apply(res);
		}
		for (int i = 0; i < res.length; i++) {
			for (int j = 0; j < res[0].length; j++) {
				out.print(res[i][j] ? '*' : ".");
			}
			out.println();
		}
	}

	boolean[][] apply(boolean[][] x) {
		int n1 = x[0].length;
		boolean[][] res = new boolean[n1 * n][n1 * n];
		for (int i = 0; i < n1 * n; i++) {
			for (int j = 0; j < n1 * n; j++) {
				int i1 = i / n, j1 = j / n;
				int i2 = i % n, j2 = j % n;
				res[i][j] = x[i1][j1] || a[i2][j2];
			}
		}
		return res;
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
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
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