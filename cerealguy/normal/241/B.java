import java.io.*;
import java.util.*;

public class B {

	static final int MOD = 1000000000 + 7;

	private static void solve() throws IOException {
		int n = nextInt();
		long m = nextLong();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		long m1 = n * (n - 1L) / 2 - m;
		int answer1 = solve(a, m1);
		int answer2 = sumXorPairs(a);

		int answer = answer2 - answer1;
		if (answer < 0) {
			answer += MOD;
		}
		out.println(answer);
	}

	private static int solve(int[] a, long m) {
		int valueLeft = 0, valueRight = Integer.MIN_VALUE;
		final int highBit = 30;
		while (valueRight - valueLeft != 1) {
			int mid = valueLeft + valueRight >>> 1;
			if (countLess0(a, highBit, mid) < m) {
				valueLeft = mid;
			} else {
				valueRight = mid;
			}
		}
		long count = countLess0(a, highBit, valueLeft);
		long answer = sumLess0(a, highBit, valueLeft);

		long countLeft = (m - count) % MOD;
		long leftLong = ((long) valueLeft) & 0xFFFFFFFF;
		leftLong %= MOD;
		answer += countLeft * leftLong;

		return (int) (answer % MOD);
	}

	private static long sumLess0(int[] a, int highBit, int value) {
		if (highBit < 0) {
			return 0;
		}
		int test = 1 << highBit;
		int withBit = countWithBit(a, test);
		int withoutBit = a.length - withBit;

		int[] a0 = getA1(a, test, 0, withoutBit);
		int[] a1 = getA1(a, test, test, withBit);

		if ((value & test) != 0) {
			long curSum = sumXorPairs(a0) + sumXorPairs(a1);
			return (curSum + sumLess1(Arrays.asList(a0), Arrays.asList(a1), highBit - 1, value))
					% MOD;
		} else {
			long res = 0;
			if (a0.length > 0) {
				res += sumLess0(a0, highBit - 1, value);
			}
			if (a1.length > 0) {
				res += sumLess0(a1, highBit - 1, value);
			}
			return res % MOD;
		}
	}

	private static long sumLess1(List<int[]> aList, List<int[]> bList, int highBit, int value) {
		if (highBit < 0) {
			return 0;
		}
		int k = aList.size();
		int test = 1 << highBit;

		if ((value & test) != 0) {
			List<int[]> newAList = new ArrayList<int[]>();
			List<int[]> newBList = new ArrayList<int[]>();
			long add = 0;
			for (int it = 0; it < k; it++) {
				int[] a = aList.get(it);
				int[] b = bList.get(it);
				int with1 = countWithBit(a, test);
				int without1 = a.length - with1;
				int with2 = countWithBit(b, test);
				int without2 = b.length - with2;
				int[] a1 = getA1(a, test, test, with1);
				int[] b0 = getA1(b, test, 0, without2);
				int[] a0 = getA1(a, test, 0, without1);
				int[] b1 = getA1(b, test, test, with2);
				if ((long) with1 * without2 != 0) {
					newAList.add(a1);
					newBList.add(b0);
				}
				if ((long) with2 * without1 != 0) {
					newAList.add(a0);
					newBList.add(b1);
				}
				add += sumXorPairs(a0, b0);
				add += sumXorPairs(a1, b1);
			}
			return (add + sumLess1(newAList, newBList, highBit - 1, value)) % MOD;
		} else {
			List<int[]> newAList = new ArrayList<int[]>();
			List<int[]> newBList = new ArrayList<int[]>();
			for (int it = 0; it < k; it++) {
				int[] a = aList.get(it);
				int[] b = bList.get(it);
				int with1 = countWithBit(a, test);
				int without1 = a.length - with1;
				int with2 = countWithBit(b, test);
				int without2 = b.length - with2;
				if ((long) with1 * with2 != 0) {
					int[] a1 = getA1(a, test, test, with1);
					int[] b1 = getA1(b, test, test, with2);
					newAList.add(a1);
					newBList.add(b1);
				}
				if ((long) without1 * without2 != 0) {
					int[] a0 = getA1(a, test, 0, without1);
					int[] b0 = getA1(b, test, 0, without2);
					newAList.add(a0);
					newBList.add(b0);
				}
			}
			return sumLess1(newAList, newBList, highBit - 1, value);
		}
	}

	static int sumXorPairs(int[] a) {
		long res = 0;
		for (int bit = 0; bit < 31; bit++) {
			int with = countWithBit(a, 1 << bit);
			int without = a.length - countWithBit(a, 1 << bit);
			res += ((long) with * without % MOD) * (1 << bit);
		}
		res %= MOD;
		return (int) res;
	}

