import java.io.*;
import java.util.*;

public class E {

	private static void solve() throws IOException {
		nextToken();
		int n = nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		Map<Integer, List<Integer>> xx = new HashMap<Integer, List<Integer>>();
		Map<Integer, List<Integer>> yy = new HashMap<Integer, List<Integer>>();
		Map<Integer, List<Integer>> xy = new HashMap<Integer, List<Integer>>();
		Map<Integer, List<Integer>> yx = new HashMap<Integer, List<Integer>>();
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
			y[i] = nextInt();
			add(xx, x[i], y[i]);
			add(yy, y[i], x[i]);
			add(xy, x[i] - y[i], x[i]);
			add(yx, x[i] + y[i], x[i]);
		}
		sort(xx);
		sort(yy);
		sort(xy);
		sort(yx);

		int[] t = new int[9];
		for (int i = 0; i < n; i++) {
			int beat = 0;
			beat += beat(xx.get(x[i]), y[i]);
			beat += beat(yy.get(y[i]), x[i]);
			beat += beat(xy.get(x[i] - y[i]), x[i]);
			beat += beat(yx.get(x[i] + y[i]), x[i]);
			t[beat]++;
		}
		for (int i = 0; i < t.length; i++) {
			out.print(t[i]+" ");
		}
	}

	static int beat(List<Integer> list, int val) {
		int beat = 0;
		if (val != list.get(0)) {
			++beat;
		}
		if (val != list.get(list.size() - 1)) {
			++beat;
		}
		return beat;
	}

	static void sort(Map<Integer, List<Integer>> map) {
		for (List<Integer> list : map.values()) {
			Collections.sort(list);
		}
	}

	static void add(Map<Integer, List<Integer>> map, int key, int val) {
		List<Integer> list = map.get(key);
		if (list == null) {
			list = new ArrayList<Integer>();
			map.put(key, list);
		}
		list.add(val);
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