import java.io.*;
import java.util.*;

public class B {
	boolean[][][] a;
	int cnt = 0;

	void dfs(int x, int y, int z) {
		if (a[x][y][z])
			return;
		cnt++;
		a[x][y][z] = true;
		for (int xx = -1; xx <= 1; xx++) {
			for (int yy = -1; yy <= 1; yy++) {
				for (int zz = -1; zz <= 1; zz++) {
					if (Math.abs(xx) + Math.abs(yy) + Math.abs(zz) != 1)
						continue;
					int x1 = x + xx, y1 = y + yy, z1 = z + zz;
					if (inBounds(x1, y1, z1))
						dfs(x1, y1, z1);
				}
			}
		}
	}

	boolean inBounds(int i, int j, int k) {
		return i >= 0 && i < a.length && j >= 0 && j < a[0].length && k >= 0
				&& k < a[0][0].length;
	}

	private void solve() throws IOException {
		int k = nextInt(), n = nextInt(), m = nextInt();
		a = new boolean[k][n][m];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				String s = nextToken();
				for (int l = 0; l < m; l++) {
					a[i][j][l] = s.charAt(l) == '#';
				}
			}
		}
		int x = nextInt(), y = nextInt();
		cnt = 0;
		dfs(0, x - 1, y - 1);
		out.println(cnt);
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