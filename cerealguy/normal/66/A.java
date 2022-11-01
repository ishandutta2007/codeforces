import static java.math.BigInteger.valueOf;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {

	private void solve() throws IOException {
		BigInteger n = new BigInteger(nextToken());
		if (isByte(n)) {
			out.println("byte");
			return;
		}
		if (isShort(n)) {
			out.println("short");
			return;
		}
		if (isInt(n)) {
			out.println("int");
			return;
		}
		if (isLong(n)) {
			out.println("long");
			return;
		}
		out.println("BigInteger");
	}

	boolean isByte(BigInteger n) {
		return n.compareTo(valueOf(Byte.MIN_VALUE)) >= 0
				&& n.compareTo(valueOf(Byte.MAX_VALUE)) <= 0;
	}

	boolean isShort(BigInteger n) {
		return n.compareTo(valueOf(Short.MIN_VALUE)) >= 0
				&& n.compareTo(valueOf(Short.MAX_VALUE)) <= 0;
	}

	boolean isInt(BigInteger n) {
		return n.compareTo(valueOf(Integer.MIN_VALUE)) >= 0
				&& n.compareTo(valueOf(Integer.MAX_VALUE)) <= 0;
	}

	boolean isLong(BigInteger n) {
		return n.compareTo(valueOf(Long.MIN_VALUE)) >= 0
				&& n.compareTo(valueOf(Long.MAX_VALUE)) <= 0;
	}

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
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