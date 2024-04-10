import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		// stress();
		int l1 = nextInt(), r1 = nextInt();
		int l2 = nextInt(), r2 = nextInt();
		--l1;
		--l2;
		out.println(get(l1, r1, l2, r2));
	}

	// static void stress() {
	// int max = 40;
	// for (int l1 = 0; l1 < max; l1++) {
	// for (int r1 = l1 + 1; r1 < max; r1++) {
	// for (int l2 = 0; l2 < max; l2++) {
	// for (int r2 = l2 + 1; r2 < max; r2++) {
	// int a = get(l1, r1, l2, r2);
	// int b = getStupid(l1, r1, l2, r2);
	// if (a != b) {
	// System.err.println(l1 + " " + r1 + " " + l2 + " " + r2);
	// System.err.println(a + " " + b);
	// System.err.println(ok.substring(l1, r1));
	// System.err.println(ok.substring(l2, r2));
	// throw new AssertionError();
	// }
	// }
	// }
	// }
	// System.err.println(".");
	// }
	// System.err.println("good");
	// }

	static int get(int l1, int r1, int l2, int r2) {
		int pow1 = maxPowerOfTwo(l1, r1);
		int pow2 = maxPowerOfTwo(l2, r2);

		int answer = 0;
		for (int pow = min(pow1, pow2); pow >= 0; --pow) {
			int a = (r1 >>> pow) << pow;
			int b = (r2 >>> pow) << pow;
			int size = 1 << pow;
			for (int i = 0; i < 5; i++) {
				int aa = a - i * size;
				if (aa <= l1) {
					break;
				}
				if ((aa & size) == 0) {
					continue;
				}
				for (int j = 0; j < 5; j++) {
					int bb = b - j * size;
					if (bb <= l2) {
						break;
					}
					if ((bb & size) == 0) {
						continue;
					}
					int right = min(r1 - aa, r2 - bb);
					int left = min(aa - l1 - 1, bb - l2 - 1);
					right = min(right, size - 1);
					left = min(left, size - 1);
					answer = max(answer, right + left + 1);
				}
			}
		}
		return answer;
	}

//	static String gen(int k) {
//		if (k == 0) {
//			return "a";
//		}
//		return gen(k - 1) + ((char) ('a' + k)) + gen(k - 1);
//	}
//
//	static String ok = gen(10);
//
//	static int getStupid(int l1, int r1, int l2, int r2) {
//		String a = ok.substring(l1, r1);
//		String b = ok.substring(l2, r2);
//		int best = 0;
//		while (!a.isEmpty()) {
//			for (int index = 0; index < b.length(); index++) {
//				int match = 0;
//				for (; match < a.length() && index + match < b.length(); match++) {
//					if (a.charAt(match) != b.charAt(index + match)) {
//						break;
//					}
//				}
//				best = max(best, match);
//			}
//			a = a.substring(1);
//		}
//		return best;
//	}

	static int maxPowerOfTwo(int l, int r) {
		for (int k = 30; k >= 0; --k) {
			int l1 = l >>> k, r1 = r >>> k;
			if (l1 < r1) {
				return k;
			}
		}
		throw new AssertionError();
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