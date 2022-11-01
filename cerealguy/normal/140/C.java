import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int n = nextInt();
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		Arrays.sort(r);
		List<Ball> balls = new ArrayList<Ball>();
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (i == n - 1 || r[i] != r[i + 1]) {
				balls.add(new Ball(r[i], i - last));
				last = i;
			}
		}
		PriorityQueue<Ball> queue = new PriorityQueue<Ball>();
		queue.addAll(balls);
		List<Snowman> answer = new ArrayList<Snowman>();
		while (queue.size() >= 3) {
			Ball b1 = queue.poll();
			Ball b2 = queue.poll();
			Ball b3 = queue.poll();
			answer.add(new Snowman(b1.r, b2.r, b3.r));
			for (Ball b : new Ball[] { b1, b2, b3 }) {
				--b.count;
				if (b.count > 0) {
					queue.add(b);
				}
			}
		}
		out.println(answer.size());
		for (Snowman s : answer) {
			out.println(s.r3 + " " + s.r2 + " " + s.r1);
		}
	}

	static class Ball implements Comparable<Ball> {
		int r, count;

		public Ball(int r, int count) {
			this.r = r;
			this.count = count;
		}

		@Override
		public int compareTo(Ball o) {
			return o.count - count;
		}
	}

	static class Snowman {
		final int r1, r2, r3;

		public Snowman(int r1, int r2, int r3) {
			if (r1 > r2) {
				int t = r1;
				r1 = r2;
				r2 = t;
			}
			if (r1 > r3) {
				int t = r1;
				r1 = r3;
				r3 = t;
			}
			if (r2 > r3) {
				int t = r2;
				r2 = r3;
				r3 = t;
			}
			this.r1 = r1;
			this.r2 = r2;
			this.r3 = r3;
		}
	}

	public static void main(String[] args) {
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

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

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

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}