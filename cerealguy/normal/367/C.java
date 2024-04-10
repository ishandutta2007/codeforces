import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] cost = new int[m];
		for (int i = 0; i < m; i++) {
			nextInt();
			cost[i] = nextInt();
		}
		Arrays.sort(cost);

		for (int sereja = m; sereja >= 0; --sereja) {
			long minSize = sereja(sereja) + 1;
			if (minSize <= n) {
				long sum = 0;
				for (int i = 0; i < sereja; i++) {
					sum += cost[m - 1 - i];
				}
				out.println(sum);
				break;
			}
		}
	}

	private static long sereja(long sereja) {
		long pairs = sereja * (sereja - 1) / 2;
		if ((sereja & 1) != 0) {
			return pairs;
		} else {
			return pairs + sereja / 2 - 1;
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
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