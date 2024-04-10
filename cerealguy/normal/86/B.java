import java.io.*;
import java.util.*;

public class B {

	int n, m;
	int[][] field;

	int[] dx = { 0, 0, 1, -1 };
	int[] dy = { 1, -1, 0, 0 };

	private void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		field = new int[n][m];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < m; j++) {
				if (s.charAt(j) == '#') {
					field[i][j] = -1;
				}
			}
		}
		int[][] p = new int[n][m];
		for (int i = 0; i < n; i++) {
			Arrays.fill(p[i], -1);
		}
		for (int i = 0; i < n; i++) {
			forj: for (int j = 0; j < m; j++) {
				if (field[i][j] != 0)
					continue;
				boolean have = false;
				for (int it = 0; it < 4; it++) {
					int i1 = i + dx[it], j1 = j + dy[it];
					if (!inBounds(i1, j1) || field[i1][j1] == -1)
						continue;
					have = true;
					if (field[i1][j1] == 0) {
						field[i][j] = 1;
						field[i1][j1] = 1;
						p[i1][j1] = toInt(i1, j1);
						p[i][j] = toInt(i1, j1);
						continue forj;
					}
				}
				if (!have) {
					out.println(-1);
					return;
				}
				for (int it = 0; it < 4; it++) {
					int i1 = i + dx[it], j1 = j + dy[it];
					if (!inBounds(i1, j1) || field[i1][j1] == -1)
						continue;
					field[i][j] = 1;
					p[i][j] = p[i1][j1];
					continue forj;
				}
			}
		}
		int[][] color = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] == -1) {
					color[i][j] = -1;
					continue;
				}
				int par = p[i][j];
				int i1 = par / m, j1 = par % m;
				color[i][j] = (i1 * 3 + j1) % 10;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (color[i][j] == -1) {
					out.print('#');
				} else {
					out.print(color[i][j]);
				}
			}
			out.println();
		}
	}

	int toInt(int i, int j) {
		return i * m + j;
	}

	boolean inBounds(int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	public static void main(String[] args) {
		new B().run();
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