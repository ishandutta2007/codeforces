import java.io.*;
import java.util.*;

public class D {

	static int n;
	static int m;
	static int[] a;

	private void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		a = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = nextInt();
		}
		int[] res = n % 2 == 0 ? solve1() : solve2();
		if (res == null) {
			out.println(-1);
		} else {
			for (int i : res) {
				out.print(i + " ");
			}
			out.println();
		}
	}

	static int[] solve1() {
		for (int i = 0; i < m; i++) {
			a[i] = Math.min(a[i], n / 2);
		}
		int[] res = new int[n];
		for (int it = 0; it < m; it++) {
			if (a[it] == n / 2) {
				for (int j = 0; j < n; j += 2) {
					res[j] = it + 1;
				}
				a[it] = 0;
				int cnt = 1;
				for (int i = 0; i < m && cnt < n;) {
					if (a[i] > 0) {
						--a[i];
						res[cnt] = i + 1;
						cnt += 2;
					} else {
						i++;
					}
				}
				if (cnt >= n)
					return res;
				else
					return null;
			}
		}
		int cnt = 0;
		for (int i = 0; i < m;) {
			if (a[i] == 0) {
				i++;
			} else {
				--a[i];
				res[cnt] = i + 1;
				cnt += 2;
				if (cnt == n + 1) {
					return res;
				}
				if (cnt == n) {
					cnt = 1;
				}
			}
		}
		return null;
	}

	static int[] solve2() {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			a[i] = Math.min(a[i], n / 2);
			sum += a[i];
		}
		if (sum < n)
			return null;
		int[] res = new int[n];
		int cnt = 0;
		for (int i = 0; i < m;) {
			if (a[i] == 0) {
				i++;
			} else {
				--a[i];
				res[cnt] = i + 1;
				cnt += 2;
				if (cnt == n) {
					return res;
				}
				if (cnt == n + 1) {
					cnt = 1;
				}
			}
		}
		throw new AssertionError();
	}

	public static void main(String[] args) {
		new D().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
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