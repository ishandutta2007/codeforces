import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int n = nextInt();
		int[] cnt = new int[5];
		for (int i = 0; i < n; i++) {
			cnt[nextInt()]++;
		}
		int ans = 0;
		{
			ans += cnt[4];
		}
		{
			ans += cnt[3];
			cnt[1] -= min(cnt[1], cnt[3]);
		}
		{
			ans += cnt[2] / 2;
			if ((cnt[2] & 1) != 0) {
				ans++;
				cnt[1] -= min(cnt[1], 2);
			}
		}
		{
			ans += (cnt[1] + 3) / 4;
		}
		out.println(ans);
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