import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int n = nextInt(), x = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		sort(a);
		int less = 0, greater = 0;
		for (int i : a) {
			if (i < x) {
				++less;
			}
			if (i > x) {
				++greater;
			}
		}
		int equal = n - less - greater;
		int answer = add(less, equal, greater);
		out.println(answer);
	}

	static int add(int less, int equal, int greater) {
		int answer = 0;
		while (less >= greater + equal || greater > less + equal) {
			answer++;
			equal++;
		}
		return answer;
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