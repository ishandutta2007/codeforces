import java.io.*;
import java.util.*;

public class B {

	static int n;
	int direction;
	int[] dx = { -1, 1 };

	boolean inBounds(int x) {
		return x >= 0 && x < n;
	}

	private void solve() throws IOException {
		n = nextInt();
		int b = nextInt() - 1, a = nextInt() - 1;
		nextToken();
		direction = "tail".equals(nextToken()) ? 1 : 0;
		String s = nextToken();
		int res = game(s, a, b);
		if (res == -1) {
			out.println("Stowaway");
		} else {
			out.println("Controller " + res);
		}
	}

	int away(int a, int dir, int b) {
		int best = b;
		if (inBounds(b + dx[dir])
				&& Math.abs(b + dx[dir] - a) > Math.abs(a - best)) {
			best = b + dx[dir];
		}
		return best;
	}

	int faraway(int a, int dir, int b) {
		if (a == 0)
			return n - 1;
		if (a == n - 1)
			return 0;
		return dir == 0 ? n - 1 : 0;
	}

	int game(String s, int a, int b) {
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '0') {
				if ((a + dx[direction] == n - 1 || a + dx[direction] == 0)
						&& b == a + dx[direction])
					return i + 1;
				a += dx[direction];
				if (!inBounds(a + dx[direction]))
					direction ^= 1;
				b = away(a, direction, b);
			} else {
				a += dx[direction];
				if (!inBounds(a + dx[direction]))
					direction ^= 1;
				b = faraway(a, direction, b);
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}