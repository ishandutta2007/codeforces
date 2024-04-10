import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int n = nextInt(), h = nextInt();
		Element[] a = new Element[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Element(i, nextInt());
		}
		Answer answer = null;
		answer = best(answer, solve1(a, h));
		answer = best(answer, solve2(a, h));
		out.println(answer.goodness);
		for (int i = 0; i < n; i++) {
			out.print(answer.whatSequence[i] + " ");
		}
		out.println();
	}

	static Answer solve1(Element[] a, int h) {
		sort(a);
		int n = a.length;
		int[] what = new int[n];
		fill(what, 1);
		return new Answer(what, a[n - 1].value + a[n - 2].value - a[0].value - a[1].value);
	}

	static Answer solve2(Element[] a, int h) {
		if (a.length < 3) {
			return null;
		}
		sort(a);
		int n = a.length;
		int[] what = new int[n];
		fill(what, 1);
		what[a[0].index] = 2;

		int max1 = max(a[0].value + a[n - 1].value + h, a[n - 1].value + a[n - 2].value);

		int min1 = min(a[1].value + a[2].value, a[0].value + a[1].value + h);

		return new Answer(what, max1 - min1);
	}

	static Answer best(Answer a, Answer b) {
		if (a == null) {
			return b;
		}
		if (b == null) {
			return a;
		}
		return a.goodness > b.goodness ? b : a;
	}

	static class Answer {
		int[] whatSequence;
		int goodness;

		private Answer(int[] whatSequence, int goodness) {
			this.whatSequence = whatSequence;
			this.goodness = goodness;
		}
	}

	static class Element implements Comparable<Element> {
		final int index, value;

		private Element(int index, int value) {
			this.index = index;
			this.value = value;
		}

		@Override
		public int compareTo(Element o) {
			return value - o.value;
		}
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