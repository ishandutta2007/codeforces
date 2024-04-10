import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int n = nextInt();
		char[][] grid = new char[n][];
		for (int i = 0; i < n; i++) {
			grid[i] = nextToken().toCharArray();
		}

		boolean haveEvilRow = false;
		for (int i = 0; i < n; i++) {
			if (isEvilRow(grid, n, i)) {
				haveEvilRow = true;
			}
		}
		boolean haveEvilCol = false;
		for (int i = 0; i < n; i++) {
			if (isEvilCol(grid, n, i)) {
				haveEvilCol = true;
			}
		}
		if (haveEvilRow && haveEvilCol) {
			out.println(-1);
		} else {
			if (haveEvilRow) {
				for (int col = 0; col < n; col++) {
					for (int row = 0; row < n; row++) {
						if (grid[row][col] != 'E') {
							out.println((row + 1) + " " + (col + 1));
							break;
						}
					}
				}
			} else {
				for (int row = 0; row < n; row++) {
					for (int col = 0; col < n; col++) {
						if (grid[row][col] != 'E') {
							out.println((row + 1) + " " + (col + 1));
							break;
						}
					}
				}
			}
		}
	}

	private static boolean isEvilRow(char[][] grid, int n, int i) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] != 'E') {
				return false;
			}
		}
		return true;
	}

	private static boolean isEvilCol(char[][] grid, int n, int i) {
		for (int j = 0; j < n; j++) {
			if (grid[j][i] != 'E') {
				return false;
			}
		}
		return true;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("a.in");
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