import java.io.*;
import java.util.*;

public class G implements Runnable {

	class Man {
		int a, c;

		public Man(int a, int c) {
			this.a = a;
			this.c = c;
		}
	}

	private void solve() throws IOException {
		int n = nextInt();
		Man[] m = new Man[n];
		for (int i = 0; i < n; i++) {
			m[i] = new Man(nextInt() - 1, nextInt());
		}
		ok = new Treap(rand.nextInt(), m[0].a);

		for (int i = 1; i < n; i++) {
			int pos = ok.firstGreater(m[i].a);
			if (pos <= m[i].c) {
				ok = ok.add(pos, m[i].a);
			} else {
				ok = ok.add(m[i].c, m[i].a);
			}
		}

		ArrayList<Integer> res = new ArrayList<Integer>();
		ok.output(res);
		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[res.get(i)] = i;
		}
		int[] ans = new int[n];
		for (int i = 0; i < n; i++) {
			ans[n - 1 - x[m[i].a]] = i + 1;
		}
		for (int i : ans) {
			out.print(i + " ");
		}
	}

	Treap ok;
	final static Random rand = new Random();

	static class Treap {
		private int y;
		public int cost;

		public Treap left;
		public Treap right;
		public int size = 1;
		public int max;

		private Treap(int y, int cost) {
			this.y = y;
			this.cost = cost;
			this.max = cost;
			this.left = null;
			this.right = null;
		}

		private Treap(int y, int cost, Treap left, Treap right) {
			this.y = y;
			this.cost = cost;
			this.max = cost;
			this.left = left;
			this.right = right;
		}

		public static int sizeOf(Treap treap) {
			return treap == null ? 0 : treap.size;
		}

		public static int maxOf(Treap treap) {
			return treap == null ? Integer.MIN_VALUE : treap.max;
		}

		public void recalc() {
			size = sizeOf(left) + sizeOf(right) + 1;
			max = Math.max(maxOf(left), maxOf(right));
			max = Math.max(max, cost);
		}

		public void split(int x, Treap[] LR) {
			Treap newTree = null;
			int curIndex = sizeOf(left) + 1;

			if (curIndex <= x) {
				if (right == null)
					LR[1] = null;
				else {
					Treap[] t = new Treap[] { newTree, LR[1] };
					right.split(x - curIndex, t);
					newTree = t[0];
					LR[1] = t[1];
				}
				LR[0] = new Treap(y, cost, left, newTree);
				LR[0].recalc();
			} else {
				if (left == null)
					LR[0] = null;
				else {
					Treap[] t = new Treap[] { LR[0], newTree };
					left.split(x, t);
					newTree = t[1];
					LR[0] = t[0];
				}
				LR[1] = new Treap(y, cost, newTree, right);
				LR[1].recalc();
			}
		}

		public static Treap merge(Treap L, Treap R) {
			if (L == null)
				return R;
			if (R == null)
				return L;

			Treap answer;
			if (L.y > R.y) {
				Treap newR = merge(L.right, R);
				answer = new Treap(L.y, L.cost, L.left, newR);
			} else {
				Treap newL = merge(L, R.left);
				answer = new Treap(R.y, R.cost, newL, R.right);
			}

			answer.recalc();
			return answer;
		}

		public Treap add(int pos, int elemCost) {
			Treap[] lr = new Treap[2];
			split(pos, lr);
			Treap m = new Treap(rand.nextInt(), elemCost);
			return merge(merge(lr[0], m), lr[1]);
		}

		public int firstGreater(int val) {
			if (maxOf(left) > val) {
				return left.firstGreater(val);
			}
			if (cost > val) {
				return sizeOf(left);
			}
			if (maxOf(right) < val)
				return size;
			return right.firstGreater(val) + sizeOf(left) + 1;
		}

		public void output(List<Integer> ret) {
			if (left != null)
				left.output(ret);
			ret.add(cost);
			if (right != null)
				right.output(ret);
		}

		public String toString() {
			ArrayList<Integer> t = new ArrayList<Integer>();
			output(t);
			return t.toString();
		}
	}

	public static void main(String[] args) {
		new Thread(new G()).start();
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