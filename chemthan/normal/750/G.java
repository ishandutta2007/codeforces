import java.io.*;
import java.util.*;

public class Main {
	
	Input in;
	PrintWriter out;
	
	final static int INF = (int) 1e9;
	final static int MOD = (int) 1e9 + 7;
	final static long LINF = (long) 1e18;
	final static double PI = (double) Math.acos(-1.0);
	final static double EPS = (double) 1e-9;
	
	void solve() {
		long x = in.nextLong();
		long ans = 0;
		for (int k = 0; k <= 50; k++) {
			for (int l = 0; l <= 50; l++) {
				long m = (1L << (k + 1)) + (1L << (l + 1)) - 3;
				long y = x - (1L << l) + 1;
				if (y < m) continue;
				for (int tot = 0; tot <= k + l; tot++) {
					long tmp = (y + tot) % m;
					if (tmp > (1L << k) + (1L << l) - 2) {
						continue;
					}
					int[] digit = new int[50];
					int cnt = 0;
					while (tmp > 0) {
						digit[cnt++] = (int) (tmp % 2);
						tmp >>= 1;
					}
					if (tot > 2 * cnt) continue;
					long[] dp = new long[(cnt + 1) * (2 * cnt + 1) * 2];
					int A = (2 * cnt + 1) * 2;
					int B = 2;
					dp[0 * A + 0 * B + 0] = 1;
					for (int pos = 0; pos < cnt; pos++) {
						int st = Math.max(0, tot - 2 * (cnt - pos));
						for (int sum = st; sum <= tot; sum++) {
							for (int car = 0; car < 2; car++) if (dp[pos * A + sum * B + car] != 0) {
								int lox = 0, hix = 1;
								int loy = 0, hiy = 1;
								if (pos >= k || pos == 0) hix = 0;
								if (pos >= l || pos == 0) hiy = 0;
								for (int i = lox; i <= hix; i++) {
									for (int j = loy; j <= hiy; j++) {
										int u = i + j + car;
										if (u % 2 == digit[pos]) {
											dp[(pos + 1) * A + (sum + i + j) * B + u / 2] += dp[pos * A + sum * B + car];
										}
									}
								}
							}
						}
					}
					ans += dp[cnt * A + tot * B + 0];
				}
			}
		}
		out.println(ans);
	}
	
	public static void main(String[] args) {
		(new Main()).run();
	}
	
	public void run() {
		in = new Input();
		try {
			out = new PrintWriter(System.out);
			//out = new PrintWriter(new FileWriter("a.out"));
		}
		catch (Exception ex) {
		}
		long stime = System.currentTimeMillis();
		solve();
		if (System.getProperty("ONLINE_JUDGE") == null) {
			out.println("\nTime elapsed: " + (System.currentTimeMillis() - stime) + "ms");
		}
		out.close();
	}
	
	public class Input {
		StringTokenizer token = null;
		BufferedReader in;
		public Input() {
			try {
				if (System.getProperty("ONLINE_JUDGE") == null) {
					in = new BufferedReader(new InputStreamReader(System.in));
					//in = new BufferedReader(new FileReader("in.txt"));
				}
				else {
					in = new BufferedReader(new InputStreamReader(System.in));
				}
			}
			catch (Exception ex) {
			}
		}
		int nextInt() {
			return Integer.parseInt(nextString());
		}
		long nextLong() {
			return Long.parseLong(nextString());
		}
		double nextDouble() {
			return Double.parseDouble(nextString());
		}
		String nextString() {
			try {
				while (token == null || !token.hasMoreTokens()) {
					token = new StringTokenizer(in.readLine());
				}
			}
			catch (IOException e) {
			}
			return token.nextToken();
		}
	}
}