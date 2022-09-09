import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.StringTokenizer;

public class G {

	static void solve() throws Exception {
		BigInteger n = new BigInteger(scanString());
		List<BigInteger> factors = new ArrayList<>();
		factors.add(n);
		int nComposites = 1;
		Random rng = new Random();
		rng.setSeed(rng.nextLong() ^ rng.hashCode());
		do {
			BigInteger test = new BigInteger(n.bitLength() + 1, rng);
			BigInteger v = test.gcd(n);
			if (v.equals(BigInteger.ONE)) {
				out.println("sqrt " + test.multiply(test).mod(n));
				out.flush();
				BigInteger res = new BigInteger(scanString());
				v = test.subtract(res).gcd(n);
			}
			if (!v.equals(BigInteger.ONE) && !v.equals(n)) {
				List<BigInteger> newFactors = new ArrayList<>();
				int newNComposites = 0;
				for (BigInteger f: factors) {
					BigInteger g = f.gcd(v);
					if (g.equals(BigInteger.ONE) || g.equals(f)) {
						newFactors.add(f);
						if (!f.isProbablePrime(100)) {
							++newNComposites;
						}
					} else {
						newFactors.add(g);
						if (!g.isProbablePrime(100)) {
							++newNComposites;
						}
						g = f.divide(g);
						newFactors.add(g);
						if (!g.isProbablePrime(100)) {
							++newNComposites;
						}
					}
				}
				factors = newFactors;
				nComposites = newNComposites;
			}
		} while (nComposites != 0);
		out.print("! " + factors.size());
		for (BigInteger f: factors) {
			out.print(" " + f);
		}
		out.println();
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}