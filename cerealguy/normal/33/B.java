import java.io.*;
import java.util.*;

public class B implements Runnable {

	int INF = Integer.MAX_VALUE / 2;

	private void solve() throws IOException {
		String a = nextToken(), b = nextToken();
		if (a.length() != b.length()) {
			out.println(-1);
			return;
		}
		int[][] cost = new int[26][26];
		for (int i = 0; i < 26; i++) {
			Arrays.fill(cost[i], INF);
			cost[i][i] = 0;
		}
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			char x = nextToken().charAt(0), y = nextToken().charAt(0);
			int c = nextInt();
			cost[x - 'a'][y - 'a'] = Math.min(cost[x - 'a'][y - 'a'], c);
		}

		for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					cost[i][j] = Math.min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}

		int len = a.length();
		long ans = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < len; i++) {
			int x = a.charAt(i) - 'a', y = b.charAt(i) - 'a';
			int min = INF, minC = -1;
			for (int j = 0; j < 26; j++) {
				if (min > cost[x][j] + cost[y][j]) {
					min = cost[x][j] + cost[y][j];
					minC = j;
				}
			}
			if (min == INF) {
				out.println(-1);
				return;
			}
			ans += min;
			sb.append((char) ('a' + minC));
		}
		out.println(ans);
		out.println(sb.toString());
	}

	public static void main(String[] args) {
		new Thread(new B()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}