import java.io.*;
import java.util.*;

public class G {

	private static void solve() throws IOException {
		int cnt = 305;
		int n = cnt + 2;
		out.println(n);
		int r0 = 1000000;
		out.println(0 + " " + r0);
		int xCur = (int) ((Math.sqrt(4L * r0 * cnt))) + 3;
		out.println(xCur + " " + cnt);
		for (int i = 2; i < n - 1; i++) {
			int r = cnt - i + 1;
			int rPrev = r + 1;
			int distance = 2 * rPrev;
			xCur += distance;
			out.println(xCur + " " + r);
		}
		out.println(r0 + " " + r0);
	}

	public static void main(String[] args) {
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

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

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

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}