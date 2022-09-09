import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.pow;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static long p4(long v) {
		v *= v;
		return v * v;
	}

	static long p3(long v) {
		return v * v * v;
	}

	static long p2(long v) {
		return v * v;
	}

	static int p2(int v) {
		return v * v;
	}

	static long nums[];
	static int counts[];
	static boolean isPrimes[];
	static int cnt;

	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static void remove(int i) {
		--cnt;
		arraycopy(nums, i + 1, nums, i, cnt - i);
		arraycopy(counts, i + 1, counts, i, cnt - i);
		arraycopy(isPrimes, i + 1, isPrimes, i, cnt - i);
	}

	static void add(long num, int count, boolean isPrime) {
		int i = binarySearch(nums, 0, cnt, num);
		if (i >= 0) {
			counts[i] += count;
			return;
		}
		i = ~i;
		if (isPrime) {
			for (int j = 0; j < cnt; j++) {
				if (!isPrimes[j] && nums[j] % num == 0) {
					long num2 = nums[j];
					int count2 = counts[j];
					remove(j);
					add(num2 / num, count2, true);
					add(num, count + count2, true);
					return;
				}
			}
		} else {
			for (int j = 0; j < cnt; j++) {
				if (isPrimes[j]) {
					if (num % nums[j] == 0) {
						counts[j] += count;
						add(num / nums[j], count, true);
						return;
					}
				} else {
					long gcd = gcd(num, nums[j]);
					if (gcd != 1) {
						num /= gcd;
						long num2 = nums[j] / gcd;
						int count2 = counts[j];
						remove(j);
						add(gcd, count + count2, true);
						add(num, count, true);
						add(num2, count2, true);
						return;
					}
				}
			}
		}
		arraycopy(nums, i, nums, i + 1, cnt - i);
		arraycopy(counts, i, counts, i + 1, cnt - i);
		arraycopy(isPrimes, i, isPrimes, i + 1, cnt - i);
		++cnt;
		nums[i] = num;
		counts[i] = count;
		isPrimes[i] = isPrime;
	}

	static void solve() throws Exception {
		int n = scanInt();
		nums = new long[2 * n];
		counts = new int[2 * n];
		isPrimes = new boolean[2 * n];
		cnt = 0;
		for (int i = 0; i < n; i++) {
			long cur = scanLong();
			long v = (long) pow(cur, 1.0 / 4);
			while (p4(v) > cur) {
				--v;
			}
			while (p4(v) < cur) {
				++v;
			}
			if (p4(v) == cur) {
				add(v, 4, true);
				continue;
			}
			v = (long) pow(cur, 1.0 / 3);
			while (p3(v) > cur) {
				--v;
			}
			while (p3(v) < cur) {
				++v;
			}
			if (p3(v) == cur) {
				add(v, 3, true);
				continue;
			}
			v = (long) pow(cur, 1.0 / 2);
			while (p2(v) > cur) {
				--v;
			}
			while (p2(v) < cur) {
				++v;
			}
			if (p2(v) == cur) {
				add(v, 2, true);
				continue;
			}
			add(cur, 1, false);
		}
		int ans = 1;
		for (int i = 0; i < cnt; i++) {
			ans = (int) ((long) ans * (isPrimes[i] ? counts[i] + 1 : p2(counts[i] + 1)) % 998244353);
		}
		out.println(ans);
		out.flush();
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}