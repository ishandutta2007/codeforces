import java.io.*;
import java.util.*;

public class D implements Runnable {

	private void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		int k = nextInt();
		boolean[][] b = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < m; j++) {
				b[i][j] = s.charAt(j) == '*';
			}
		}
		for (int x = 1; 2 * x + 1 <= Math.min(n, m); x++) {
			for (int row = x; row < n - x; row++) {
				for (int col = x; col < m - x; col++) {
					if (b[row][col] && b[row][col - x] && b[row - x][col]
							&& b[row][col + x] && b[row + x][col] && --k == 0) {
						row++;
						col++;
						out.println(row+" "+col);
						out.println((row-x)+" "+col);
						out.println((row+x)+" "+col);
						out.println(row+" "+(col-x));
						out.println(row+" "+(col+x));
						return;
					}
				}
			}
		}
		out.println(-1);
	}

	public static void main(String[] args) {
		new Thread(new D()).start();
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