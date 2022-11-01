import static java.lang.Math.max;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int ret = solve(a);
		out.println(ret);
	}

	private static int solve(int[] a) {
		int maxA = 0;
		for (int i : a) {
			maxA = max(maxA, i);
		}
		int[] cnt = new int[maxA + 1];
		for (int i : a) {
			++cnt[i];
		}

		for (int i = 1; i < cnt.length; i++) {
			cnt[i] += cnt[i - 1];
		}

		int[] someDivisor = new int[maxA + 1];
		for (int i = 2; i * i <= maxA; i++) {
			if (someDivisor[i] != 0) {
				continue;
			}
			for (int j = i * i; j <= maxA; j += i) {
				someDivisor[j] = i;
			}
		}

		int[] divisorList = new int[1000];
		int[] primes = new int[100];
		int[] pows = new int[100];

		long ret = 0;

		for (int lcm = 1; lcm <= maxA; lcm++) {
			int value = lcm;
			int pp = 0;
			while (someDivisor[value] > 0) {
				int p = someDivisor[value];
				int pow = 0;
				while (value % p == 0) {
					value /= p;
					++pow;
				}
				primes[pp] = p;
				pows[pp] = pow;
				++pp;
			}
			if (value > 1) {
				primes[pp] = value;
				pows[pp] = 1;
				++pp;
			}
			int dCount = getDivisors(primes, pows, pp, divisorList);
			sort(divisorList, 0, dCount);

			long answer = 1;
			for (int i = 0; i < dCount - 1; i++) {
				int d = divisorList[i];
				int next = divisorList[i + 1];
				int onSegment = cnt[next - 1] - cnt[d - 1];

				answer = answer * modPow(i + 1, onSegment) % MOD;
			}
			int onLastSegment = cnt[maxA] - cnt[lcm - 1];
			long ways = modPow(dCount, onLastSegment) - modPow(dCount - 1, onLastSegment);
			answer = answer * ways % MOD;
			ret += answer;
		}
		ret %= MOD;
		ret += MOD;
		ret %= MOD;
		return (int) ret;
	}

	static int modPow(int a, int pow) {
		int res = 1;
		while (pow > 0) {
			if ((pow & 1) != 0) {
				res = (int) ((long) res * a % MOD);
			}
			a = (int) ((long) a * a % MOD);
			pow >>= 1;
		}
		return res;
	}

	static int getDivisors(int[] primes, int[] pows, int primesCount, int[] answer) {
		return goDivisors(primes, pows, primesCount, 0, 1, answer, 0);
	}

	static int goDivisors(int[] primes, int[] pows, int primesCount, int start, int have,
			int[] answer, int haveAnswer) {
		if (start == primesCount) {
			answer[haveAnswer++] = have;
			return haveAnswer;
		}
		for (int pow = 0; pow <= pows[start]; pow++) {
			haveAnswer = goDivisors(primes, pows, primesCount, start + 1, have, answer, haveAnswer);
			have *= primes[start];
		}

		return haveAnswer;
	}

	static final int MOD = 1000000007;

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