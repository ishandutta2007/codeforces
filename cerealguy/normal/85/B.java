import java.io.*;
import java.util.*;

public class B {

	static class ManEvent implements Comparable<ManEvent> {
		final long startingTime;
		long time;
		int window;

		public ManEvent(long startingTime, long time, int window) {
			this.startingTime = startingTime;
			this.time = time;
			this.window = window;
		}

		@Override
		public int compareTo(ManEvent o) {
			if (time < o.time)
				return -1;
			if (time > o.time)
				return 1;
			return Long.signum(startingTime - o.startingTime);
		}
	}

	private void solve() throws IOException {
		int[] k = new int[3];
		for (int i = 0; i < 3; i++) {
			k[i] = nextInt();
		}
		int[] t = new int[3];
		for (int i = 0; i < 3; i++) {
			t[i] = nextInt();
		}
		int n = nextInt();
		for (int i = 0; i < 3; i++) {
			k[i] = Math.min(k[i], n);
		}
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = nextInt();
		}
		Arrays.sort(c);
		Queue<ManEvent> q = new PriorityQueue<B.ManEvent>();
		for (int i = 0; i < n; i++) {
			q.add(new ManEvent(c[i], c[i], 0));
		}
		@SuppressWarnings("unchecked")
		PriorityQueue<Long> free[] = new PriorityQueue[3];
		for (int i = 0; i < 3; i++) {
			free[i] = new PriorityQueue<Long>();
		}
		long answer = 0;

		while (!q.isEmpty()) {
			ManEvent e = q.poll();
			for (int i = 0; i < 3; i++) {
				while (!free[i].isEmpty() && free[i].peek() < e.time) {
					free[i].poll();
					k[i]++;
				}
			}
			int w = e.window;
			if (k[w] > 0) {
				--k[w];
				e.time += t[w];
			} else {
				long serve = free[w].poll();
				e.time = serve + t[w];
			}
			free[w].add(e.time);
			if (w < 2) {
				e.window = w + 1;
				q.add(e);
			} else {
				answer = Math.max(answer, e.time - e.startingTime);
			}
		}
		out.println(answer);
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