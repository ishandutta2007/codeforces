import static java.math.BigInteger.ONE;
import static java.math.BigInteger.ZERO;
import static java.math.BigInteger.valueOf;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {

	static void solve() throws IOException {
		long n = nextLong();
		List<BigInteger> answers = solve(n);
		Collections.sort(answers);
		if (answers.isEmpty()) {
			out.println(-1);
		} else {
			for (BigInteger val : answers) {
				out.println(val);
			}
		}
	}

	private static List<BigInteger> solve(long n) {
		List<BigInteger> list = new ArrayList<>();

		for (int d = 0; (1L << d) - 1 <= n; d++) {
			BigInteger p = ZERO.setBit(d + 1).subtract(valueOf(3));
			BigInteger q = valueOf(-2 * n);
			BigInteger ok = p.multiply(p).subtract(q.shiftLeft(2));
			if (ok.signum() < 0) {
				continue;
			}
			BigInteger sqrt = sqrt(ok);
			if (sqrt == null) {
				continue;
			}
			BigInteger root = sqrt.subtract(p).shiftRight(1);
			if (root.signum() <= 0) {
				continue;
			}
			if (root.and(ONE).signum() == 0) {
				continue;
			}
			
			BigInteger numberOfTeams = root.shiftLeft(d);
			list.add(numberOfTeams);
		}
		return list;
	}

	private static BigInteger sqrt(BigInteger ok) {
		BigInteger left = valueOf(-1), right = ok;
		while (right.subtract(left).compareTo(ONE) > 0) {
			BigInteger mid = right.add(left).shiftRight(1);
			if (mid.multiply(mid).compareTo(ok) < 0) {
				left = mid;
			} else {
				right = mid;
			}
		}
		if (right.multiply(right).compareTo(ok) == 0) {
			return right;
		} else {
			return null;
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
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