import java.util.*;
import java.io.*;

public class C {
	BufferedReader br;
	PrintWriter out;
	StringTokenizer stok;

	String nextToken() throws IOException {
		while (stok == null || !stok.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null) {
				return null;
			}
			stok = new StringTokenizer(s);
		}
		return stok.nextToken();
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

	char nextChar() throws IOException {
		return (char) (br.read());
	}

	String nextLine() throws IOException {
		return br.readLine();
	}

	class Pair {
		int x, y;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	ArrayList<Pair> al[];
	ArrayList<Integer> stack;
	boolean color[];

	int dfs(int v, boolean problem) {
		int ret = 0;
		color[v] = true;
		for (Pair edge : al[v]) {
			if (!color[edge.x]) {
				ret += dfs(edge.x, edge.y == 2 ? true : false);
			}
		}
		if (problem) {
			if (ret > 0) {
				return ret;
			} else {
				stack.add(v + 1);
				return 1;
			}
		} else {
			return ret;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		al = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			al[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int x = nextInt();
			int y = nextInt();
			int t = nextInt();
			x--;
			y--;
			al[x].add(new Pair(y, t));
			al[y].add(new Pair(x, t));
		}
		stack = new ArrayList<Integer>();
		color = new boolean[n];
		dfs(0, false);
		out.println(stack.size());
		for (int i = 0; i < stack.size(); i++) {
			out.print(stack.get(i) + " ");
		}
	}

	void run() throws IOException {
		//br = new BufferedReader(new FileReader("input.txt"));
		//out = new PrintWriter("output.txt");
		 br = new BufferedReader(new InputStreamReader(System.in));
		 out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Locale.setDefault(Locale.US);
		new C().run();
	}
}