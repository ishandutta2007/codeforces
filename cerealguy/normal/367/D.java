import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
		int n = nextInt(), sets = nextInt();
		int d = nextInt();
		int[] setId = new int[n];
		Arrays.fill(setId, -1);
		for (int i = 0; i < sets; i++) {
			int setSize = nextInt();
			for (int j = 0; j < setSize; j++) {
				setId[nextInt() - 1] = i;
			}
		}
		int[] cnt = new int[sets];
		for (int i = 0; i < d; i++) {
			++cnt[setId[i]];
		}
		int mask = 0;
		for (int i = 0; i < sets; i++) {
			if (cnt[i] > 0) {
				mask |= 1 << i;
			}
		}

		boolean[] notEnough = new boolean[1 << sets];
		for (int start = 0; start + d <= n; start++) {
			if (start > 0) {
				int set1 = setId[start - 1];
				if (--cnt[set1] == 0) {
					mask &= ~(1 << set1);
				}
				int set2 = setId[start + d - 1];
				if (++cnt[set2] == 1) {
					mask |= 1 << set2;
				}
			}
			notEnough[(1 << sets) - 1 - mask] = true;
		}

		int bestAnswer = Integer.MAX_VALUE;

		for (int m = (1 << sets) - 1; m >= 0; --m) {
			if (!notEnough[m]) {
				bestAnswer = Math.min(bestAnswer, Integer.bitCount(m));
				continue;
			}
			for (int bit = 0; bit < sets; bit++) {
				notEnough[m & ~(1 << bit)] = true;
			}
		}
		out.println(bestAnswer);
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("d.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
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
}