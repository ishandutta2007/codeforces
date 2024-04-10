import java.io.*;
import java.util.*;

public class E {

	static void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int sereja = nextInt();
		int answer = sereja(n, m, sereja);
		
		for (int i = 1; i <= n; i++) {
			answer = (int)((long)answer * i % MOD);
		}

		out.println(answer);
	}

	private static int sereja(int n, int m, int sereja) {
		if (n > m) {
			return 0;
		}
		int[][] dp = new int[n + 1][n + 1];
		dp[0][0] = 1;
		for (int value = 1; value <= m; value++) {
			for (int i = n; i >= 0; --i) {
				int[] dpi = dp[i];
				int[] dpi1 = i < n ? dp[i + 1] : null;
				for (int j = i; j >= 0; --j) {
					if (dpi[j] == 0) {
						continue;
					}
					if (i < n) {
						dpi1[j] = add(dpi1[j], dpi[j]);
						dpi1[j + 1] = add(dpi1[j + 1], dpi[j]);
					}
					if (i > j && value != sereja) {
						dpi[j + 1] = add(dpi[j + 1], dpi[j]);
					}
					if (value == sereja) {
						dpi[j] = 0;
					}
				}
			}
		}

		return dp[n][n];
	}

	static int add(int a, int b) {
		a += b;
		if (a >= MOD) {
			a -= MOD;
		}
		return a;
	}

	static final int MOD = 1000000007;

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("e.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}