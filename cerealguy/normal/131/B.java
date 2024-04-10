import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int n = nextInt();
		int[] cnt = new int[21];
		int add = 10;
		for (int i = 0; i < n; i++) {
			cnt[add + nextInt()]++;
		}
		long res = 0;
		for (int i = 1; i <= add; i++) {
			res += (long) cnt[i + add] * cnt[-i + add];
		}
		long zero = cnt[add];
		res += zero * (zero - 1) / 2;
		out.println(res);
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