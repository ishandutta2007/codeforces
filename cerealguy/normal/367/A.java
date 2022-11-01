import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		String s = nextToken();
		int[] cntX = count(s, 'x');
		int[] cntY = count(s, 'y');
		int[] cntZ = count(s, 'z');
		int queries = nextInt();
		for (int i = 0; i < queries; i++) {
			int left = nextInt() - 1;
			int right = nextInt();
			if (right - left < 3) {
				out.println("YES");
				continue;
			}
			int x = cntX[right] - cntX[left];
			int y = cntY[right] - cntY[left];
			int z = cntZ[right] - cntZ[left];
			boolean ok = Math.abs(x - y) <= 1 && Math.abs(y - z) <= 1
					&& Math.abs(z - x) <= 1;
			out.println(ok ? "YES" : "NO");
		}
	}

	private static int[] count(String s, char c) {
		int n = s.length();
		int[] res = new int[n + 1];
		for (int i = 0; i < n; i++) {
			res[i + 1] = res[i] + ((s.charAt(i) == c) ? 1 : 0);
		}
		return res;
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