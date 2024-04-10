import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class F {

	private static void solve() throws IOException {
		// stress();
		int n = nextInt(), m = nextInt();
		int k = nextInt();
		boolean[][] b = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			if (s.length() != m) {
				throw new AssertionError();
			}
			for (int j = 0; j < m; j++) {
				b[i][j] = s.charAt(j) == '1';
			}
		}
		out.println(get(b, k));
	}

	static long get(boolean[][] b, int k) {
		if (k <= 0) {
			throw new AssertionError();
		}
		int n = b.length, m = b[0].length;
		if (n < 3 || m < 3) {
			return 0;
		}
		boolean[][] star = star(b);
		n -= 2;
		m -= 2;
		if (k > n * m) {
			return 0;
		}
		int[] cnt = new int[m];
		long res = 0;
		for (int top = 0; top < n; top++) {
			fill(cnt, 0);
			for (int bottom = top + 1; bottom <= n; bottom++) {
				boolean[] cur = star[bottom - 1];
				for (int i = 0; i < m; i++) {
					if (cur[i])
						++cnt[i];
				}
				res += ways(cnt, k);
			}
		}
		return res;
	}

	static long getStupid(boolean[][] b, int k) {
		int res = 0;
		int n = b.length, m = b[0].length;
		for (int i = 0; i < n; i++) {
			for (int i1 = i + 1; i1 <= n; i1++) {
				for (int j = 0; j < m; j++) {
					for (int j1 = j + 1; j1 <= m; j1++) {
						boolean[][] b1 = new boolean[i1 - i][j1 - j];
						if (b1.length < 3 || b1[0].length < 3) {
							continue;
						}
						for (int l = 0; l < b1.length; l++) {
							for (int l2 = 0; l2 < b1[0].length; l2++) {
								b1[l][l2] = b[i + l][j + l2];
							}
						}
						boolean[][] star = star(b1);
						int cnt = 0;
						for (boolean[] star1 : star) {
							for (boolean star2 : star1) {
								if (star2) {
									cnt++;
								}
							}
						}
						if (cnt >= k) {
							res++;
						}
					}
				}
			}
		}
		return res;
	}

	static Random rng = new Random();

	static void stress() {
		while (true) {
			int n = rng.nextInt(5) + 3;
			int m = rng.nextInt(5) + 3;
			boolean[][] b = new boolean[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					b[i][j] = rng.nextBoolean();
				}
			}
			int k = rng.nextInt(n * m) + 1;
			long got = get(b, k);
			long stup = getStupid(b, k);
			if (got != stup) {
				System.err.println(n + " " + m + " " + k);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						System.err.print(b[i][j] ? '1' : '0');
					}
					System.err.println();
				}
				System.err.println("got " + got);
				System.err.println("stup " + stup);
				throw new AssertionError();
			}
		}
	}

	static int ways(int[] cnt, int k) {
		int ret = 0;
		int n = cnt.length;
		int i = 0, j = 0;
		int sum = 0;
		for (; i < n; i++) {
			if (i > 0) {
				sum -= cnt[i - 1];
			}
			while (j < n && sum < k) {
				sum += cnt[j++];
			}
			if (sum >= k) {
				ret += n - j + 1;
			}
		}
		return ret;
	}

	static boolean[][] star(boolean[][] b) {
		int n = b.length, m = b[0].length;
		boolean[][] star = new boolean[n - 2][m - 2];
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				star[i - 1][j - 1] = b[i][j] && b[i - 1][j] && b[i][j - 1] && b[i + 1][j]
						&& b[i][j + 1];
			}
		}
		return star;
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