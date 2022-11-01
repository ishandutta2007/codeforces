import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] d = new int[n];
		for (int i = 0; i < n; i++) {
			d[i] = nextInt();
		}
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextInt();
		}
		int sum = 0;
		int wait = 0;
		int gas = 0;
		int best = 0;
		for (int i = 0; i < n; i++) {
			sum += d[i];
			gas += s[i];
			best = max(best, s[i]);
			while (gas < sum) {
				gas += best;
				wait++;
			}
		}
		int answer = wait * k + sum;
		out.println(answer);
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