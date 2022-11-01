import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int tc = nextInt();
		while (tc-- > 0) {
			long a = nextLong(), b = nextLong();
			out.println(win(a, b) ? "First" : "Second");
		}
	}

	static boolean win(long a, long b) {
		if (a > b) {
			long t = a;
			a = b;
			b = t;
		}
		if (a == 0) {
			return false;
		}
		if (a == 1) {
			return true;
		}
		if (!win(b % a, a)) {
			return true;
		}
		b -= a;
		b /= a;
		if ((a & 1) == 1) {
			return (b & 1) == 1;
		} else {
			b %= a + 1;
			return b == a || (b & 1) != 0;
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