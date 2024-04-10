import static java.lang.System.arraycopy;

import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int n = nextInt();
		int digitsMask = 0;
		for (int i = 0; i < n; i++) {
			digitsMask |= 1 << nextInt();
		}

		int[] string = new int[12];
		int[] string2 = new int[12];
		Set<Integer> gotIps = new HashSet<Integer>();
		for (int oneHalf = 0; oneHalf < 1 << 16; oneHalf++) {
			int length = toString(oneHalf, string);
			int haveMask = 0;
			for (int i = 0; i < length; i++) {
				haveMask |= 1 << string[i];
			}
			if (haveMask != digitsMask) {
				continue;
			}
			// System.err.println("good "+ipToString(oneHalf));
			for (int fullLength = length + 2; fullLength <= length * 2; fullLength++) {
				firstHalf: {
					arraycopy(string, 0, string2, 0, length);
					for (int i = length; i < fullLength; i++) {
						string2[i] = string2[fullLength - 1 - i];
					}
					if (!isPalindrome(string2, fullLength)) {
						break firstHalf;
					}
					for (int thirdPart = 1; thirdPart <= 3 && thirdPart + length < fullLength; thirdPart++) {
						int third = getNumber(string2, length, length + thirdPart);
						if (third < 0) {
							continue;
						}
						int fourth = getNumber(string2, length + thirdPart, fullLength);
						if (fourth < 0) {
							continue;
						}
						int ip = (oneHalf << 16) + (third << 8) + fourth;
						gotIps.add(ip);
					}
				}
				secondHalf: {
					arraycopy(string, 0, string2, fullLength - length, length);
					for (int i = 0; i < fullLength - length; i++) {
						string2[i] = string2[fullLength - 1 - i];
					}
					if (!isPalindrome(string2, fullLength)) {
						break secondHalf;
					}
					// System.err.println(Arrays.toString(Arrays.copyOf(string2,
					// fullLength)));
					for (int firstPart = 1; firstPart <= 3 && firstPart + length < fullLength; firstPart++) {
						int first = getNumber(string2, 0, firstPart);
						if (first < 0) {
							continue;
						}
						int second = getNumber(string2, firstPart, fullLength - length);
						if (second < 0) {
							continue;
						}
						int ip = (oneHalf) + (first << 24) + (second << 16);
						gotIps.add(ip);
					}
				}
			}
		}
		out.println(gotIps.size());
		for (int ip : gotIps) {
			out.println(ipToString(ip));
		}
	}

	private static String ipToString(int ip) {
		return (ip >>> 24) + "." + ((ip >> 16) & 0xFF) + "." + ((ip >> 8) & 0xFF) + "."
				+ (ip & 0xFF);
	}

	private static int getNumber(int[] string, int from, int to) {
		if (to - from > 3 || to - from < 1) {
			return -1;
		}
		if (string[from] == 0) {
			return to - from == 1 ? 0 : -1;
		}
		int ret = 0;
		for (int i = from; i < to; i++) {
			ret = ret * 10 + string[i];
		}
		if (ret >= 0 && ret < 256) {
			return ret;
		} else {
			return -1;
		}
	}

	private static boolean isPalindrome(int[] string, int fullLength) {
		for (int i = 0, j = fullLength - 1; i < j; i++, j--) {
			if (string[i] != string[j]) {
				return false;
			}
		}
		return true;
	}

	private static int toString(int oneHalf, int[] string) {
		String s = Integer.toString(oneHalf >>> 8) + Integer.toString(oneHalf & 0xFF);
		for (int i = 0; i < s.length(); i++) {
			string[i] = s.charAt(i) - '0';
		}
		return s.length();
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