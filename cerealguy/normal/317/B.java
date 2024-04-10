import static java.lang.Math.abs;
import static java.lang.Math.max;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static final int MAXN = 100;

	static void solve() throws IOException {
		int ants = nextInt();
//		 long time = System.currentTimeMillis();

		int[][] count = new int[MAXN * 2][MAXN * 2];
		int maxX = 0;
		count[MAXN][MAXN] = ants;
		while (maxX >= 0) {
			int newMaxX = -1;
			for (int i = MAXN - maxX; i <= MAXN + maxX; i++) {
				for (int j = MAXN - maxX; j <= MAXN + maxX; j++) {
					if (count[i][j] < 4) {
						continue;
					}
					int ok = count[i][j];
					for (int dir = 0; dir < 4; dir++) {
						int ni = i + dx[dir];
						int nj = j + dy[dir];
						count[ni][nj] += ok >> 2;
						newMaxX = max(newMaxX, abs(MAXN - ni));
						newMaxX = max(newMaxX, abs(MAXN - nj));
					}
					count[i][j] &= 3;
				}
			}
			maxX = newMaxX;
		}
		int sum = 0;
		for (int i = 0; i < MAXN * 2; i++) {
			for (int j = 0; j < MAXN * 2; j++) {
				if (count[i][j] >= 4) {
					throw new AssertionError();
				}
				sum += count[i][j];
			}
		}
		if (sum != ants) {
			throw new AssertionError();
		}
//		 System.err.println(System.currentTimeMillis() - time);
		int queries = nextInt();
		for (int i = 0; i < queries; i++) {
			int x = nextInt(), y = nextInt();
			int answer;
			if (abs(x) >= MAXN || abs(y) >= MAXN) {
				answer = 0;
			} else {
				answer = count[x + MAXN][y + MAXN];
			}
			out.println(answer);
		}

	}

	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
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