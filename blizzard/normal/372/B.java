import java.util.*;
import java.io.*;

public class B {
	BufferedReader br;
	PrintWriter out;
	StringTokenizer stok;

	String nextToken() throws IOException {
		while (stok == null || !stok.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null) {
				return null;
			}
			stok = new StringTokenizer(s);
		}
		return stok.nextToken();
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

	char nextChar() throws IOException {
		return (char) (br.read());
	}

	String nextLine() throws IOException {
		return br.readLine();
	}
	
	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		char[][] c = new char[n][m];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			c[i] = s.toCharArray();
		}
		long[][][][] dp = new long[n][m][n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == '0') dp[i][j][i][j] = 1;
			}
		}
		
		
		for (int len = 1; len < n; len++) {
			for (int i = 0; i  < n - len; i++) {
				for (int j = 0; j < m; j++) {
					int i1 = i + len;
					int j1 = j;
					dp[i][j][i1][j1] = dp[i][j][i1-1][j1];
					for (int q = i1; q >= i && c[q][j] == '0'; q--) {
						dp[i][j][i1][j1]++;
					}
				}
			}
		}
		
		for (int len = 1; len < m; len++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m - len; j++) {
					int i1 = i;
					int j1 = j + len;
					dp[i][j][i1][j1] = dp[i][j][i1][j1-1];
					for (int q = j1; q >= j && c[i][q] == '0'; q--) {
						dp[i][j][i1][j1]++;
					}
				}
			}
		}
		
		int[][] t = new int[n][m];
		for (int i = 0; i < m; i++) {
			if (c[0][i] == '1') {
				t[0][i] = 0;
			} else {
				t[0][i] = -1;
			}
		}
		
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == '1') {
					t[i][j] = i;
				} else {
					t[i][j] = t[i-1][j];
				}
			}
		}
		
		for (int li = 1; li < n; li++) {
			for (int lj = 1; lj < m; lj++) {
				for (int i1 = 0; i1 < n - li; i1++) {
					for (int j1 = 0; j1 < m - lj; j1++) {
						int i2 = i1 + li;
						int j2 = j1 + lj;
						long x = dp[i1][j1][i2-1][j2] + dp[i1][j1][i2][j2-1] - dp[i1][j1][i2-1][j2-1];
					
						int prev = -1;
						if (c[i2][j2] == '0') {
						for (int q = j2; q >= j1 && prev != i2; q--) {
							int qq = t[i2][q];
							prev =  Math.max(Math.max(i1 - 1, qq), prev);
							int p = i2 - prev;
							x += p;
						}
						}
						dp[i1][j1][i2][j2] = x;
					}
				}
			}
		}
		
		for (int q = 0; q < k; q++) {
			int i1 = nextInt() - 1;
			int j1 = nextInt() - 1;
			int i2 = nextInt() - 1;
			int j2 = nextInt() - 1;
			out.println(dp[i1][j1][i2][j2]);
		}
		
		
	}

	void run() throws IOException {
		// br = new BufferedReader(new FileReader("input.txt"));
		// out = new PrintWriter("output.txt");
		 br = new BufferedReader(new InputStreamReader(System.in));
		 out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Locale.setDefault(Locale.US);
		new B().run();
	}
}