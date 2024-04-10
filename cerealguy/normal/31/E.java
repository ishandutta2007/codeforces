import java.io.*;
import java.util.*;

public class E implements Runnable {

	private void solve() throws IOException {
		int n = nextInt();
		String s = nextToken();
		int[] digits = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			digits[i] = s.charAt(2 * n - 1 - i) - '0';
		}
		long[] pows = new long[n];
		pows[0] = 1;
		for (int i = 1; i < n; i++) {
			pows[i] = pows[i - 1] * 10;
		}
		long[][] d = new long[n + 1][n + 1];
		d[0][0] = 0;
		for (int sum = 1; sum <= 2 * n; sum++) {
			for (int i = Math.max(sum - n, 0); i <= Math.min(sum, n); i++) {
				int j = sum - i;
				if (i > 0)
					d[i][j] = Math.max(d[i][j], d[i - 1][j] + digits[sum - 1]
							* pows[i - 1]);
				if (j > 0)
					d[i][j] = Math.max(d[i][j], d[i][j - 1] + digits[sum - 1]
							* pows[j - 1]);
			}
		}

		boolean[] res = new boolean[2 * n];
		int c1 = n, c2 = n;
		while (c1 + c2 > 0) {
			int sum = c1 + c2;
			if (c1 > 0
					&& d[c1][c2] == d[c1 - 1][c2] + digits[sum - 1]
							* pows[c1 - 1]) {
				res[sum - 1] = true;
				c1--;
				continue;
			}
			if (c2 > 0
					&& d[c1][c2] == d[c1][c2 - 1] + digits[sum - 1]
							* pows[c2 - 1]) {
				res[sum - 1] = false;
				c2--;
				continue;
			}
		}

		for (int i = 0; i < n; i++) {
			boolean t = res[i];
			res[i] = res[2 * n - 1 - i];
			res[2 * n - 1 - i] = t;
		}

		for (int i = 0; i < 2 * n; i++) {
			out.print(res[i] ? 'H' : 'M');
		}
	}

	public static void main(String[] args) {
		new Thread(new E()).start();
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