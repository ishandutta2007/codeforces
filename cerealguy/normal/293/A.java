import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int n = nextInt();
		String s1 = nextToken();
		String s2 = nextToken();
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (s1.charAt(i) == '0' && s2.charAt(i) == '1') {
				a++;
			}
			if (s1.charAt(i) == '1' && s2.charAt(i) == '0') {
				b++;
			}
			if (s1.charAt(i) == '1' && s2.charAt(i) == '1') {
				c++;
			}
		}
		b += c & 1;
		if (a > b + 1) {
			out.println("Second");
		} else {
			if (a < b) {
				out.println("First");
			} else {
				out.println("Draw");
			}
		}
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