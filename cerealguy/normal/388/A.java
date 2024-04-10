import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int n = nextInt();
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
		}
		Arrays.sort(x);
		for (int stacks = 1; stacks <= n; stacks++) {
			if (canPut(x, n, stacks)) {
				out.println(stacks);
				return;
			}
		}
	}

	private static boolean canPut(int[] x, int n, int stacks) {
		for (int i = 0; i * stacks < n; i++) {
			for (int j = i * stacks; j < i * stacks + stacks && j < n; j++) {
				if (x[j] < i) {
					return false;
				}
			}
		}
		return true;
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