import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class A {

	private static void solve() throws IOException {
		int fighters = nextInt(), suits = nextInt();
		int x = nextInt(), y = nextInt();
		Pair[] a = new Pair[fighters];
		for (int i = 0; i < fighters; i++) {
			a[i] = new Pair(nextInt(), i);
		}
		Pair[] b = new Pair[suits];
		for (int i = 0; i < suits; i++) {
			b[i] = new Pair(nextInt(), i);
		}
		sort(a);
		sort(b);
		int curFighter = 0;
		List<Pair> answer = new ArrayList<Pair>();
		for (int suit = 0; suit < suits; suit++) {
			while (curFighter < fighters && a[curFighter].first < b[suit].first - y) {
				curFighter++;
			}
			if (curFighter == fighters) {
				break;
			}
			if (a[curFighter].first <= b[suit].first + x) {
				answer.add(new Pair(a[curFighter].second, b[suit].second));
				curFighter++;
			}
		}
		out.println(answer.size());
		for (int i = 0; i < answer.size(); i++) {
			out.println((answer.get(i).first + 1) + " " + (answer.get(i).second + 1));
		}
	}

	static class Pair implements Comparable<Pair> {
		int first, second;

		private Pair(int a, int id) {
			this.first = a;
			this.second = id;
		}

		@Override
		public int compareTo(Pair o) {
			return first - o.first;
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