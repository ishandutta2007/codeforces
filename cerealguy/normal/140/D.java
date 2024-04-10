import static java.lang.Math.max;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class D {

	private static void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		final int CONTEST = 12 * 60 - 10;
		final int HALFCONTEST = 6 * 60 - 10;
		sort(a);
		int sum = 0, cnt = 0;
		while (cnt < n && sum + a[cnt] <= CONTEST) {
			sum += a[cnt++];
		}
		a = copyOf(a, cnt);
		int time = 0;
		int score = 0;
		for (int i = 0; i < cnt; i++) {
			time += a[i];
			score += max(time, HALFCONTEST) - HALFCONTEST;
		}
		out.println(cnt + " " + score);
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