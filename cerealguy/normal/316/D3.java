import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
		int n = nextInt();
		int one = 0, two = 0;
		for (int i = 0; i < n; i++) {
			int ok = nextInt();
			if (ok == 1) {
				++one;
			}
			if (ok > 1) {
				++two;
			}
		}
		int answer = get1(one, two);
		out.println(answer);
	}

	private static int get1(int one, int two) {
		int[] a = new int[Math.max(one + 1, 10)];
		a[0] = 1;
		a[1] = 1;
		for (int i = 2; i < a.length; i++) {
			a[i] = (int) (((long) a[i - 1] + (i - 1L) * a[i - 2]) % MOD);
		}

		long answer = a[one];
		for (int i = one + 1; i <= one + two; i++) {
			answer = answer * i % MOD;
		}
		return (int) answer;
	}

	private static int get(int one, int two) {

		int[][] dp = new int[one + 1][two + 1];
		int[] fact = new int[one + two + 1];
		fact[0] = 1;
		for (int i = 0; i < fact.length - 1; i++) {
			fact[i + 1] = (int) (fact[i] * (i + 1L) % MOD);
		}
		int[][] c = new int[two + 1][two + 1];
		for (int i = 0; i <= two; i++) {
			c[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				c[i][j] = (int) ((long) c[i][j - 1] * (i - j + 1L) % MOD);
			}
		}
		for (int i = 0; i <= one; i++) {
			for (int j = 0; j <= two; j++) {
				if (i == 0) {
					dp[i][j] = fact[j];
					continue;
				}
				long ok = 0;
				for (int ones = 1; ones <= i && ones <= 2; ones++) {
					for (int twos = 0; twos <= j; twos++) {
						long add;
						if (twos == 0) {
							add = dp[i - ones][j];
							if (ones == 2) {
								add *= i - 1;
							}
							// ++ok;
						} else {
							add = (long) c[j][twos] * dp[i - ones][j - twos];
							if (ones == 2) {
								add %= MOD;
								add *= i - 1;
								add *= twos + 1;
							}
						}
						ok += add;
						if (ok < 0) {
							ok -= MODMOD;
						}
					}
				}
				dp[i][j] = (int) (ok % MOD);
			}
		}
		// for (int i = 0; i < one; i++) {
		// System.err.println(dp[i][0] + " " + a[i]);
		// }
		System.err.println(Arrays.toString(dp[5]));
		return dp[one][two];
	}

	static int add(int a, int b) {
		a += b;
		if (a >= MOD) {
			a -= MOD;
		}
		return a;
	}

	static final int MOD = 1000000007;
	static final long MODMOD = Long.MAX_VALUE / MOD * MOD;

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("d.in");
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