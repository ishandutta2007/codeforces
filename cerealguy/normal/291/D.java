import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		for (int it = 0; it < k; it++) {
			int[] c = new int[n];
			for (int i = 1; i < n; i++) {
				if (((i - 1) & (1 << it)) != 0) {
					c[i] = 1 << it;
				}
			}
			for (int i = n - 1; i >= 0; --i) {
				out.print(n - c[i]);
				if (i > 0) {
					out.print(' ');
				}
			}
			out.println();
		}
	}
	
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("d.in");
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