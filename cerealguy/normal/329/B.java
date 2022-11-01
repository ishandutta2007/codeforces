import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int r = nextInt(), c = nextInt();
		char[][] grid = new char[r][];
		for (int i = 0; i < r; i++) {
			grid[i] = nextToken().toCharArray();
		}

		int[][] distance = new int[r][c];
		for (int i = 0; i < r; i++) {
			Arrays.fill(distance[i], -1);
		}
		int[] queue = new int[r * c];
		int qh = 0, qt = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == 'E') {
					queue[qt++] = (i << 16) + j;
					distance[i][j] = 0;
				}
			}
		}
		while (qh < qt) {
			int u = queue[qh++];
			int x = u >> 16, y = u & 0xFFFF;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + DX[dir];
				int ny = y + DY[dir];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c
						|| grid[nx][ny] == 'T') {
					continue;
				}
				if (distance[nx][ny] < 0) {
					distance[nx][ny] = distance[x][y] + 1;
					queue[qt++] = (nx << 16) + ny;
				}
			}
		}
		
		int ourDistance = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == 'S') {
					ourDistance = distance[i][j];
				}
			}
		}
		
		int fight = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (distance[i][j] >= 0 && distance[i][j] <= ourDistance) {
					if (grid[i][j] >= '0' && grid[i][j] <= '9') {
						 fight += grid[i][j] - '0';
					}
				}
			}
		}
		
		out.println(fight);
	}

	static int[] DX = { 0, 0, 1, -1 };
	static int[] DY = { 1, -1, 0, 0 };

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