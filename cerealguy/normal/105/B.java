import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class B {

	private void solve() throws IOException {
		int senators = nextInt();
		int candies = nextInt();
		scoreA = nextInt();
		lvl = new int[senators];
		unloyal = new int[senators];
		for (int i = 0; i < senators; i++) {
			lvl[i] = nextInt();
			unloyal[i] = 10 - nextInt() / 10;
		}
		n = senators;
		give = new int[n];
		res = 0;
		go(0, candies);
		out.println(res);
	}

	static double res;
	static int[] lvl;
	static int[] unloyal;
	static int[] give;
	static int n;
	static int scoreA;

	static double probability() {
		double res = 0;
		for (int mask = 0; mask < 1 << n; mask++) {
			double p = 1;
			int scoreB = 0;
			int cntGood = Integer.bitCount(mask);
			for (int i = 0; i < n; i++) {
				int cnt = unloyal[i] - give[i];
				if ((mask & (1 << i)) == 0) {
					scoreB += lvl[i];
					p *= cnt * .1;
				} else {
					p *= (10 - cnt) * .1;
				}
			}
			if (2 * cntGood > n) {
				res += p;
			} else {
				res += p * scoreA / (scoreA + scoreB);
			}
		}
		return res;
	}

	static void go(int man, int candies) {
		if (man == n) {
			res = max(res, probability());
			return;
		}
		give[man] = 0;
		go(man + 1, candies);
		for (int i = 1; i <= min(unloyal[man], candies); i++) {
			give[man] = i;
			go(man + 1, candies - i);
		}
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			new B().solve();
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