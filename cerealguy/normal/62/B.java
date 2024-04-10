import static java.lang.Math.PI;

import java.io.*;
import java.util.*;

public class B {

	int n, k;
	char[] entered;
	int[][] positions;

	private void solve() throws IOException {
		n = nextInt();
		k = nextInt();
		entered = nextToken().toCharArray();
		int[] cnt = new int[26];
		for (int i = 0; i < entered.length; i++) {
			cnt[entered[i] - 'a']++;
		}
		positions = new int[26][];
		for (int i = 0; i < 26; i++) {
			positions[i] = new int[cnt[i]];
		}
		Arrays.fill(cnt, 0);
		for (int i = 0; i < entered.length; i++) {
			positions[entered[i] - 'a'][cnt[entered[i] - 'a']++] = i;
		}
		for (int i = 0; i < n; i++) {
			out.println(distance(nextToken().toCharArray()));
		}
	}

	long distance(char[] s) {
		long res = 0;
		for (int i = 0; i < s.length; i++) {
			int c = s[i] - 'a';
			if (positions[c].length == 0) {
				res += s.length;
				continue;
			}
			int[] p = positions[c];
			int l = -1, r = p.length;
			while (r - l > 1) {
				int m = (r + l) / 2;
				if (p[m] <= i) {
					l = m;
				} else {
					r = m;
				}
			}
			int ans = Integer.MAX_VALUE;
			if (l != -1)
				ans = Math.min(ans, i - p[l]);
			if (r != p.length)
				ans = Math.min(ans, p[r] - i);
			res += ans;
		}
		return res;
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}