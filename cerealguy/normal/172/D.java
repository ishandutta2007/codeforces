import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class D {

	private static void solve() throws IOException {
		int a = nextInt(), n = nextInt();
		int limit = a + n;
		int[] answer = new int[limit];
		boolean[] notP = new boolean[limit];
		fill(answer, 1);
		for (int p = 2; p * p < limit; p++) {
			if (notP[p]) {
				continue;
			}
			for (int i = p * p; i < limit; i += p) {
				notP[i] = true;
			}

			for (long pow = p * p; pow < limit; pow = pow * p * p) {
				int intPow = (int) pow;
				for (int i = intPow; i < limit; i += intPow) {
					answer[i] *= p * p;
				}
			}
		}
		long sum = 0;
		for (int i = a; i < limit; i++) {
			sum += i / answer[i];
		}
		out.println(sum);
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