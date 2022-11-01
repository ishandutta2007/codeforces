import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		long p = nextLong(), d = nextLong();
		out.println(get(p, d));
	}

	static long get(long p, long d) {
		p++;
		long ans = p;
		for (long ten = 1; p % ten <= d; ten = ten < 2e18 ? ten * 10
				: Long.MAX_VALUE) {
			ans = p - p % ten;
		}
		return ans - 1;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
	}

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		File inputFile = new File("fn.in");
		if (inputFile.canRead()) {
			input = new FileInputStream(inputFile);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}
}