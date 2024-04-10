import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int n = nextInt();
		int[][] friends = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				friends[i][nextInt() - 1] = j;
			}
		}
		int[] alex = new int[n];
		for (int i = 0; i < n; i++) {
			alex[nextInt() - 1] = i;
		}

		int[] answer = new int[n];

		for (int friend = 0; friend < n; friend++) {
			int best = -1;
			int alexBest = -1;
			int[] rating = friends[friend];
			for (int i = 0; i < n; i++) {
				if (i == friend) {
					continue;
				}
				if (alexBest < 0 || alex[alexBest] > alex[i]) {
					alexBest = i;
					if (best < 0 || rating[i] < rating[best]) {
						best = i;
					}
				}
			}
			answer[friend] = best;
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(answer[i] + 1);
		}
		out.println();
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