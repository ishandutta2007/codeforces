import java.io.*;
import java.util.*;

public class C {

	int[] ans1;
	Queue<Integer> q;
	int n, m;
	int[][] gcd, lcm;
	long[][] p;

	boolean check(int u, int i) {
		Arrays.fill(ans1, 0);
		ans1[u] = i;
		q.clear();
		q.add(u);
		while (!q.isEmpty()) {
			u = q.poll();
			for (int j = 0; j < n; j++) {
				if (p[u][j] != 0) {
					long lval = p[u][j] / ans1[u];
					if (lval * ans1[u] != p[u][j])
						return false;
					int val = (int) lval;
					if (gcd(val, ans1[u]) != gcd[u][j])
						return false;
					if (ans1[j] == 0) {
						ans1[j] = val;
						q.add(j);
					} else {
						if (ans1[j] != val)
							return false;
					}
				}
			}
		}
		return true;
	}

	private boolean solve() throws IOException {
		n = nextInt();
		m = nextInt();
		gcd = new int[n][n];
		lcm = new int[n][n];
		p = new long[n][n];
		for (int i = 0; i < m; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			int a = nextInt(), b = nextInt();
			gcd[u][v] = gcd[v][u] = a;
			lcm[u][v] = lcm[v][u] = b;
			if (b % a != 0) {
				System.err.println("FUCk");
				out.println("NO");
				return false;
			}
			p[u][v] = p[v][u] = (long) b * a;
		}
		int[] max = new int[n];
		int[] min = new int[n];
		for (int i = 0; i < n; i++) {
			min[i] = 1;
			for (int j = 0; j < n; j++) {
				if (gcd[i][j] == 0)
					continue;
				max[i] = gcd(max[i], lcm[i][j]);
				min[i] = lcm(min[i], gcd[i][j]);
			}
			if (max[i] % min[i] != 0) {
				out.println("NO");
				return false;
			}
		}
		int[] ans = new int[n];
		ans1 = new int[n];
		q = new ArrayDeque<Integer>();
		for (int i = 0; i < n; i++) {
			if (max[i] == 0) {
				ans[i] = 1;
			}
		}
		loop: while (true) {
			int first = 0;
			while (first < n && ans[first] != 0)
				first++;
			if (first == n)
				break;
			int t = max[first] / min[first];
			for (int i = 1; i * i <= t; i++) {
				if (t % i == 0) {
					if (check(first, i * min[first])) {
						for (int j = 0; j < n; j++) {
							if (ans1[j] != 0)
								ans[j] = ans1[j];
						}
						continue loop;
					}
					if (i * i != t && check(first, t / i * min[first])) {
						for (int j = 0; j < n; j++) {
							if (ans1[j] != 0)
								ans[j] = ans1[j];
						}
						continue loop;
					}
				}
			}
			out.println("NO");
			return false;
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
		}
		out.println();
		return true;
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	int lcm(int a, int b) {
		return a / gcd(a, b) * b;
	}

	public static void main(String[] args) {
		new C().run();
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