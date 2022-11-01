import static java.math.BigInteger.valueOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	private static void solve() throws IOException {
		int m = nextInt();
		String m1 = Integer.toString(m + 1);
		int[] count = new int[100];
		for (int match = 0; match < m1.length(); match++) {
			int curDigit = m1.charAt(match) - '0';
			for (int digit = 0; digit < curDigit; digit++) {
				String t = m1.substring(0, match) + digit;
				int have = lucky(t);
				int digitsLeft = m1.length() - match - 1;
				for (int luckyCount = 0; luckyCount <= digitsLeft; luckyCount++) {
					int ways = c(digitsLeft, luckyCount) << luckyCount;
					for (int i = 0; i < digitsLeft - luckyCount; i++) {
						ways *= 8;
					}
					count[have + luckyCount] += ways;
				}
			}
		}
		--count[0];

		int[][] dp = new int[7][count.length];
		dp[0][0] = 1;
		for (int c = 0; c < count.length; c++) {
			if (count[c] == 0) {
				continue;
			}
			for (int takeOther = 6; takeOther >= 0; --takeOther) {
				for (int takeThis = 1; takeThis <= 6; takeThis++) {
					if (takeThis + takeOther > 6) {
						continue;
					}
					if (takeThis > count[c]) {
						continue;
					}
					for (int sumWas = 0; sumWas < count.length; sumWas++) {
						int sumTo = sumWas + c * takeThis;
						if (sumTo >= count.length) {
							continue;
						}
						if (dp[takeOther][sumWas] == 0) {
							continue;
						}
						int takeTo = takeThis + takeOther;
						long ways = dp[takeOther][sumWas];
						ways = ways * cMod(count[c], takeThis) % MOD;
						dp[takeTo][sumTo] = (int) ((dp[takeTo][sumTo] + ways) % MOD);
					}
				}
			}
		}

		long ans = 0;
		long dpSum = 0;

		for (int ourCount = 1; ourCount < count.length; ourCount++) {
			dpSum += dp[6][ourCount - 1];
			dpSum %= MOD;
			ans += dpSum * count[ourCount] % MOD;
		}
		ans %= MOD;
		ans = ans * 720L % MOD;
		out.println(ans);
	}

	static int cMod(int n, int k) {
		long a = 1;
		for (int i = 0; i < k; i++) {
			a = (a * (n - i)) % MOD;
			a = a * inv(i + 1) % MOD;
		}
		return (int) a;
	}

	private static long inv(int i) {
		return valueOf(i).modInverse(valueOf(MOD)).intValue();
	}

	static final int MOD = 1000000007;

	static int c(int n, int k) {
		int ret = 1;
		for (int i = 0; i < k; i++) {
			ret *= n - i;
			ret /= i + 1;
		}
		return ret;
	}

	private static int lucky(String t) {
		int cnt = 0;
		for (int i = 0; i < t.length(); i++) {
			if (t.charAt(i) == '4' || t.charAt(i) == '7') {
				++cnt;
			}
		}
		return cnt;
	}

	public static void main(String[] args) {
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

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

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

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}