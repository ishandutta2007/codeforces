import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int a = nextInt(), b = nextInt();
		int m = nextInt();
		int r0 = nextInt();
		Map<Long, Integer> map = new HashMap<Long, Integer>();
		int r1 = (a * r0 + b) % m;
		map.put(toLong(r0, r1), 0);
		for (int it = 1;; it++) {
			int r2 = (a * r1 + b) % m;
			r0 = r1;
			r1 = r2;
			Long pair = toLong(r0, r1);
			Integer index = map.get(pair);
			if (index != null) {
				out.println(it - index);
				break;
			}
			map.put(pair, it);
		}
	}

	static long toLong(int a, int b) {
		return a * 1000000009L + b * 23917L;
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