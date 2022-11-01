import java.io.*;
import java.util.*;

public class C {

	static final int MOD = 1000000007;

	static void solve() throws IOException {
//		stress();
		int n = nextInt(), k = nextInt();
		String s = nextToken();
		int answer = solve(k, s);
		out.println(answer);
	}

	private static int solve(int k, String s) {
		int n = s.length();

		if (k > n * (n + 1) / 2) {
			return 0;
		}

		int[][] greater = new int[n + 1][k + 1];
		int[][] lessEqual = new int[n + 1][k + 1];
		int[] lessEqualSum = new int[k + 1];

		lessEqual[n][0] = 1;

		for (int last = n - 1; last >= 0; --last) {
			int countLess = s.charAt(last) - 'a';
			for (int i = 0; i <= k; i++) {
				lessEqualSum[i] = add(lessEqualSum[i], lessEqual[last + 1][i]);

				int value = lessEqualSum[i];

				int stop = n;

				for (int nextGreater = last + 1; nextGreater <= n; nextGreater++) {
					int count = nextGreater - last - 1;
					int added = count * (n - nextGreater);
					if (added > i) {
						stop = nextGreater;
						break;
					}
					value = add(value, greater[nextGreater][i - added]);
				}
				
				for (int nextGreater = n; nextGreater > stop; --nextGreater) {
					int count = nextGreater - last - 1;
					int added = count * (n - nextGreater);
					if (added > i) {
						break;
					}
					value = add(value, greater[nextGreater][i - added]);
				}

				lessEqual[last][i] = mul(value, countLess);
			}

			int strings = n - last;
			int countGreater = 'z' - s.charAt(last);
			for (int i = strings; i <= k; i++) {
				int value = lessEqualSum[i - strings];
				
				int stop = n;

				for (int nextGreater = last + 1; nextGreater <= n; nextGreater++) {
					int count = nextGreater - last - 1;
					int added = count * (n - nextGreater) + strings;
					if (added > i) {
						stop = nextGreater;
						break;
					}
					value = add(value, greater[nextGreater][i - added]);
				}
				
				for (int nextGreater = n; nextGreater > stop; --nextGreater) {
					int count = nextGreater - last - 1;
					int added = count * (n - nextGreater) + strings;
					if (added > i) {
						break;
					}
					value = add(value, greater[nextGreater][i - added]);
				}

				greater[last][i] = mul(value, countGreater);
			}
		}

		int answer = 0;
		for (int equalPrefix = 0; equalPrefix < n; equalPrefix++) {
			answer = add(answer, lessEqual[equalPrefix][k]);
			int strings = n - equalPrefix;
			int count = equalPrefix;
			int added = count * strings;
			if (added <= k) {
				answer = add(answer, greater[equalPrefix][k - added]);
			}
		}
		answer = add(answer, lessEqual[n][k]);
		return answer;
	}

	private static int add(int i, int j) {
		i += j;
		if (i >= MOD) {
			i -= MOD;
		}
		return i;
	}

	static int mul(int i, int j) {
		return (int) ((long) i * j % MOD);
	}

	static Random rng = new Random(58);

	static void oneTest() {
		int n = rng.nextInt(4) + 1;
		// int n = 2000;
		char[] c = new char[n];
		for (int i = 0; i < n; i++) {
			c[i] = (char) ('a' + rng.nextInt(4));
			c[i] = (char) ('z' - rng.nextInt(4));
		}
		int k = rng.nextInt(Math.min(2000, n * (n + 1) / 2) + 1);
		String s = new String(c);
		int smart = solve(k, s);
		int stup = getStupid(s, k);
		// int stup = smart;
		if (stup != smart) {
			System.err.println(s.length() + " " + k);
			System.err.println(s);
			System.err.println("smart " + smart);
			System.err.println("STUPID " + stup);
			throw new AssertionError();
		}
		System.err.println("pass");
	}

	static void stress() {
		while (true) {
			oneTest();
		}
	}

	static int getStupid(String s, int k) {
		return goStupid(s, k, new char[s.length()], 0);
	}

	private static int goStupid(String s, int k, char[] t, int start) {
		if (t.length == start) {
			return count(s, new String(t)) == k ? 1 : 0;
		}
		int ret = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			t[start] = (char) i;
			ret += goStupid(s, k, t, start + 1);
		}
		return ret;
	}

	static int count(String s, String t) {
		int n = s.length();
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (t.substring(i, j).compareTo(s.substring(i, j)) > 0) {
					++ret;
				}
			}
		}
		return ret;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
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