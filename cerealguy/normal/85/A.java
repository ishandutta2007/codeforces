import java.io.*;
import java.util.*;

public class A {

	private void solve() throws IOException {
		int n = nextInt();
		int[][] res = n % 2 == 0 ? solve1(n) : solve2(n);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				out.print((char) (res[i][j] + 'a'));
			}
			out.println();
		}
	}

	private int[][] solve2(int n) {
		int[][] color = new int[4][n];
		for (int i = 0; i < n / 2; i++) {
			color[0][2 * i] = color[0][2 * i + 1] = getColor(0, 2 * i);
			color[1][2 * i] = color[1][2 * i + 1] = getColor(1, 2 * i);
			color[2][2 * i + 1] = color[2][2 * i + 2] = getColor(2, 2 * i + 1);
			color[3][2 * i + 1] = color[3][2 * i + 2] = getColor(3, 2 * i + 1);
		}
		color[2][0] = color[3][0] = getColor(2, 0);
		color[0][n - 1] = color[1][n - 1] = getColor(0, n - 1);
		return color;
	}

	private int[][] solve1(int n) {
		int[][] color = new int[4][n];
		for (int i = 0; i < n / 2; i++) {
			color[0][2 * i] = color[0][2 * i + 1] = getColor(0, 2 * i);
			color[3][2 * i] = color[3][2 * i + 1] = getColor(3, 2 * i);
		}
		color[1][0] = color[2][0] = getColor(1, 0);
		color[1][n - 1] = color[2][n - 1] = getColor(1, n - 1);
		for (int i = 0; i < n / 2 - 1; i++) {
			color[1][2 * i + 1] = color[1][2 * i + 2] = getColor(1, 2 * i + 1);
			color[2][2 * i + 1] = color[2][2 * i + 2] = getColor(2, 2 * i + 2);
		}
		return color;
	}

	static int getColor(int i, int j) {
		return (4 * i + j) % 16;
	}

	public static void main(String[] args) {
		new A().run();
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