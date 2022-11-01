import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int n = nextInt();
		int mustWin = nextInt();
		int haveFree = nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt();
		}
		int[] bags = new int[n];
		for (int i = 0; i < n; i++) {
			bags[i] = nextInt();
		}
		double[][] prob = new double[n + 1][n + 1];
		haveFree = min(haveFree, n);
		prob[0][haveFree] = 1;
		int maxWin = 0;
		for (int it = 0; it < n; it++) {
			if (bags[it] < 0 || p[it] == 0) {
				continue;
			}
			double pWin = p[it] * 0.01;
			for (int win = maxWin; win >= 0; --win) {
				for (int haveSpace = n; haveSpace >= 0; --haveSpace) {
					int newSpace = min(n, haveSpace + bags[it]);
					prob[win + 1][newSpace] += prob[win][haveSpace] * pWin;
					prob[win][haveSpace] *= (1 - pWin);
				}
			}
			++maxWin;
		}
		for (int it = 0; it < n; it++) {
			if (bags[it] >= 0 || p[it] == 0) {
				continue;
			}
			double pWin = p[it] * 0.01;
			for (int win = maxWin; win >= 0; --win) {
				for (int haveSpace = n; haveSpace >= 0; --haveSpace) {
					int newSpace = haveSpace - 1;
					if (newSpace >= 0) {
						prob[win + 1][newSpace] += prob[win][haveSpace] * pWin;
					}
					prob[win][haveSpace] *= (1 - pWin);
				}
			}
			++maxWin;
		}
		double ansP = 0;
		for (int win = mustWin; win <= maxWin; win++) {
			for (int space = 0; space <= n; space++) {
				ansP += prob[win][space];
			}
		}
		out.println(ansP);

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