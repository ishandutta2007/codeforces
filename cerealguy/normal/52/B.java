import java.io.*;
import java.util.*;

public class B implements Runnable {

	private void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		boolean[][] a = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < m; j++) {
				a[i][j] = s.charAt(j) == '*';
			}
		}
		int[] row = new int[n], col = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j]) {
					row[i]++;
					col[j]++;
				}
			}
		}
		long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j]) {
					ans += (row[i] - 1) * (col[j] - 1);
				}
			}
		}
		out.println(ans);
	}

	public static void main(String[] args) {
		new Thread(new B()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

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
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}
}