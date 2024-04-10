import static java.util.Arrays.copyOfRange;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

	static void solve() throws IOException {
		int n = nextInt();
		int[] input = new int[n];
		for (int i = 0; i < n; i++) {
			input[i] = nextInt();
		}
		sort(input);
		int zero = 0;
		while (zero < n && input[zero] == 0) {
			zero++;
		}
		input = copyOfRange(input, zero, n);
		int ok = solve(input);
		out.println(ok);
	}

	private static int solve(int[] input) {
		int ret = 0;
		for (int i = 0; i < input.length;) {
			int j = i;
			while (j < input.length && input[j] == input[i]) {
				j++;
			}
			if (j - i > 2) {
				return -1;
			}
			if (j - i == 2) {
				++ret;
			}
			i = j;
		}

		return ret;
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