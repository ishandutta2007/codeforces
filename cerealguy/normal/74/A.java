import java.io.*;
import java.util.*;

public class A {

	private void solve() throws IOException {
		int n = nextInt();
		String[] names = new String[n];
		int[] points = new int[n];
		for (int i = 0; i < n; i++) {
			names[i] = nextToken();
			int plus = nextInt();
			int minus = nextInt();
			for (int j = 0; j < 5; j++) {
				points[i] += nextInt();
			}
			points[i] += 100 * plus - 50 * minus;
		}
		int best = 0;
		for (int i = 0; i < n; i++) {
			if (points[i] > points[best]) {
				best = i;
			}
		}
		out.println(names[best]);
	}

	public static void main(String[] args) {
		new A().run();
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