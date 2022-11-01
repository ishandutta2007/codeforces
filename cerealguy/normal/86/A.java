import static java.math.BigInteger.valueOf;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {

	private void solve() throws IOException {
		int l = nextInt(), r = nextInt();
		int n = get(l, r);
		out.println(get2(n));
	}

	void stress() {
		Random rand = new Random();
		while (true) {
			int l = rand.nextInt(1000) + 1;
			int r = rand.nextInt(1000) + 1;
			if (l > r) {
				int t = l;
				l = r;
				r = t;
			}
			if (solve(l, r) != solveStupid(l, r)) {
				System.err.println("WTF");
			}
			System.err.println("OK");
		}
	}

	static int get(int l, int r) {
		if (r == 1000000000)
			return 1000000000;
		String s = Integer.toString(r);
		int len = s.length();
		int number = pow(10, len) - 1;
		int n1 = number / 2;
		int n2 = (number + 1) / 2;
		if (inRange(n1, l, r) || inRange(n2, l, r))
			return n1;
		if (get(l) > get(r))
			return l;
		else
			return r;
	}

	BigInteger get2(int n) {
		String s = Integer.toString(n);
		int len = s.length();
		long number = pow2(10, len) - 1;
		return valueOf(number - n).multiply(valueOf(n));
	}

	static long solve(int l, int r) {
		return get(get(l, r));
	}

	static long solveStupid(int l, int r) {
		long res = Long.MIN_VALUE;
		for (int i = l; i <= r; i++) {
			res = Math.max(res, get(i));
		}
		return res;
	}

	static boolean inRange(int a, int l, int r) {
		return l <= a && a <= r;
	}

	static long get(int n) {
		String s = Integer.toString(n);
		int len = s.length();
		long number = pow2(10, len) - 1;
		return (number - n) * n;
	}

	static long pow2(int a, int pow) {
		long res = 1;
		for (int i = 0; i < pow; i++) {
			res *= a;
		}
		return res;
	}

	static int pow(int a, int pow) {
		int res = 1;
		for (int i = 0; i < pow; i++) {
			res *= a;
		}
		return res;
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