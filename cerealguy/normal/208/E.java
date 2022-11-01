import static java.lang.System.arraycopy;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class E {

	@SuppressWarnings("unchecked")
	private static void solve() throws IOException {
		int n = nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		int h = 1;
		while (1 << h < n) {
			h++;
		}
		int[][] up = new int[h][n];
		arraycopy(p, 0, up[0], 0, n);
		for (int it = 0; it < h - 1; it++) {
			int[] cur = up[it];
			int[] next = up[it + 1];
			for (int i = 0; i < n; i++) {
				if (cur[i] < 0) {
					next[i] = -1;
				} else {
					next[i] = cur[cur[i]];
				}
			}
		}
		int q = nextInt();
		int[] inputV = new int[q];
		int[] inputDist = new int[q];
		for (int i = 0; i < q; i++) {
			inputV[i] = nextInt() - 1;
			inputDist[i] = nextInt();
		}
		int[] queryV = new int[q];
		for (int i = 0; i < q; i++) {
			queryV[i] = go(up, inputV[i], inputDist[i] - 1);
		}

		fill(up, null);
		up = null;

		List<Integer>[] edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; i++) {
			if (p[i] >= 0) {
				edges[p[i]].add(i);
			}
		}
		List<Query>[] queries = new List[n];
		for (int i = 0; i < n; i++) {
			queries[i] = new ArrayList<Query>();
		}

		for (int i = 0; i < q; i++) {
			if (queryV[i] < 0 || p[queryV[i]] < 0) {
				continue;
			}
			Query q1 = new Query(i, 1, inputDist[i]);
			// Query q2 = new Query(i, -1, inputDist[i] - 1);
			Query q2 = new Query(i, -1, 0);
			queries[queryV[i]].add(q2);
			queries[p[queryV[i]]].add(q1);
		}

		int[] queryAnswer = new int[q];

		for (int i = 0; i < n; i++) {
			if (p[i] < 0) {
				dfs(edges, queries, queryAnswer, i);
			}
		}

		for (int i = 0; i < q; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(queryAnswer[i]);
		}
		out.println();
	}

	static SmartStructure dfs(List<Integer>[] edges, List<Query>[] queries, int[] queryAnswer, int u) {
		SmartStructure ret = new SmartStructure();
		for (int v : edges[u]) {
			SmartStructure cur = dfs(edges, queries, queryAnswer, v);
			ret = SmartStructure.union(ret, cur);
		}
		for (Query q : queries[u]) {
			queryAnswer[q.queryIndex] += q.sign * ret.getCount(q.distance);
		}
		ret.add++;
		return ret;
	}

	static class Query {
		int queryIndex;
		int sign;
		int distance;

		private Query(int queryIndex, int sign, int distance) {
			this.queryIndex = queryIndex;
			this.sign = sign;
			this.distance = distance;
		}
	}

	static class SmartStructure {
		Map<Integer, Integer> countForDistance;
		int add;

		SmartStructure() {
			countForDistance = new HashMap<Integer, Integer>();
			countForDistance.put(0, 1);
			add = 0;
		}

		SmartStructure addAll(SmartStructure other) {
			for (Map.Entry<Integer, Integer> entry : other.countForDistance.entrySet()) {
				int key = entry.getKey();
				int val = entry.getValue();
				add(countForDistance, key + other.add - add, val);
			}
			return this;
		}

		static SmartStructure union(SmartStructure a, SmartStructure b) {
			if (a.countForDistance.size() < b.countForDistance.size()) {
				return b.addAll(a);
			} else {
				return a.addAll(b);
			}
		}

		int getCount(int distance) {
			Integer ret = countForDistance.get(distance - add);
			if (ret == null) {
				ret = 0;
			}
			return ret;
		}
	}

	static void add(Map<Integer, Integer> map, Integer key, int add) {
		Integer have = map.get(key);
		if (have == null) {
			have = 0;
		}
		map.put(key, have + add);
	}

	static int go(int[][] up, int u, int go) {
		for (int h = up.length - 1; h >= 0 && u >= 0 && go > 0; --h) {
			if (((1 << h) & go) != 0) {
				go ^= 1 << h;
				u = up[h][u];
			}
		}
		if (go > 0) {
			return -1;
		}
		return u;
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