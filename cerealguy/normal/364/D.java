import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
		// long time = System.currentTimeMillis();
		long timeLimit = System.currentTimeMillis() + 3300;
		Random rng = new Random(58 + 50216);
		int n = (int) nextLong();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		long answer = 1;
		while (System.currentTimeMillis() < timeLimit) {
			int index = rng.nextInt(n);
			long best = checkDivisorsOf(a, a[index]);
			answer = Math.max(answer, best);
		}
		out.println(answer);
		// System.err.println(System.currentTimeMillis() - time);
	}

	static class MyLong {
		long value;

		@Override
		public int hashCode() {
			return (int) ((value * 50215) ^ (value >>> 32));
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			MyLong other = (MyLong) obj;
			if (value != other.value)
				return false;
			return true;
		}
	}

	static MyLong[] temporary = new MyLong[10000];
	static {
		for (int i = 0; i < temporary.length; i++) {
			temporary[i] = new MyLong();
		}
	}

	static int[] countForId = new int[10000];
	static Map<MyLong, Integer> map = new HashMap<MyLong, Integer>(10000);

	private static long checkDivisorsOf(long[] a, long value) {
		map.clear();
		for (long i : a) {
			long gcd = binaryGCD(i, value);
			MyLong myLong = temporary[map.size()];
			myLong.value = gcd;
			Integer id = map.get(myLong);
			if (id == null) {
				countForId[map.size()] = 0;
				id = map.size();
				map.put(myLong, id);
			}
			countForId[id]++;
		}
		// System.err.println("time: "+time);
		// System.err.println(map.size());
		long[] divisor = new long[map.size()];
		int[] count = new int[map.size()];
		int cnt = 0;
		for (Map.Entry<MyLong, Integer> entry : map.entrySet()) {
			divisor[cnt] = entry.getKey().value;
			count[cnt] = countForId[entry.getValue()];
			++cnt;
		}
		int[] newCount = new int[map.size()];
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < cnt; j++) {
				if (divisor[j] % divisor[i] == 0) {
					newCount[i] += count[j];
				}
			}
		}
		long best = 1;
		int want = (a.length + 1) >> 1;
		for (int i = 0; i < cnt; i++) {
			if (newCount[i] >= want) {
				best = Math.max(best, divisor[i]);
			}
		}
		return best;
	}

	static long gcd(long a, long b) {
		while (a > 0 && b > 0) {
			if (a < Integer.MAX_VALUE && b < Integer.MAX_VALUE) {
				return intGCD((int) a, (int) b);
			}
			if (a > b) {
				a %= b;
			} else {
				b %= a;
			}
		}
		return a | b;
	}

	private static long intGCD(int a, int b) {
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			} else {
				b %= a;
			}
		}
		return a | b;
	}

	static long binaryGCD(long x, long y) {
		if (x == 0)
			return y;

		if (y == 0)
			return x;

		long cf2 = Long.numberOfTrailingZeros(x | y);

		x >>= Long.numberOfTrailingZeros(x);

		for (;;) {
			y >>= Long.numberOfTrailingZeros(y);

			if (x == y)
				break;

			if (x > y) {
				long t = x;
				x = y;
				y = t;
			}
			if (x == 1)
				break;

			y -= x;
		}

		return x << cf2;
	}

	static BufferedReader br;
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

	public static long nextLong() throws IOException {
		int c = br.read();
		while ((c < '0' || c > '9') && c != '-')
			c = br.read();
		boolean negative = false;
		if (c == '-') {
			negative = true;
			c = br.read();
		}
		long m = 0;
		while (c >= '0' && c <= '9') {
			m = m * 10 + c - '0';
			c = br.read();
		}
		return negative ? -m : m;
	}
}