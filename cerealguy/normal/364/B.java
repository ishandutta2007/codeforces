import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int n = nextInt(), d = nextInt();
		int[] c = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			c[i] = nextInt();
			sum += c[i];
		}
		boolean[] dp = new boolean[sum + 1];
		dp[0] = true;
		int s = 0;
		for (int add : c) {
			for (int i = s; i >= 0; --i) {
				dp[i + add] |= dp[i];
			}
			s += add;
		}
		int ans = 0;
		int days = 0;
		int last = 1;
		while (ans < sum) {
			int lastCan = -1;
			while (last <= ans + d && last <= sum) {
				if (dp[last]) {
					lastCan = last;
				}
				last++;
			}
			if (lastCan < 0) {
				break;
			}
			ans = lastCan;
			days++;
		}
		out.println(ans + " " + days);
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