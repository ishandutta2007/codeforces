import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		String s = nextToken();
		Deque<Integer> deque = new ArrayDeque<>();
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s.charAt(i) == 'l') {
				deque.addLast(i);
			} else {
				deque.addFirst(i);
			}
		}
		for (int i : deque) {
			out.println(i + 1);
		}
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		if (new File("a.in").exists()) {
			br = new BufferedReader(new FileReader("a.in"));
		} else {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		out = new PrintWriter(System.out);
		solve();
		out.close();
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