import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		long n = nextLong();
		long ways = solve(n);
		out.println(ways);
	}

	private static long solve(long n) {
		if (n % 3 != 0) {
			return 0;
		}
		n /= 3;

		Factor[] factors = factorize(n);

//		System.err.println(ArraystoString(factors));
		int[] pows = new int[factors.length];
		C.n = n;
		C.factors = factors;
		C.pows1 = pows;
		C.pows2 = new int[factors.length];
		C.productLeft = new long[factors.length + 1];

		go1(0, 1);
		return ways;
	}

	static Factor[] factors;
	static int[] pows1;

	static int[] pows2;
	static long[] productLeft;

	static long n;

	static long number1;

	static long ways;

	private static void go1(int start, long number) {
		if (start == factors.length) {
			productLeft[factors.length] = 1;
			for (int i = factors.length - 1; i >= 0; --i) {
				productLeft[i] = productLeft[i + 1];
				for (int j = 0; j < factors[i].pow - pows1[i]; j++) {
					productLeft[i] *= factors[i].p;
				}
			}
			long allLeft = productLeft[0];
			if (number > allLeft) {
				return;
			}
			if (number * number > allLeft) {
				return;
			}
			number1 = number;
			go2(0, 1);
			return;
		}

		for (int pow = 0; pow <= factors[start].pow; pow++) {
			pows1[start] = pow;
			go1(start + 1, number);
			number *= factors[start].p;
		}
	}

	private static void go2(int start, long number) {
		if (start == factors.length) {
			long number2 = number;
			long number3 = n / number1 / number2;
			check(number1, number2, number3);
			return;
		}
		if (productLeft[start] * number < number1) {
			return;
		}
		long ok = n / (number1 * number);
		if (ok < number1 || ok < number) {
			return;
		}

		for (int pow = 0; pow + pows1[start] <= factors[start].pow; pow++) {
			pows2[start] = pow;
			go2(start + 1, number);
			number *= factors[start].p;
		}
	}

	private static void check(long number1, long number2, long number3) {
		long sum = (number1 + number2 + number3);
		if ((sum & 1) != 0) {
			return;
		}
		if (number1 > number2 || number2 > number3) {
			return;
		}
		if (sum <= 2 * number3) {
			return;
		}
		
		if (number1 < number2 && number2 < number3) {
			ways += 6;
		} else {
			if (number1 == number2 && number2 == number3) {
				++ways;
			} else {
				ways += 3;
			}
		}
	}

	static Factor[] factorize(long n) {
		List<Factor> list = new ArrayList<>();
		if (n % 2 == 0) {
			list.add(new Factor(2, Long.numberOfTrailingZeros(n)));
			n >>= Long.numberOfTrailingZeros(n);
		}
		for (long p = 3; p * p <= n; p++) {
			if (n % p != 0) {
				continue;
			}
			int pow = 0;
			while (n % p == 0) {
				++pow;
				n /= p;
			}
			list.add(new Factor(p, pow));
		}
		if (n > 1) {
			list.add(new Factor(n, 1));
		}
		return (Factor[]) list.toArray(new Factor[list.size()]);
	}

	static class Factor {
		long p;
		int pow;

		public Factor(long p, int pow) {
			this.p = p;
			this.pow = pow;
		}

		@Override
		public String toString() {
			return "Factor [p=" + p + ", pow=" + pow + "]";
		}
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