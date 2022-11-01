import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int k = nextInt();
		int n = 1001;
		boolean[][] graph = new boolean[n][n];

		int bitLength = 32 - Integer.numberOfLeadingZeros(k);
		for (int i = 0; i < bitLength - 1; i++) {
			int x1 = 2 + 3 * i;
			int x2 = 2 + 3 * i + 1;
			int x3 = 2 + 3 * i + 2;
			int x4 = 2 + 3 * i + 3;
			graph[x1][x2] = graph[x2][x1] = true;
			graph[x1][x3] = graph[x3][x1] = true;

			graph[x4][x2] = graph[x2][x4] = true;
			graph[x4][x3] = graph[x3][x4] = true;
		}

		int current = 2 + 3 * (bitLength - 1) + 1;
		for (int twoPow = 0; twoPow < bitLength; twoPow++) {
			if ((k & (1 << twoPow)) == 0) {
				continue;
			}
			int last = 1;
			for (int i = 0; i < 2 * (bitLength - 1 - twoPow); i++) {
				graph[last][current] = graph[current][last] = true;
				last = current;
				++current;
			}
			int connect = 2 + 3 * twoPow;
			graph[last][connect] = graph[connect][last] = true;
		}

		out.println(current - 1);
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i < current; i++) {
			sb.setLength(0);
			for (int j = 1; j < current; j++) {
				sb.append(graph[i][j] ? 'Y' : 'N');
			}
			out.println(sb.toString());
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
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