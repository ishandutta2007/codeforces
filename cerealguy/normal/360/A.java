import java.io.*;
import java.util.*;

public class A {

	static class Event {
		int type;
		int left, right, value;

		public Event(int type, int left, int right, int value) {
			this.type = type;
			this.left = left;
			this.right = right;
			this.value = value;
		}
	}

	static void solve() throws IOException {
		int n = nextInt();
		int ops = nextInt();
		int[] max = new int[n];
		Arrays.fill(max, Integer.MAX_VALUE);
		int[] add = new int[n];
		Event[] events = new Event[ops];
		for (int operation = 0; operation < ops; operation++) {
			int type = nextInt();
			int left = nextInt() - 1;
			int right = nextInt();
			int value = nextInt();
			events[operation] = new Event(type, left, right, value);
			if (type == 1) {
				for (int i = left; i < right; i++) {
					add[i] += value;
				}
			} else {
				boolean ok = false;
				for (int i = left; i < right; i++) {
					if (max[i] >= value - add[i]) {
						ok = true;
						max[i] = value - add[i];
					}
				}
				if (!ok) {
					out.println("NO");
					return;
				}
			}
		}
		Arrays.fill(add, 0);
		for (Event event : events) {
			int type = event.type;
			int left = event.left;
			int right = event.right;
			int value = event.value;
			if (type == 1) {
				for (int i = left; i < right; i++) {
					add[i] += value;
				}
			} else {
				int whatMax = Integer.MIN_VALUE;
				for (int i = left; i < right; i++) {
					whatMax = Math.max(whatMax, max[i] + add[i]);
				}
				if (whatMax != value) {
					out.println("NO");
					return;
				}
			}
		}

		out.println("YES");
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			if (max[i] == Integer.MAX_VALUE) {
				out.print(1000000000);
			} else {
				out.print(max[i]);
			}
		}
		out.println();

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