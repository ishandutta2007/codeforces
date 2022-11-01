import java.io.*;
import java.util.*;

public class c implements Runnable {

	private void solve() throws IOException {
		int n = nextInt();
		int[][] d = new int[n][n];
		long sum = 0;
		for (int i = 0; i < d.length; i++) {
			for (int j = 0; j < d[0].length; j++) {
				d[i][j] = nextInt();
				sum += d[i][j];
			}
		}
		sum /= 2;
		int k = nextInt();
		for (int it = 0; it < k; it++) {
			int a = nextInt() - 1, b = nextInt() - 1, c = nextInt();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (d[i][j] > d[i][a] + c + d[j][b]) {
						sum -= d[i][j];
						d[j][i] = d[i][j] = d[i][a] + c + d[j][b];
						sum += d[i][j];
					}
					if (d[i][j] > d[i][a] + c + d[j][b]) {
						sum -= d[i][j];
						d[j][i] = d[i][j] = d[i][a] + c + d[j][b];
						sum += d[i][j];
					}
				}
			}
			out.print(sum + " ");
		}

	}

	public static void main(String[] args) {
		new Thread(new c()).start();
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