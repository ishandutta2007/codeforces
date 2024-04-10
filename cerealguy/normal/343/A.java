import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		long a = nextLong(), b = nextLong();
		long answer = get(a, b);
		out.println(answer);
	}

	private static long get(long p, long q) {
		if (p == 0) {
			return 0;
		}
		if (q == 1) {
			return p;
		}
		if (p == 1) {
			return q;
		}
		if (p >= q) {
			return p / q + get(p % q, q);
		}
		return q / p + get(p, q % p);
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