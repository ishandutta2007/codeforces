import static java.math.BigInteger.ONE;
import static java.math.BigInteger.valueOf;
import static java.util.Arrays.fill;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {

	static void solve() throws IOException {
		String s = nextToken();
		int questions = 0;
		Set<Character> haveLetters = new HashSet<>();
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if ('0' <= c && c <= '9') {
				continue;
			}
			if (c == '?') {
				++questions;
			} else {
				haveLetters.add(c);
			}
		}
		int letters = haveLetters.size();
		if (letters > 10) {
			out.println(0);
			return;
		}
		BigInteger answer = ONE;
		char first = s.charAt(0);
		if (first == '?') {
			answer = valueOf(9);
			--questions;
		} else {
			if ('0' <= first && first <= '9') {

			} else {
				answer = valueOf(9);
				for (int i = 1; i < letters; i++) {
					answer = answer.multiply(valueOf(10 - i));
				}
				letters = 0;
			}
		}
		for (int i = 0; i < letters; i++) {
			answer = answer.multiply(valueOf(10-i));
		}
		out.print(answer);
		char[] buf = new char[questions];
		fill(buf, '0');
		out.println(buf);
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