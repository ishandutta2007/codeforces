import static java.lang.Math.max;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int n = nextInt();
		int us = nextInt() - 1;
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		int[] dude = new int[n];
		int[] dist = new int[n];
		fill(dist, -1);
		for (int i = 0; i < n; i++) {
			calcDist(dist, dude, p, i);
		}
		int[] maxDist = new int[n];
		fill(maxDist, -1);	
		for (int i = 0; i < n; i++) {
			int d = dude[i];
			maxDist[d] = max(maxDist[d], dist[i]);
		}
		
		boolean[] possible = new boolean[n];
		possible[dist[us]] = true;
		for (int ti = 0; ti < n; ti++) {
			if (maxDist[ti] < 0) {
				continue;
			}
			if (ti == dude[us]) {
				continue;
			}
			int size = maxDist[ti] + 1;
			for (int i= n - size - 1; i >= 0; --i) {
				if (possible[i]) {
					possible[i + size] = true;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (possible[i]) {
				out.println(i+1);
			}
		}
		
	}

	private static void calcDist(int[] dist, int[] dude, int[] p, int i) {
		if (dist[i] >= 0) {
			return;
		}
		if(p[i] < 0) {
			dist[i] = 0;
			dude[i] = i;
			return;
		}
		calcDist(dist, dude, p, p[i]);
		dist[i] = dist[p[i]] + 1;
		dude[i] = dude[p[i]];
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