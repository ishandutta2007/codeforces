import static java.math.BigInteger.ZERO;
import static java.math.BigInteger.valueOf;

import java.io.*;
import java.util.*;

public class G {

	static void solve() throws IOException {
		String s = nextToken();
		int n = nextInt();
		String[] p = new String[n];
		int[] l = new int[n];
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextToken();
			l[i] = nextInt();
			r[i] = nextInt();
		}
		int good = solve(s, p, l, r);
		out.println(good);
	}

	private static int solve(String s, String[] p, int[] l, int[] r) {
		int n = p.length;
		// int[][] match = new int[n][s.length() + 1];
		// for (int i = 0; i < s.length(); i++) {
		// for (int j = 0; j < n; j++) {
		// if (s.substring(i).startsWith(p[j])) {
		// match[j][i + 1] = 1;
		// }
		// }
		// }
		// for (int i = 0; i < n; i++) {
		// for (int pos = 1; pos < s.length(); pos++) {
		// match[i][pos] += match[i][pos - 1];
		// }
		// }

		// Set<String> set = new HashSet<>();

		long[][] temp1 = new long[n][];
		long[][] temp2 = new long[n][];
		Hasher[] hashes = new Hasher[n];

		for (int i = 0; i < n; i++) {
			temp1[i] = new long[p[i].length()];
			temp2[i] = new long[p[i].length()];
			hashes[i] = new Hasher(p[i]);
		}
		int[] good2 = new int[n];
		int[] good1 = new int[n];

		Hasher ourHash = new Hasher(s);

		long[] answers = new long[s.length()];

		int ret = 0;

		for (int length = 1; length <= s.length(); length++) {
			for (int pattern = 0; pattern < n; pattern++) {
				long[] arr = temp1[pattern];
				int cnt = 0;
				String what = p[pattern];
				for (int start = 0; start + length <= what.length(); start++) {
					arr[cnt++] = hashes[pattern].subStringHash(start, length);
				}
				Arrays.sort(arr, 0, cnt);
				good2[pattern] = 0;
				long[] arr2 = temp2[pattern];
				good1[pattern] = cnt;

				for (int i = 0; i < cnt;) {
					int j = i;
					while (j < cnt && arr[j] == arr[i]) {
						++j;
					}
					int size = j - i;
					if (size >= l[pattern] && size <= r[pattern]) {
						arr2[good2[pattern]++] = arr[i];
					}
					i = j;
				}
			}

//			System.err.println(Arrays.toString(good));
			int cnt = 0;
			for (int ourStart = 0; ourStart + length <= s.length(); ourStart++) {
				long h = ourHash.subStringHash(ourStart, length);
				boolean ok = true;
//				System.err.println("checking: "+s.substring(ourStart, ourStart + length));
				for (int i = 0; i < n; i++) {
					boolean found = Arrays.binarySearch(temp2[i], 0, good2[i], h) >= 0;
					if (found) {
						continue;
					}
					if (l[i] > 0) {
						if (!found) {
							ok = false;
							break;
						}
					} else {
						found = Arrays.binarySearch(temp1[i], 0, good1[i], h) >= 0;
						if (found) {
							ok = false;
							break;
						}
					}
				}
				if (ok) {
					answers[cnt++] = h;
				}
			}
			Arrays.sort(answers, 0, cnt);
			for (int i = 0; i < cnt;) {
				int j = i;
				while (j < cnt && answers[j] == answers[i]) {
					++j;
				}
				++ret;
				i = j;
			}
		}

		return ret;
	}

	public static int[] prefix(String s) {
		int[] p = new int[s.length() + 1];
		p[0] = -1;
		for (int i = 1, k = 0; i < s.length(); i++) {
			while (k >= 0 && s.charAt(i) != s.charAt(k))
				k = p[k];
			p[i + 1] = ++k;
		}
		return p;
	}

	static class Hasher {
		final static long P = 23917;
		final static long P_1 = valueOf(P).modInverse(ZERO.setBit(64))
				.longValue();
		static long P_1_pows[];
		int n;
		long[] hash;

		static void calcP_1_pows(int len) {
			if (P_1_pows != null && P_1_pows.length > len) {
				return;
			}
			P_1_pows = new long[len + 1];
			P_1_pows[0] = 1;
			for (int i = 0; i < len; i++) {
				P_1_pows[i + 1] = P_1_pows[i] * P_1;
			}
		}

		Hasher(String s) {
			n = s.length();
			int n = s.length();
			long mul = 1;
			hash = new long[n + 1];
			hash[0] = 0;
			for (int i = 0; i < n; i++) {
				hash[i + 1] = hash[i] + mul * s.charAt(i);
				mul *= P;
			}
			calcP_1_pows(n);
		}

		long subStringHash(int start, int len) {
			return (hash[len + start] - hash[start]) * P_1_pows[start];
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("g.in");
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