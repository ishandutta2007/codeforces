import java.io.*;
import java.util.*;

public class E implements Runnable {

	private void solve() throws IOException {
		int n = nextInt();
		int[][] m = new int[n][n];
		int edges = nextInt();
		int k = nextInt();
		for (int i = 0; i < edges; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			m[u][v]++;
			m[v][u]++;
		}
		int[][] d = new int[1 << n][1 << n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int mask = (1 << i) | (1 << j);
				d[mask][mask] = m[i][j];
			}
		}
		for (int mask = 1; mask < 1 << n; mask++) {
			if (Integer.bitCount(mask) <= 2)
				continue;
			for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
				int bit = Integer.numberOfTrailingZeros(sub);
				int mask1 = mask ^ (1 << bit);
				int sub1 = sub ^ (1 << bit);
				for (int i = 0; i < n; i++) {
					if ((mask1 & (1 << i)) != 0 && (sub1 & (1 << i)) == 0) {
						d[mask][sub] += m[bit][i] * d[mask1][sub1 | (1 << i)];
						d[mask][sub] += m[bit][i] * d[mask1][sub1];
					}
				}
			}
		}

		int ans = 0;
		for (int mask = 0; mask < 1 << n; mask++) {
			if (Integer.bitCount(mask) == k) {
				ans += d[(1 << n) - 1][mask];
			}
		}
		out.println(ans);
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
}