	static int sumXorPairs(int[] a, int[] b) {
		long res = 0;
		for (int bit = 0; bit < 31; bit++) {
			{
				int with = countWithBit(a, 1 << bit);
				int without = b.length - countWithBit(b, 1 << bit);
				res += ((long) with * without % MOD) * (1 << bit);
			}
			{
				int with = countWithBit(b, 1 << bit);
				int without = a.length - countWithBit(a, 1 << bit);
				res += ((long) with * without % MOD) * (1 << bit);
			}
		}
		res %= MOD;
		return (int) res;
	}

	private static long countLess0(int[] a, int highBit, int value) {
		if (highBit < 0) {
			return 0;
		}
		int test = 1 << highBit;
		int withBit = countWithBit(a, test);
		int withoutBit = a.length - withBit;
		long pairs0 = ((long) withBit * (withBit - 1) >> 1)
				+ ((long) withoutBit * (withoutBit - 1) >> 1);

		int[] a0 = getA1(a, test, 0, withoutBit);
		int[] a1 = getA1(a, test, test, withBit);
		// System.err.println(a0.length+" "+a1.length+" "+highBit);

		if ((value & test) != 0) {
			return pairs0 + countLess1(Arrays.asList(a0), Arrays.asList(a1), highBit - 1, value);
		} else {
			long res = 0;
			if (a0.length > 0) {
				res += countLess0(a0, highBit - 1, value);
			}
			if (a1.length > 0) {
				res += countLess0(a1, highBit - 1, value);
			}
			return res;
		}
	}

	private static int countWithBit(int[] a, int test) {
		int withBit = 0;
		for (int i : a) {
			if ((i & test) != 0) {
				++withBit;
			}
		}
		return withBit;
	}

	private static long countLess1(List<int[]> aList, List<int[]> bList, int highBit, int value) {
		if (highBit < 0) {
			return 0;
		}
		int k = aList.size();
		int test = 1 << highBit;
		long pairs0 = 0;

		for (int it = 0; it < k; it++) {
			int[] a = aList.get(it);
			int[] b = bList.get(it);
			int with1 = countWithBit(a, test);
			int without1 = a.length - with1;
			int with2 = countWithBit(b, test);
			int without2 = b.length - with2;
			pairs0 += (long) with1 * with2 + (long) without1 * without2;
		}

		if ((value & test) != 0) {
			List<int[]> newAList = new ArrayList<int[]>();
			List<int[]> newBList = new ArrayList<int[]>();
			for (int it = 0; it < k; it++) {
				int[] a = aList.get(it);
				int[] b = bList.get(it);
				int with1 = countWithBit(a, test);
				int without1 = a.length - with1;
				int with2 = countWithBit(b, test);
				int without2 = b.length - with2;
				if ((long) with1 * without2 != 0) {
					int[] a1 = getA1(a, test, test, with1);
					int[] b0 = getA1(b, test, 0, without2);
					newAList.add(a1);
					newBList.add(b0);
				}
				if ((long) with2 * without1 != 0) {
					int[] a0 = getA1(a, test, 0, without1);
					int[] b1 = getA1(b, test, test, with2);
					newAList.add(a0);
					newBList.add(b1);
				}
			}
			return pairs0 + countLess1(newAList, newBList, highBit - 1, value);
		} else {
			List<int[]> newAList = new ArrayList<int[]>();
			List<int[]> newBList = new ArrayList<int[]>();
			for (int it = 0; it < k; it++) {
				int[] a = aList.get(it);
				int[] b = bList.get(it);
				int with1 = countWithBit(a, test);
				int without1 = a.length - with1;
				int with2 = countWithBit(b, test);
				int without2 = b.length - with2;
				if ((long) with1 * with2 != 0) {
					int[] a1 = getA1(a, test, test, with1);
					int[] b1 = getA1(b, test, test, with2);
					newAList.add(a1);
					newBList.add(b1);
				}
				if ((long) without1 * without2 != 0) {
					int[] a0 = getA1(a, test, 0, without1);
					int[] b0 = getA1(b, test, 0, without2);
					newAList.add(a0);
					newBList.add(b0);
				}
			}
			return countLess1(newAList, newBList, highBit - 1, value);
		}
	}

	private static int[] getA1(int[] a, int test, int value, int with1) {
		int[] res = new int[with1];
		int cnt = 0;
		for (int i : a) {
			if ((i & test) == value) {
				res[cnt++] = i;
			}
		}
		return res;
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