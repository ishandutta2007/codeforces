import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class A {

	static final long MOD = 1000_000_007;

	static long choose(long n, long k) {
		if (k == 0)
			return 1;
		if (k > n / 2)
			return choose(n, n - k);
		long ans = 1;
		BigInteger mod = new BigInteger("1000000007");
		for (long i = 0; i < k; ++i) {
			ans = (ans * (n - i)) % MOD;
			ans = ans
					* Long.parseLong(new BigInteger(Long.toString(i + 1))
							.modInverse(mod).toString()) % MOD;
			// System.out.println("mod inv is "
			// + Long.parseLong(new BigInteger(Long.toString(i + 1))
			// .modInverse(mod).toString()));
			// System.out.println(ans);
			ans %= MOD;
		}
		return ans;
	}

	static long[][] ans = new long[1005][1005];
	static int[] c;

	static long get_ans(int k, int n) {
		if (k == -1) {
			return 1;
		}
		if (ans[k][n] == -1)
			ans[k][n] = (choose(n - 1, c[k] - 1) * get_ans(k - 1, n - c[k]))
					% MOD;
		return ans[k][n];
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(br.readLine());
		c = new int[k];
		int n = 0;
		for (int i = 0; i < k; ++i) {
			c[i] = Integer.parseInt(br.readLine());
			n += c[i];
		}

		for (int i = 0; i < 1005; ++i)
			for (int j = 0; j < 1005; ++j)
				ans[i][j] = -1;

		System.out.println(get_ans(k - 1, n));
	}
}