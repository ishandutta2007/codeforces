import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int n = nextInt();
		int[][] x = new int[n][2];
		int[][] y = new int[n][2];
		int minX = Integer.MAX_VALUE;
		int minY = Integer.MAX_VALUE;
		int maxX = Integer.MIN_VALUE;
		int maxY = Integer.MIN_VALUE;
		long area = 0;
		for (int i = 0; i < n; i++) {
			x[i][0] = nextInt();
			y[i][0] = nextInt();
			x[i][1] = nextInt();
			y[i][1] = nextInt();
			for (int xx : x[i]) {
				minX = min(minX, xx);
				maxX = max(maxX, xx);
			}
			for (int yy : y[i]) {
				minY = min(minY, yy);
				maxY = max(maxY, yy);
			}
			area += abs(((long) x[i][1] - x[i][0]) * ((long) y[i][1] - y[i][0]));
		}
		long squareArea = ((long) maxX - minX) * ((long) maxY - minY);
		boolean isSquare = (maxX - minX == maxY - minY) && squareArea == area;
		out.println(isSquare ? "YES" : "NO");
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