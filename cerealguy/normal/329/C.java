import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt(), edgesCount = nextInt();
		if (edgesCount == 0) {
			return;
		}
		@SuppressWarnings("unchecked")
		List<Integer>[] edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>(2);
		}
		for (int i = 0; i < edgesCount; i++) {
			int u = nextInt() - 1, v = nextInt() - 1;
			edges[u].add(v);
			edges[v].add(u);
		}

		if (edgesCount <= n - 2) {
			int start = 0;
			for (int i = 0; i < n; i++) {
				if (edges[i].size() < edges[start].size()) {
					start = i;
				}
			}
			int current = start;
			Queue<Integer> free = new ArrayDeque<>();
			for (int i = 0; i < n; i++) {
				if (i != start) {
					free.add(i);
				}
			}
			for (int i = 0; i < edgesCount - 1; i++) {
				int next = -1;
				while (true) {
					Integer to = free.poll();
					if (!edges[current].contains(to)) {
						next = to;
						break;
					} else {
						free.add(to);
					}
				}
				out.println((current + 1) + " " + (next + 1));
				current = next;
			}
			for (Integer to : free) {
				if (!edges[start].contains(to)) {
					out.println((start + 1) + " " + (to + 1));
					break;
				}
			}
			return;
		}

		if (edgesCount == n) {
			if (n < 5) {
				out.println(-1);
			} else {
				solveForGraphOfCycles(n, edges);
			}
			return;
		}

		// if (edgesCount == n - 1) {
		if (n <= 3) {
			out.println(-1);
			return;
		}
		if (n == 4) {
			for (int u = 0; u < n; u++) {
				if (edges[u].size() == 0) {
					out.println(-1);
					return;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (!edges[i].contains(j)) {
						out.println((i + 1) + " " + (j + 1));
					}
				}
			}
			return;
		}
		for (int u = 0; u < n; u++) {
			if (edges[u].size() == 0) {
				boolean[] was = new boolean[n];
				was[u] = true;
				List<List<Integer>> cycles = getCycles(n, edges, was);
				if (n > 5) {
					output(solveForCycles(cycles));
					return;
				} else {
					List<Integer> list = cycles.get(0);
					out.println((list.get(2) + 1) + " " + (list.get(0) + 1));
					out.println((list.get(0) + 1) + " " + (u + 1));
					out.println((u + 1) + " " + (list.get(1) + 1));
					out.println((list.get(1) + 1) + " " + (list.get(3) + 1));
					return;
				}
			}
		}
		for (int u = 0; u < n; u++) {
			if (edges[u].size() == 1) {
				for (int v = u + 1; v < n; v++) {
					if (edges[v].size() == 1) {
						if (!edges[u].contains(v)) {
							edges[u].add(v);
							edges[v].add(u);
							++edgesCount;
							List<List<Integer>> cycles = getCycles(n, edges,
									new boolean[n]);
							List<Integer> answer = solveForCycles(cycles);
							outputPath(answer);
							return;
						} else {
							if (n == 5) {
								List<Integer> notij = new ArrayList<>();
								for (int k = 0; k < 5; k++) {
									if (k != u && k != v) {
										notij.add(k);
									}
								}
								out.println((notij.get(0) + 1) + " " + (u + 1));
								out.println((u + 1) + " " + (notij.get(1) + 1));
								out.println((notij.get(1) + 1) + " " + (v + 1));
								out.println((v + 1) + " " + (notij.get(2) + 1));
								return;
							} else {
								boolean[] was = new boolean[n];
								was[u] = was[v] = true;
								List<List<Integer>> cycles = getCycles(n,
										edges, was);
								if (n == 6) {
									List<Integer> list = cycles.get(0);
									out.println((list.get(2) + 1) + " " + (list.get(0) + 1));
									out.println((list.get(0) + 1) + " " + (u + 1));
									out.println((u + 1) + " " + (list.get(1) + 1));
									out.println((list.get(1) + 1) + " " + (list.get(3) + 1));
									out.println((list.get(3)+1)+" "+(v+1));
								} else {
									List<Integer> answer = solveForCycles(cycles);
									answer.add(u);
									output(answer);
								}
								return;
							}
						}
					}
				}
			}
			// }
		}

	}

	private static void solveForGraphOfCycles(int n, List<Integer>[] edges) {
		boolean[] was = new boolean[n];
		List<List<Integer>> cycles = getCycles(n, edges, was);
		List<Integer> answer = solveForCycles(cycles);
		output(answer);
	}

	private static List<List<Integer>> getCycles(int n, List<Integer>[] edges,
			boolean[] was) {
		List<List<Integer>> cycles = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (was[i]) {
				continue;
			}
			List<Integer> curCycle = new ArrayList<>();
			curCycle.add(i);
			was[i] = true;
			int prev = i;
			int cur = edges[i].get(0);
			while (!was[cur]) {
				curCycle.add(cur);
				was[cur] = true;
				int next = edges[cur].get(0) ^ edges[cur].get(1) ^ prev;
				prev = cur;
				cur = next;
			}
			cycles.add(curCycle);
		}
		return cycles;
	}

	private static List<Integer> solveForCycles(List<List<Integer>> cycles) {
		int maxCycle = 0;
		for (int i = 0; i < cycles.size(); i++) {
			if (cycles.get(i).size() > cycles.get(maxCycle).size()) {
				maxCycle = i;
			}
		}
		List<Integer> what = cycles.remove(maxCycle);
		if (what.size() >= 5) {
			LinkedList<Integer> answer = new LinkedList<Integer>(
					reorderCycle(what));
			for (List<Integer> list : cycles) {
				insertListToAnswer(answer, list);
			}
			return (answer);
		} else {
			List<Integer> list1 = what;
			List<Integer> list2 = cycles.remove(cycles.size() - 1);
			LinkedList<Integer> answer = new LinkedList<>(uniteTwoSmall(list1,
					list2));
			for (List<Integer> list : cycles) {
				insertListToAnswer(answer, list);
			}
			return (answer);
		}
	}

	private static List<Integer> uniteTwoSmall(List<Integer> list1,
			List<Integer> list2) {
		List<Integer> result = new ArrayList<>();
		if (list1.size() == list2.size()) {
			for (int i = 0; i < list1.size(); i++) {
				result.add(list1.get(i));
				result.add(list2.get(i));
			}
		} else {
			if (list1.size() > list2.size()) {
				List<Integer> t = list1;
				list1 = list2;
				list2 = t;
			}
			if (list1.size() != 3 || list2.size() != 4) {
				throw new AssertionError();
			}
			result.add(list2.get(0));
			result.add(list1.get(0));
			result.add(list2.get(1));
			result.add(list1.get(1));
			result.add(list2.get(3));
			result.add(list1.get(2));
			result.add(list2.get(2));
		}
		return result;
	}

	private static void output(List<Integer> cycle) {
		Iterator<Integer> it = cycle.iterator();
		int first = it.next();
		int current = first;
		while (it.hasNext()) {
			int next = it.next();
			out.println((current + 1) + " " + (next + 1));
			current = next;
		}
		out.println((current + 1) + " " + (first + 1));
	}

	private static void outputPath(List<Integer> path) {
		Iterator<Integer> it = path.iterator();
		int first = it.next();
		int current = first;
		while (it.hasNext()) {
			int next = it.next();
			out.println((current + 1) + " " + (next + 1));
			current = next;
		}
	}

	private static void insertListToAnswer(LinkedList<Integer> answer,
			List<Integer> list) {
		ListIterator<Integer> it = answer.listIterator();
		for (Integer value : list) {
			it.add(value);
			it.next();
		}
	}

	private static List<Integer> reorderCycle(List<Integer> what) {
		if (what.size() == 6) {
			List<Integer> result = new ArrayList<>();
			result.add(what.get(0));
			result.add(what.get(3));
			result.add(what.get(1));
			result.add(what.get(5));
			result.add(what.get(2));
			result.add(what.get(4));
			return result;
		} else {
			int okStep = -1;
			for (int step = 2; step < what.size() - 1; step++) {
				if (gcd(what.size(), step) == 1) {
					okStep = step;
					break;
				}
			}
			if (okStep < 0) {
				throw new AssertionError();
			}
			List<Integer> result = new ArrayList<>();
			result.add(what.get(0));
			int pos = okStep;
			while (pos != 0) {
				result.add(what.get(pos));
				pos += okStep;
				if (pos >= what.size()) {
					pos -= what.size();
				}
			}
			return result;
		}
	}

	static int gcd(int a, int b) {
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			} else {
				b %= a;
			}
		}
		return a | b;
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