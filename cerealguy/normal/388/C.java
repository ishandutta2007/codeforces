import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt();
		int[][] stacks = new int[n][];
		List<Integer> middles = new ArrayList<>();
		int firstMan = 0;
		int secondMan = 0;
		for (int i = 0; i < n; i++) {
			stacks[i] = new int[nextInt()];
			int len = stacks[i].length;
			for (int j = 0; j < len; j++) {
				stacks[i][j] = nextInt();
			}
			if (len % 2 != 0) {
				middles.add(stacks[i][len / 2]);
			}
			for (int j = 0; j < len / 2; j++) {
				firstMan += stacks[i][j];
				secondMan += stacks[i][len - 1 - j];
			}
		}
		Collections.sort(middles);
		Collections.reverse(middles);
		for (int i = 0; i < middles.size(); i++) {
			if ((i & 1) == 0) {
				firstMan += middles.get(i);
			} else {
				secondMan += middles.get(i);
			}
		}
		out.println(firstMan+" "+secondMan);
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