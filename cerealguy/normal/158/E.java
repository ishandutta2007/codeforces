import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class E {

	private static void solve() throws IOException {
		int n = nextInt(), k = nextInt();
		int[] t = new int[n];
		int[] d = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
			d[i] = nextInt();
		}
		int answer = sleep(t, d, k);
		out.println(answer);
	}

	static final int DAY = 86400;

	static int sleep(int[] t, int[] d, int canSkip) {
		int n = t.length;
		if (n == 0) {
			return DAY;
		}

		int[] minLastCall = new int[canSkip + 1];
		fill(minLastCall, 1);

		int maxSleep = t[0] - 1;

		for (int call = 0; call < n; call++) {
			for (int skip = canSkip; skip >= 0; --skip) {
				if (skip < canSkip) {
					minLastCall[skip + 1] = min(minLastCall[skip + 1], minLastCall[skip]);
				}
				minLastCall[skip] = max(minLastCall[skip], t[call]) + d[call];
			}
			int wakeUp = call < n - 1 ? t[call + 1] : DAY + 1;
			int getSleep = wakeUp - minLastCall[canSkip];
			maxSleep = max(maxSleep, getSleep);
		}
		return maxSleep;
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