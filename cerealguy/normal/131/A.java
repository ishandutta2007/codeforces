import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		String s = nextToken();
		if (isCaps(s)) {
			s = fix(s);
		}
		out.println(s);
	}

	static boolean isCaps(String s) {
		for (int i = 1; i < s.length(); i++) {
			if (!Character.isUpperCase(s.charAt(i))) {
				return false;
			}
		}
		return true;
	}

	static String fix(String s) {
		char[] c = new char[s.length()];
		for (int i = 0; i < c.length; i++) {
			if (Character.isUpperCase(s.charAt(i))) {
				c[i] = Character.toLowerCase(s.charAt(i));
			} else {
				c[i] = Character.toUpperCase(s.charAt(i));
			}
		}
		return new String(c);
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