import java.io.*;
import java.util.*;

public class C {
	static int[] primes = getPrimes(32);

	static void test() {
		for (int k = 10; k <= 5000; k++) {
			System.err.println(k);
			solveTheProblem(k);
		}
	}

	static void solve() throws IOException {
		// test();
		int k = nextInt();
		List<Integer> result = solveTheProblem(k);

		for (int i = 0; i < result.size(); i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(result.get(i));
		}
		out.println();
	}

	private static List<Integer> solveTheProblem(int k) {
		int limit = 2 * k * k;
		int[] values = new int[k];
		Arrays.fill(values, 1);
		Arrays.fill(values, k / 2, k, 2);

		for (int usePrimes = 1; usePrimes < 10; usePrimes++) {
			int[] canCreate = new int[1 << usePrimes];
			mask: for (int mask = 0; mask < 1 << usePrimes; mask++) {
				long product = 1;
				for (int i = 0; i < usePrimes; i++) {
					if ((mask & (1 << i)) != 0) {
						product *= primes[i];
						if (product > limit) {
							continue mask;
						}
					}
				}
				int count = goAll((int) (limit / product), mask);
				canCreate[mask] = count;
			}
			int[] without = new int[usePrimes];
			int have = 0;
			int[] create = new int[1 << usePrimes];
			for (int bitCount = usePrimes; bitCount > 0 && have < k; --bitCount) {
				for (int m = 0; m < 1 << usePrimes; m++) {
					if (Integer.bitCount(m) != bitCount) {
						continue;
					}
					int ok = canCreate[m];
					int take = ok;
					for (int i = 0; i < usePrimes; i++) {
						if ((m & (1 << i)) == 0) {
							take = Math.min(take, k / 2 - without[i]);
						}
					}
					take = Math.min(take, k - have);
					have += take;
					for (int i = 0; i < usePrimes; i++) {
						if ((m & (1 << i)) == 0) {
							without[i] += take;
						}
					}
					create[m] = take;
					if (have >= k) {
						break;
					}
				}
			}
			if (have >= k) {
				List<Integer> result = new ArrayList<>();
				for (int mask = (1 << usePrimes) - 1; mask >= 0; --mask) {
					if (create[mask] == 0) {
						continue;
					}
					long product = 1;
					for (int i = 0; i < usePrimes; i++) {
						if ((mask & (1 << i)) != 0) {
							product *= primes[i];
						}
					}
					int ok = goAll(limit, product, mask, result, create[mask]);
					if (ok != 0) {
						throw new AssertionError();
					}
				}
				return result;
			}
		}
		throw new AssertionError();
	}

	private static int goAll(int limit, long product, int mask,
			List<Integer> result, int wantToGo) {
		if (wantToGo == 0) {
			return 0;
		}
		if (mask == 0) {
			result.add((int) product);
			return --wantToGo;
		}
		int largestPrimeId = 31 - Integer.numberOfLeadingZeros(mask);
		int p = primes[largestPrimeId];
		mask ^= 1 << largestPrimeId;
		while (wantToGo > 0 && product <= limit) {
			wantToGo = goAll(limit, product, mask, result, wantToGo);
			product *= p;
		}
		return wantToGo;
	}

	private static int goAll(int limit, int mask) {
		if (mask == 0) {
			return 1;
		}
		int largestPrimeId = 31 - Integer.numberOfLeadingZeros(mask);
		int p = primes[largestPrimeId];
		mask ^= 1 << largestPrimeId;
		int answer = 0;
		while (limit > 0) {
			answer += goAll(limit, mask);
			limit /= p;
		}
		return answer;
	}

	private static int[] getPrimes(int size) {
		int[] primes = new int[size];
		int cnt = 0;
		for (int i = 2; cnt < size; i++) {
			if (isPrime(i)) {
				primes[cnt++] = i;
			}
		}
		return primes;
	}

	private static boolean isPrime(int i) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				return false;
			}
		}
		return true;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
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