import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class C {
	static final int sizeX = 100000;
	static final int sizeY = 100;

	private static void solve() throws IOException {
		int h1 = nextInt(), h2 = nextInt();
		int n = nextInt();
		int[] score = new int[n];
		int[] a = new int[n];
		int[] b = new int[n];
		boolean[] top = new boolean[n];
		for (int i = 0; i < n; i++) {
			score[i] = nextInt();
			top[i] = nextToken().startsWith("T");
			a[i] = nextInt();
			b[i] = nextInt();
		}
		int answer1 = maxScore(h1, h2, n, score, top, a, b);
		for (int i = 0; i < n; i++) {
			top[i] = !top[i];
		}
		int answer2 = maxScore(sizeY - h1, sizeY - h2, n, score, top, a, b);
		int answer = max(answer1, answer2);
		out.println(answer);
	}

	private static int maxScore(int h1, int h2, int n, int[] score, boolean[] top, int[] a, int[] b) {
		int best = 0;
		for (int reflections = 0; reflections <= n; reflections++) {
			int dx = sizeX;
			int dy = -h1 - reflections * sizeY;
			if ((reflections & 1) != 0) {
				dy -= h2;
			} else {
				dy -= sizeY - h2;
			}
			dy += sizeY;
			int curScore = shootIt(h1, dx, dy, reflections, score, top, a, b);
			best = max(best, curScore);
		}
		return best;
	}

	private static int shootIt(int h1, int dx, int dy, int reflections, int[] score, boolean[] top,
			int[] a, int[] b) {
		int n = score.length;
		boolean[] weHit = new boolean[n];
		for (int reflection = 0; reflection < reflections; reflection++) {
			boolean expectTop = (reflection & 1) != 0;
			boolean wasHit = false;
			for (int who = 0; who < n; who++) {
				if (top[who] != expectTop) {
					continue;
				}
				int posY = -h1 - reflection * sizeY;
				if (hitsIt(dx, dy, posY, a[who], b[who])) {
					if (weHit[who]) {
						return 0;
					}
					wasHit = true;
					weHit[who] = true;
				}
			}
			if (!wasHit) {
				return 0;
			}
		}
		int answer = 0;
		for (int i = 0; i < n; i++) {
			if (weHit[i]) {
				answer += score[i];
			}
		}
		return answer;
	}

	private static boolean hitsIt(int dx, int dy, int posY, int l, int r) {
		dy = -dy;
		posY = -posY;
		return good(dx, dy, l, posY) && good(r, posY, dx, dy);
	}

	private static boolean good(int dx, int dy, int dx2, int dy2) {
		long vmul = ((long) dx * dy2) - ((long) dx2 * dy);
		return vmul >= 0;
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