import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		int n = nextInt();
		int[] t = new int[n];
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
			c[i] = nextInt();
		}
		int currentTime = 0;
		int queueSize = 0;
		int maxQueueSize = 0;
		for (int event = 0; event < n; event++) {
			int time = t[event];
			int quantity = c[event];
			if (currentTime + queueSize <= time) {
				queueSize = quantity;
			} else {
				queueSize = queueSize + currentTime - time - 1 + quantity;
			}
			maxQueueSize = max(maxQueueSize, queueSize);
			currentTime = time + 1;
		}
		currentTime += queueSize - 1;
		out.println(currentTime + " " + maxQueueSize);
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