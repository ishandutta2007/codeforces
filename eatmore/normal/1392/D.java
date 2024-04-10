import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static int v(boolean b) {
		return b ? 1 : 0;
	}

	static boolean v(int i) {
		return i != 0;
	}

	static void solve() throws Exception {
		int tests = scanInt();
		for (int test = 0; test < tests; test++) {
			int n = scanInt();
			String s = scanString();
			boolean d[] = new boolean[n];
			for (int i = 0; i < n; i++) {
				d[i] = s.charAt(i) == 'R';
			}
			int ans = n;
			int dyn[] = new int[4], ndyn[] = new int[4];
			for (int ss = 0; ss < 4; ss++) {
				fill(dyn, Integer.MAX_VALUE);
				dyn[ss] = v(v(ss & 1) ^ d[0]) + v(v(ss & 2) ^ d[1]);
				for (int i = 2; i < n; i++) {
					for (int ns = 0; ns < 4; ns++) {
						int v = Integer.MAX_VALUE;
						for (int b = 0; b < 2; b++) {
							int sss = (ns << 1) + b;
							if (sss == 0 || sss == 7) {
								continue;
							}
							int pv = dyn[sss & 3];
							if (pv != Integer.MAX_VALUE) {
								v = min(v, pv + v(v(ns & 2) ^ d[i]));
							}
						}
						ndyn[ns] = v;
					}
					int t[] = dyn;
					dyn = ndyn;
					ndyn = t;
				}
				for (int ls = 0; ls < 4; ls++) {
					int ssss = ls + (ss << 2);
					if ((ssss & 7) == 0 || (ssss & 7) == 7 || (ssss >> 1) == 0 || (ssss >> 1) == 7) {
						continue;
					}
					ans = min(ans, dyn[ls]);
				}
			}
			out.println(ans);
		}
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