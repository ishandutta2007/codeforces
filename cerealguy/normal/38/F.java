import java.io.*;
import java.util.*;

public class F implements Runnable {

	class GameResult implements Comparable<GameResult> {
		@Override
		public String toString() {
			int a1 = a >= 0 ? a : a - Integer.MIN_VALUE;
			int b1 = b >= 0 ? b : b - Integer.MIN_VALUE;
			return "GameResult [a=" + a1 + ", b=" + b1 + "] "
					+ (a >= 0 ? "1" : "2");
		}

		int a, b;

		public GameResult(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(GameResult o) {
			boolean win = a >= 0;
			boolean owin = o.a >= 0;
			if (win && !owin)
				return 1;
			if (!win && owin)
				return -1;
			if (a > o.a)
				return 1;
			if (a < o.a)
				return -1;
			return o.b - b;
		}

	}

	int n;
	String[] s;

	GameResult[][][] d1;
	GameResult[][][] d0;

	int sumvalues(int word, int l, int r) {
		int res = 0;
		for (int i = l; i < r; i++) {
			res += s[word].charAt(i) - 'a' + 1;
		}
		return res;
	}

	int maxvalue(int word, int l, int r) {
		int res = 0;
		for (int i = l; i < r; i++) {
			res = Math.max(res, s[word].charAt(i) - 'a');
		}
		return res + 1;
	}

	void work(int word, int l, int r) {
		if (d1[word][l][r] != null)
			return;
		GameResult best = new GameResult(Integer.MIN_VALUE, 0);
		if (r < s[word].length()) {
			String s1 = s[word].substring(l, r + 1);
			int sumvalue = sumvalues(word, l, r + 1);
			int maxvalue = maxvalue(word, l, r + 1);
			int num = 0;
			for (String t : s) {
				if (t.indexOf(s1) >= 0)
					num++;
			}
			int score = sumvalue * maxvalue + num;
			GameResult cur = get(word, l, r + 1);
			cur = new GameResult(cur.b + score, cur.a);
			if (best.compareTo(cur) < 0)
				best = cur;
		}
		if (l > 0) {
			String s1 = s[word].substring(l - 1, r);
			int sumvalue = sumvalues(word, l - 1, r);
			int maxvalue = maxvalue(word, l - 1, r);
			int num = 0;
			for (String t : s) {
				if (t.indexOf(s1) >= 0)
					num++;
			}
			int score = sumvalue * maxvalue + num;
			GameResult cur = get(word, l - 1, r);
			cur = new GameResult(cur.b + score, cur.a);
			if (best.compareTo(cur) < 0)
				best = cur;
		}
		d1[word][l][r] = best;
	}

	GameResult get(int word, int l, int r) {
		if (d0[word][l][r] != null)
			return d0[word][l][r];
		GameResult res = new GameResult(Integer.MIN_VALUE, 0);
		String s0 = s[word].substring(l, r);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= s[i].length() - s0.length(); j++) {
				if (s[i].startsWith(s0, j)) {
					work(i, j, j + r - l);
					if (res.compareTo(d1[i][j][j + r - l]) < 0)
						res = d1[i][j][j + r - l];
				}
			}
		}
		return d0[word][l][r] = res;
	}

	private void solve() throws IOException {
		n = nextInt();
		s = new String[n];
		d1 = new GameResult[n][][];
		d0 = new GameResult[n][][];
		for (int i = 0; i < n; i++) {
			s[i] = nextToken();
			int len = s[i].length();
			d1[i] = new GameResult[len + 1][len + 1];
			d0[i] = new GameResult[len + 1][len + 1];
		}
		GameResult best = new GameResult(Integer.MIN_VALUE, 0);
		for (int i = 0; i < n; i++) {
			for (int l = 1; l < s[i].length() - 1; l++) {
				GameResult cur = get(i, l, l);
				if (best.compareTo(cur) < 0)
					best = cur;
			}
		}
		if (best.a > 0) {
			out.println("First");
			out.print(best.a);
			out.print(" ");
			out.println(best.b - Integer.MIN_VALUE);
		} else {
			out.println("Second");
			out.print(best.a - Integer.MIN_VALUE);
			out.print(" ");
			out.println(best.b);
		}
	}

	public static void main(String[] args) {
		new Thread(new F()).start();
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