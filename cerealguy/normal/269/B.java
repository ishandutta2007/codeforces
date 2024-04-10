import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int plants = nextInt(), types = nextInt();
		Plant[] p = new Plant[plants];
		for (int i = 0; i < plants; i++) {
			p[i] = new Plant(nextInt() - 1, stupidInput());
		}
		Arrays.sort(p);

		int[] type = new int[plants];
		for (int i = 0; i < plants; i++) {
			type[i] = p[i].type;
		}

		int answer = solve(type, types);
		out.println(answer);
	}

	private static int solve(int[] type, int types) {
		int n = type.length;

		int[] countSuffix = new int[types];
		for (int i = 0; i < n; i++) {
			++countSuffix[type[i]];
		}

		int[] dp = new int[types];
		fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for (int t : type) {
			countSuffix[t]--;


			for (int usedThings = 0; usedThings < types - 1; usedThings++) {
				int priceToMove = countSuffix[usedThings];
				priceToMove += dp[usedThings];
				// priceToMove += countPrefix[usedThings + 1];
				if (dp[usedThings + 1] > priceToMove) {
					dp[usedThings + 1] = priceToMove;
				}
			}
			for (int i = 0; i < t; i++) {
				dp[i]++;
			}
//			System.err.println(Arrays.toString(dp));

		}
		for (int usedThings = 0; usedThings < types - 1; usedThings++) {
			int priceToMove = countSuffix[usedThings];
			priceToMove += dp[usedThings];
			// priceToMove += countPrefix[usedThings + 1];
			if (dp[usedThings + 1] > priceToMove) {
				dp[usedThings + 1] = priceToMove;
			}
		}

		return dp[types - 1];
	}

	static class Plant implements Comparable<Plant> {
		int type;
		long pos;

		public Plant(int type, long pos) {
			this.type = type;
			this.pos = pos;
		}

		@Override
		public int compareTo(Plant o) {
			return Long.compare(pos, o.pos);
		}
	}

	static long stupidInput() throws IOException {
		String s = nextToken();
		int dot = s.indexOf('.');
		if (dot < 0) {
			return Long.parseLong(s) * 1000000L;
		} else {
			long val1 = Long.parseLong(s.substring(0, dot));
			int len = s.substring(dot + 1).length();
			long val2 = Long.parseLong(s.substring(dot + 1));
			for (int i = 0; i < 6 - len; i++) {
				val2 *= 10;
			}
			return val1 * 1000000L + val2;
		}
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		if (new File("b.in").exists()) {
			br = new BufferedReader(new FileReader("b.in"));
		} else {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		out = new PrintWriter(System.out);
		solve();
		out.close();
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