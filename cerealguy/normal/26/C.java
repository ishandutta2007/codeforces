import java.io.*;
import java.util.*;

public class C implements Runnable {

	private void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		int a = nextInt(), b = nextInt(), c = nextInt();
		if (n * m % 2 == 1) {
			out.println("IMPOSSIBLE");
			return;
		}
		char[][] x = new char[n][m];
		if (m % 2 == 1) {
			if (b < (n / 2)) {
				out.println("IMPOSSIBLE");
				return;
			}
			b -= n / 2;
			boolean t = false;
			for (int i = 0; i < n; i += 2) {
				x[i][m - 1] = t ? 'b' : 'a';
				x[i + 1][m - 1] = t ? 'b' : 'a';
				t = !t;
			}
			m--;
		}
		if (n % 2 == 1) {
			if (a < (m / 2)) {
				out.println("IMPOSSIBLE");
				return;
			}
			a -= m / 2;
			boolean t = false;
			for (int i = 0; i < m; i += 2) {
				x[n - 1][i] = t ? 'x' : 'y';
				x[n - 1][i + 1] = t ? 'x' : 'y';
				t = !t;
			}
			n--;
		}
		boolean[] possible = new boolean[26];
		for (int i = n - 2; i >= 0; i -= 2) {
			for (int j = m - 2; j >= 0; j -= 2) {
				Arrays.fill(possible, true);
				for (int k = i - 2; k < i + 3; k++) {
					for (int l = j - 2; l < j + 3; l++) {
						if (k >= 0 && k < x.length && l >= 0 && l < x[0].length) {
							if (x[k][l] != 0)
								possible[x[k][l] - 'a'] = false;
						}
					}
				}

				if (c > 0) {
					c--;
					char fill = 'a';
					for (int k = 0; k < possible.length; k++) {
						if (possible[k]) {
							fill = (char) (k + 'a');
							break;
						}
					}
					x[i][j] = x[i][j + 1] = x[i + 1][j] = x[i + 1][j + 1] = fill;
				} else {
					if (b > 1) {
						char fill1 = 0, fill2 = 0;
						for (int k = 0; k < possible.length; k++) {
							if (possible[k]) {
								if (fill1 == 0) {
									fill1 = (char) (k + 'a');
								} else {
									fill2 = (char) (k + 'a');
									break;
								}
							}
						}
						x[i][j] = x[i + 1][j] = fill1;
						x[i][j + 1] = x[i + 1][j + 1] = fill2;
						b -= 2;
					} else {
						if (a > 1) {
							char fill1 = 0, fill2 = 0;
							for (int k = 0; k < possible.length; k++) {
								if (possible[k]) {
									if (fill1 == 0) {
										fill1 = (char) (k + 'a');
									} else {
										fill2 = (char) (k + 'a');
										break;
									}
								}
							}
							x[i][j] = x[i][j + 1] = fill1;
							x[i + 1][j] = x[i + 1][j + 1] = fill2;
							a -= 2;
						} else {
							out.println("IMPOSSIBLE");
							return;
						}
					}
				}
			}
		}
		for (int i = 0; i < x.length; i++) {
			for (int j = 0; j < x[0].length; j++) {
				out.print(x[i][j]);
			}
			out.println();
		}
	}

	public static void main(String[] args) {
		new Thread(new C()).start();
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
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}