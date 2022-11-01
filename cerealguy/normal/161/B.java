import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class B {

	private static void solve() throws IOException {
		int n = nextInt(), k = nextInt();
		List<Pair> type1 = new ArrayList<Pair>();
		List<Pair> type2 = new ArrayList<Pair>();
		for (int i = 0; i < n; i++) {
			int cost = nextInt(), type = nextInt();
			Pair ok = new Pair(cost, i + 1);
			(type == 1 ? type1 : type2).add(ok);
		}
		Collections.sort(type1);
		Collections.sort(type2);
		if (type1.size() > k) {
			List<Pair> subList = type1.subList(0, type1.size() - k);
			type2.addAll(subList);
			subList.clear();
		}
		List<List<Pair>> answer = new ArrayList<List<Pair>>();
		long ansCost = 0;
		while (!type1.isEmpty()) {
			Pair ok = type1.get(type1.size() - 1);
			type1.remove(type1.size() - 1);
			List<Pair> curList = new ArrayList<Pair>();
			curList.add(ok);

			if (type1.isEmpty() && answer.size() == k - 1) {
				curList.addAll(type2);
				type2.clear();
			}

			int low = Integer.MAX_VALUE;
			for (Pair p : curList) {
				ansCost += 2 * p.first;
				low = min(low, p.first);
			}
			ansCost -= low;
			answer.add(curList);
		}
		if (!type2.isEmpty()) {
			for (Pair p : type2) {
				ansCost += 2 * p.first;
			}
			while (answer.size() < k - 1) {
				List<Pair> list = new ArrayList<Pair>();
				list.add(type2.get(type2.size() - 1));
				type2.remove(type2.size() - 1);
				answer.add(list);
			}
			answer.add(type2);
		}
		out.println(toString(ansCost));
		for (List<Pair> list : answer) {
			out.print(list.size());
			for (Pair p : list) {
				out.print(" " + p.second);
			}
			out.println();
		}
	}

	static String toString(long val) {
		return (val / 2) + "." + (val % 2 * 5);
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