import static java.util.Arrays.copyOfRange;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int k = nextInt();
		char[] c = nextToken().toCharArray();
		String res = get(c, k);
		if (res == null) {
			out.println("-1");
		} else {
			out.println(res);
		}
	}

	static String get(char[] c, int k) {
		if (c.length % k != 0) {
			return null;
		}
		sort(c);
		char[] res = new char[c.length];
		int cnt = 0;
		for (int i = 0; i < c.length / k; i++) {
			for (int j = 0; j < k; j++) {
				res[j * c.length / k + i] = c[cnt++];
			}
		}
		for (int i = 0; i < k; i++) {
			if (!Arrays.equals(
					copyOfRange(res, i * c.length / k, (i + 1) * c.length / k),
					(copyOfRange(res, 0, c.length / k)))) {
				return null;
			}
		}
		return new String(res);
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
		File inputFile = new File("fatrat.in");
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