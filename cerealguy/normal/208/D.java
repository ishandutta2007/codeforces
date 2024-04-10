import java.io.*;
import java.util.*;

public class D {

	private static void solve() throws IOException {
		int n = nextInt();
		int[] win = new int[n];
		for (int i = 0; i < n; i++) {
			win[i] = nextInt();
		}
		int[] price = new int[5];
		for (int i = 0; i < 5; i++) {
			price[i] = nextInt();
		}
		int money = 0;
		long[] buy = new long[5];
		for (int it = 0; it < n; it++) {
			money += win[it];
			for (int i = 4; i >= 0; --i) {
				buy[i] += money / price[i];
				money %= price[i];
			}
		}
		for (int i = 0; i < 5; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(buy[i]);
		}
		out.println();
		out.println(money);
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