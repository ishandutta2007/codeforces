import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int goalX = nextInt(), goalY = nextInt();
		String s = nextToken();
		boolean robot = solve(goalX, goalY, s);
		out.println(robot ? "Yes" : "No");
	}

	private static boolean solve(int goalX, int goalY, String s) {
		int x = 0, y = 0;
		int bigDx = 0, bigDy = 0;
		for (int it = 0; it < s.length(); it++) {
			int dir = DIRS.indexOf(s.charAt(it));
			bigDx += DX[dir];
			bigDy += DY[dir];
		}
		for (int it = 0; it < s.length(); it++) {
			int wantDx = goalX - x;
			int wantDy = goalY - y;
			if (possible(wantDx, wantDy, bigDx, bigDy)) {
				return true;
			}
			int dir = DIRS.indexOf(s.charAt(it));
			x += DX[dir];
			y += DY[dir];
		}

		return false;
	}

	private static boolean possible(int wantDx, int wantDy, int bigDx, int bigDy) {
		if (bigDx == 0 && bigDy == 0) {
			return wantDx == 0 && wantDy == 0;
		}
		long smul = (long) wantDx * (long) bigDx + (long) wantDy * (long) bigDy;
		long vmul = (long) wantDx * (long) bigDy - (long) wantDy * (long) bigDx;
		if (!(vmul == 0 && smul >= 0)) {
			return false;
		}
		if (bigDx != 0 && wantDx % bigDx != 0) {
			return false;
		}
		if (bigDy != 0 && wantDy % bigDy != 0) {
			return false;
		}
		return true;
	}

	static final int[] DX = { 0, 0, 1, -1 };
	static final int[] DY = { 1, -1, 0, 0 };
	static final String DIRS = "UDRL";

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