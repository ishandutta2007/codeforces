import java.io.*;
import java.util.*;

public class D {

	static final int MOD = 1000000007;

	static void solve() throws IOException {
		int k = nextInt();
		out.println(get(k));
	}

	private static int get(int k) {
		int answer = 0;

		int maxC = 32;
		int[][] choose = new int[maxC][maxC];
		for (int i = 0; i < maxC; i++) {
			choose[i][0] = choose[i][i] = 1;
			for (int j = 1; j < i; j++) {
				choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
			}
		}

		int bitLength = 32 - Integer.numberOfLeadingZeros(k);
		for (int matchWithK = 0; matchWithK <= bitLength; matchWithK++) {
			int bitsRemaining = bitLength - matchWithK;
			int onesTotal = Integer.bitCount(k >> bitsRemaining);

			if (bitsRemaining > 0 && (k & (1 << bitsRemaining - 1)) == 0) {
				continue;
			}

			for (int sizeFirstHalf = 0; sizeFirstHalf <= onesTotal; sizeFirstHalf++) {
				if ((sizeFirstHalf == 0) ^ (matchWithK == 0)) {
					continue;
				}
				int chooseFirstHalf;
				if (matchWithK > 0) {
					chooseFirstHalf = chooseFirstHalf(k >> bitsRemaining,
							sizeFirstHalf);
				} else {
					chooseFirstHalf = 1;
				}

				if (bitsRemaining == 0) {
					answer = add(answer, chooseFirstHalf);
					continue;
				}

				if (matchWithK > 0) {
					chooseFirstHalf = mul(chooseFirstHalf,
							1 << (sizeFirstHalf - 1));
				}
				int[] chooseSecondHalf = numberOfSetsSimple(bitsRemaining - 1);
				for (int sizeSecondHalf = 0; sizeSecondHalf < chooseSecondHalf.length; sizeSecondHalf++) {
					int ways;
					int chooseSecond = chooseSecondHalf[sizeSecondHalf];
					if (matchWithK == 0) {
						ways = 1;
					} else {
						ways = modPow(2, (bitsRemaining - 1 - sizeSecondHalf)
								* sizeFirstHalf);
					}
					ways = mul(ways, chooseSecond);
					ways = mul(ways, chooseFirstHalf);
					answer = add(answer, ways);
				}
			}
		}
		return answer;
	}

	private static int chooseFirstHalf(int mask, int size) {
		int bits = 32 - Integer.numberOfLeadingZeros(mask);
		int[][] dp = new int[bits + 1][size + 1];

		dp[1][1] = 1;
		for (int bit = 2; bit <= bits; bit++) {
			for (int s = 1; s <= size; s++) {
				int ways1 = mul(1 << (s - 1), dp[bit - 1][s]);
				int ways2;
				if ((mask & (1 << bits - bit)) == 0) {
					ways2 = 0;
				} else {
					ways2 = dp[bit - 1][s - 1];
				}
				dp[bit][s] = add(ways1, ways2);
			}
		}
		return dp[bits][size];
	}

	private static int[] numberOfSetsSimple(int bits) {
		int[][] dp = new int[bits + 1][bits + 1];
		dp[0][0] = 1;
		for (int b = 1; b <= bits; b++) {
			dp[b][0] = 1;
			for (int size = 1; size <= b; size++) {
				dp[b][size] = add(dp[b - 1][size],
						mul(dp[b - 1][size - 1], 1 << b - size));
			}
		}
		return dp[bits];
	}

	static int modPow(int a, long pow) {
		int res = 1 % MOD;
		while (pow > 0) {
			if ((pow & 1) != 0) {
				res = mul(res, a);
			}
			a = mul(a, a);
			pow >>= 1;
		}
		return res;
	}

	static int add(int a, int b) {
		a += b;
		if (a >= MOD || a < 0) {
			a -= MOD;
		}
		return a;
	}

	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

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