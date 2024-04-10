import java.io.*;
import java.util.*;

public class E {

	static int n;
	static int[] friend;
	static int[] sex;
	static int[] cycle;
	static int cycles;
	static int[] cyclesize;

	static int[][] listForCycle;
	static int[][] outEdges;

	static boolean[] onCycle;

	static void getCycles() {
		cycle = new int[n];
		Arrays.fill(cycle, -1);
		cycles = 0;
		for (int i = 0; i < n; i++) {
			go(i);
			if (cycle[i] == cycles) {
				++cycles;
			}
		}
		cyclesize = new int[cycles];
		for (int i = 0; i < n; i++) {
			cyclesize[cycle[i]]++;
		}
		listForCycle = new int[cycles][];
		onCycle = new boolean[n];
		for (int i = 0; i < n; i++) {
			int c = cycle[i];
			if (listForCycle[c] != null)
				continue;
			ArrayList<Integer> list = new ArrayList<Integer>();
			int j = i;
			for (int it = 0; it < cyclesize[c]; it++) {
				j = friend[j];
			}
			list.add(j);
			for (int j1 = friend[j]; j1 != j; j1 = friend[j1]) {
				list.add(j1);
			}
			int[] arr = new int[list.size()];
			for (int k = 0; k < list.size(); k++) {
				arr[k] = list.get(k);
				onCycle[arr[k]] = true;
			}
			listForCycle[c] = arr;
		}
	}

	static int[] cnt1, good1;
	static int[] cnt2, good2;

	static void restore1(int u, ArrayList<Pair> res) {
		for (int v : outEdges[u]) {
			restore2(v, res);
		}
	}

	private static void restore2(int u, ArrayList<Pair> res) {
		if (good1[u] == good2[u] && cnt1[u] == cnt2[u]) {
			restore1(u, res);
			return;
		}
		for (int v : outEdges[u]) {
			int cur = cnt1[u] - cnt2[v] + cnt1[v] + 1;
			int curGood = good1[u] - good2[v] + good1[v]
					+ (sex[u] == sex[v] ? 0 : 1);
			if (cur == cnt2[u] && curGood == good2[u]) {
				res.add(new Pair(u, v));
				for (int i : outEdges[u]) {
					if (i == v)
						restore1(i, res);
					else
						restore2(i, res);
				}
				return;
			}
		}
	}

	static void getOutEdges() {
		outEdges = new int[n][];
		int[] outEdgesCNT = new int[n];
		for (int i = 0; i < n; i++) {
			if (onCycle[i])
				continue;
			outEdgesCNT[friend[i]]++;
		}
		for (int i = 0; i < n; i++) {
			outEdges[i] = new int[outEdgesCNT[i]];
		}
		Arrays.fill(outEdgesCNT, 0);
		for (int i = 0; i < n; i++) {
			if (onCycle[i])
				continue;
			outEdges[friend[i]][outEdgesCNT[friend[i]]++] = i;
		}
	}

	static void work() {
		cnt1 = new int[n];
		cnt2 = new int[n];
		good1 = new int[n];
		good2 = new int[n];
		answer = new ArrayList<E.Pair>();
		cnt = 0;
		cntGood = 0;
		for (int c = 0; c < cycles; c++) {
			work(c);
		}
	}

	static int cnt, cntGood;
	static ArrayList<Pair> answer;

	static void work(int cycle) {
		int[] list = listForCycle[cycle];
		Pair res = new Pair(0, 0);
		ArrayList<Pair> pairs = new ArrayList<E.Pair>();
		int first = list[0];
		int last = list[list.length - 1];
		for (int i = 0; i < list.length - 1; i++) {
			int u = list[i];
			int next = list[i + 1];
			int[] e = outEdges[u];
			e = Arrays.copyOf(e, e.length + 1);
			e[e.length - 1] = next;
			outEdges[u] = e;
		}
		{
			dfs(first);
			Pair cur = new Pair(cnt2[first], good2[first]);
			if (res.compareTo(cur) < 0) {
				res = cur;
				pairs.clear();
				restore2(first, pairs);
			}
		}
		{
			{
				int u = list[list.length - 2];
				int[] e = outEdges[u];
				e = Arrays.copyOf(e, e.length - 1);
				outEdges[u] = e;
			}
			if (list.length > 2) {
				int u = list[0];
				int[] e = outEdges[u];
				e = Arrays.copyOf(e, e.length - 1);
				outEdges[u] = e;
			}
			int cnt = 0, good = 0;
			dfs(first);
			dfs(last);
			Pair ok = null;
			if (list.length > 2) {
				dfs(list[1]);
				ok = new Pair(cnt2[list[1]], good2[list[1]]);
				cnt += ok.a;
				good += ok.b;
			}
			cnt += cnt1[first];
			cnt += cnt1[last];
			good += good1[first];
			good += good1[last];
			cnt++;
			good += sex[first] == sex[last] ? 0 : 1;
			Pair cur = new Pair(cnt, good);
			if (res.compareTo(cur) < 0) {
				res = cur;
				pairs.clear();
				pairs.add(new Pair(first, last));
				restore1(first, pairs);
				restore1(last, pairs);
				if (list.length > 2) {
					restore2(list[1], pairs);
				}
			}
		}
		cnt += res.a;
		cntGood += res.b;
		answer.addAll(pairs);
	}

	static class Pair implements Comparable<Pair> {
		@Override
		public String toString() {
			return "Pair [a=" + a + ", b=" + b + "]";
		}

		int a, b;

		@Override
		public int compareTo(Pair o) {
			if (a != o.a)
				return a - o.a;
			return b - o.b;
		}

		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}

	static void dfs(int u) {
		cnt1[u] = 0;
		good1[u] = 0;
		cnt2[u] = 0;
		good2[u] = 0;
		for (int v : outEdges[u]) {
			dfs(v);
			cnt1[u] += cnt2[v];
			good1[u] += good2[v];
		}
		good2[u] = good1[u];
		cnt2[u] = cnt1[u];
		for (int v : outEdges[u]) {
			int cur = cnt1[u] - cnt2[v] + cnt1[v] + 1;
			int curGood = good1[u] - good2[v] + good1[v]
					+ (sex[u] == sex[v] ? 0 : 1);
			if (cur > cnt2[u] || cur == cnt2[u] && curGood > good2[u]) {
				cnt2[u] = cur;
				good2[u] = curGood;
			}
		}
	}

	static void go(int u) {
		if (cycle[u] != -1)
			return;
		cycle[u] = cycles;
		int v = friend[u];
		go(v);
		cycle[u] = cycle[v];
	}

	private void solve() throws IOException {
		n = nextInt();
		friend = new int[n];
		sex = new int[n];
		for (int i = 0; i < n; i++) {
			friend[i] = nextInt() - 1;
			sex[i] = nextInt();
		}
		getCycles();
		getOutEdges();
		work();
		out.println(cnt + " " + cntGood);
		for (Pair p : answer) {
			out.println((p.a + 1) + " " + (p.b + 1));
		}
	}

	public static void main(String[] args) {
		new E().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}