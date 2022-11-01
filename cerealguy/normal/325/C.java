import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class C {

	static void solve() throws IOException {
		int numberOfTransformations = nextInt();
		int numberOfMonsters = nextInt();
		@SuppressWarnings("unchecked")
		List<Transformation>[] transformationsIn = new List[numberOfMonsters];
		@SuppressWarnings("unchecked")
		List<Transformation>[] transformationsOut = new List[numberOfMonsters];
		for (int i = 0; i < numberOfMonsters; i++) {
			transformationsOut[i] = new ArrayList<>();
			transformationsIn[i] = new ArrayList<>();
		}
		Transformation[] allTransformations = new Transformation[numberOfTransformations];
		for (int transformationId = 0; transformationId < numberOfTransformations; transformationId++) {
			int monster = nextInt() - 1;
			int cnt = nextInt();
			int[] to = new int[cnt];
			for (int j = 0; j < cnt; j++) {
				to[j] = nextInt() - 1;
			}
			int[] toWithoutMinusOnes = removeNegatives(to);
			Transformation transformation = new Transformation(
					transformationId, monster, toWithoutMinusOnes, cnt
							- toWithoutMinusOnes.length);
			transformationsOut[monster].add(transformation);
			for (int man : toWithoutMinusOnes) {
				transformationsIn[man].add(transformation);
			}
			allTransformations[transformationId] = transformation;
		}
		
		int[] minMoney = new int[numberOfMonsters];
		Arrays.fill(minMoney, Integer.MAX_VALUE);
		
		int[] hasMen = new int[numberOfTransformations];

		PriorityQueue<HeapEntry> heap = new PriorityQueue<>();
		for (int transformationId = 0; transformationId < numberOfTransformations; transformationId++) {
			hasMen[transformationId] = allTransformations[transformationId].transformTo.length;
		}

		for (int monster = 0; monster < numberOfMonsters; monster++) {
			int curMinMoney = Integer.MAX_VALUE;
			for (int it = 0; it < transformationsOut[monster].size(); it++) {
				Transformation t = transformationsOut[monster].get(it);
				if (t.isEmpty()) {
					curMinMoney = min(curMinMoney, t.money);
				}
			}
			if (curMinMoney == Integer.MAX_VALUE) {
				continue;
			}
			curMinMoney = min(curMinMoney, BIG);
			minMoney[monster] = curMinMoney;
			HeapEntry entry = new HeapEntry(monster, curMinMoney);
			heap.add(entry);
		}

		while (!heap.isEmpty()) {
			HeapEntry entry = heap.poll();
			int monster = entry.id;
			if (minMoney[monster] < entry.cost) {
				continue;
			}
			for (int it = 0; it < transformationsIn[monster].size(); it++) {
				Transformation in = transformationsIn[monster].get(it);
				if (--hasMen[in.transformationId] == 0) {
					int moneyCost = in.money;
					if (moneyCost > BIG) {
						moneyCost = BIG;
					}
					for (int i : in.transformTo) {
						moneyCost += minMoney[i];
						if (moneyCost > BIG) {
							moneyCost = BIG;
						}
					}
					if (minMoney[in.transformWho] > moneyCost) {
						HeapEntry ok = new HeapEntry(in.transformWho, moneyCost);
						minMoney[in.transformWho] = moneyCost;
						heap.add(ok);
					}
				}
			}
		}

		boolean[] canEnd = new boolean[numberOfMonsters];
		for (int i = 0; i < numberOfMonsters; i++) {
			canEnd[i] = minMoney[i] != Integer.MAX_VALUE;
		}


		
		Queue<Integer> queue = new ArrayDeque<>();
		boolean[] transformationIsInvalid = new boolean[numberOfTransformations];
		for (int transformationId = 0; transformationId < numberOfTransformations; transformationId++) {
			Transformation t = allTransformations[transformationId];
			for (int man : t.transformTo) {
				transformationIsInvalid[transformationId] |= !canEnd[man];
			}
		}

		for (int i = 0; i < numberOfTransformations; i++) {
			hasMen[i] = allTransformations[i].transformTo.length;
		}
		int[] hasNonEmptyTransformations = new int[numberOfMonsters];
		for (int monster = 0; monster < numberOfMonsters; monster++) {
			for (int i = 0; i < transformationsOut[monster].size(); i++) {
				Transformation t = transformationsOut[monster].get(i);
				if (!transformationIsInvalid[t.transformationId]
						&& !t.isEmpty()) {
					++hasNonEmptyTransformations[monster];
				}
			}
		}

		boolean[] endsInLimitedTimeIfEnds = new boolean[numberOfMonsters];
		int[] maxMoney = new int[numberOfMonsters];

		for (int monster = 0; monster < numberOfMonsters; monster++) {
			if (hasNonEmptyTransformations[monster] != 0) {
				continue;
			}
			if (!canEnd[monster]) {
				continue;
			}
			int curMaxMoney = Integer.MIN_VALUE;

			for (int it = 0; it < transformationsOut[monster].size(); it++) {
				Transformation t = transformationsOut[monster].get(it);
				if (t.isEmpty()) {
					curMaxMoney = max(curMaxMoney, t.money);
				}
			}
			if (curMaxMoney == Integer.MIN_VALUE) {
				continue;
			}
			curMaxMoney = min(curMaxMoney, BIG);
			maxMoney[monster] = curMaxMoney;
			endsInLimitedTimeIfEnds[monster] = true;
			queue.add(monster);
		}

		while (!queue.isEmpty()) {
			int monster = queue.poll();
			for (int it = 0; it < transformationsIn[monster].size(); it++) {
				Transformation in = transformationsIn[monster].get(it);
				--hasMen[in.transformationId];
				if (hasMen[in.transformationId] == 0) {
					--hasNonEmptyTransformations[in.transformWho];

					if (hasNonEmptyTransformations[in.transformWho] == 0) {
						int dude = in.transformWho;
						endsInLimitedTimeIfEnds[dude] = true;
						queue.add(dude);
						maxMoney[dude] = Integer.MIN_VALUE;
						for (int dudeTrasformation = 0; dudeTrasformation < transformationsOut[dude]
								.size(); dudeTrasformation++) {
							Transformation t = transformationsOut[dude]
									.get(dudeTrasformation);
							if (transformationIsInvalid[t.transformationId]) {
								continue;
							}
							int curMaxMoney = t.money;
							if (curMaxMoney > BIG) {
								curMaxMoney = BIG;
							}

							for (int i : t.transformTo) {
								curMaxMoney += maxMoney[i];
								if (curMaxMoney > BIG) {
									curMaxMoney = BIG;
								}
							}

							maxMoney[dude] = max(maxMoney[dude], curMaxMoney);
						}
					}
				}
			}
		}

		for (int monster = 0; monster < numberOfMonsters; monster++) {
			if (!canEnd[monster]) {
				out.println("-1 -1");
				continue;
			}
			if (endsInLimitedTimeIfEnds[monster]) {
				out.println(minMoney[monster] + " " + maxMoney[monster]);
				continue;
			}
			out.println(minMoney[monster] + " -2");
		}

	}

	static class HeapEntry implements Comparable<HeapEntry> {
		int id, cost;

		public HeapEntry(int id, int cost) {
			this.id = id;
			this.cost = cost;
		}

		@Override
		public int compareTo(HeapEntry o) {
			return cost - o.cost;
		}

	}

	static final int BIG = 314000000;

	private static int[] removeNegatives(int[] to) {
		int cnt = 0;
		for (int val : to) {
			if (val >= 0) {
				++cnt;
			}
		}
		int[] ret = new int[cnt];
		cnt = 0;
		for (int val : to) {
			if (val >= 0) {
				ret[cnt++] = val;
			}
		}
		return ret;
	}

	static class Transformation {
		int transformationId;
		int transformWho;
		int[] transformTo;
		int money;

//		int distinct;

		public Transformation(int transformationId, int transformWho,
				int[] transformTo, int money) {
			this.transformationId = transformationId;
			this.transformWho = transformWho;
			this.transformTo = transformTo;
			this.money = money;
//			this.distinct = countDistinct();
		}

//		private int countDistinct() {
//			Arrays.sort(transformTo);
//			int res = 0;
//			int last = -1;
//			for (int i : transformTo) {
//				if (i != last) {
//					++res;
//					last = i;
//				}
//			}
//			return res;
//		}

		boolean isEmpty() {
			return transformTo.length == 0;
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
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