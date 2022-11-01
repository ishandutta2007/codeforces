import java.io.*;
import java.util.*;

public class d implements Runnable {

	int[] p, r;

	void init(int n) {
		p = new int[n];
		r = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}

	int get(int i) {
		if (p[i] != i)
			p[i] = get(p[i]);
		return p[i];
	}

	void union(int i, int j) {
		i = get(i);
		j = get(j);
		if (i == j)
			return;
		if (r[i] == r[j]) {
			r[i]++;
		}
		if (r[i] >= r[j]) {
			p[j] = i;
		} else {
			p[i] = j;
		}
	}

	class Pair {
		int a, b;

		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

	}

	private void solve() throws IOException {
		int n = nextInt();
		init(n);
		ArrayList<Pair> remove = new ArrayList<Pair>();
		ArrayList<Pair> add = new ArrayList<Pair>();
		for (int i = 0; i < n - 1; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			if (get(u) != get(v))
				union(u, v);
			else {
				remove.add(new Pair(u + 1, v + 1));
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (get(i) != get(j)) {
					add.add(new Pair(i + 1, j + 1));
					union(i, j);
				}
			}
		}
		if (add.size() != remove.size())
			throw new AssertionError();
		out.println(remove.size());
		for (int i = 0; i < remove.size(); i++) {
			out.println(remove.get(i).a + " " + remove.get(i).b + " "
					+ add.get(i).a + " " + add.get(i).b);
		}
	}

	public static void main(String[] args) {
		new Thread(new d()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
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

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}