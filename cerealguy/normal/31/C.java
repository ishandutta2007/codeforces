import java.io.*;
import java.util.*;

public class C implements Runnable {

	class Segment implements Comparable<Segment> {
		int l, r, id;

		public Segment(int l, int r, int id) {
			this.l = l;
			this.r = r;
			this.id = id;
		}

		@Override
		public int compareTo(Segment o) {
			if (l < o.l)
				return -1;
			if (l > o.l)
				return 1;
			if (r < o.r)
				return -1;
			if (r > o.r)
				return 1;
			return 0;
		}

	}

	private void solve() throws IOException {
		int n = nextInt();
		Segment[] s = new Segment[n];
		for (int i = 0; i < n; i++) {
			s[i] = new Segment(nextInt(), nextInt(), i);
		}
		Arrays.sort(s);

		boolean[] ok = new boolean[n];
		int ans = 0;

		ii: for (int i = 0; i < n; i++) {
			int last = Integer.MIN_VALUE;
			for (int j = 0; j < n; j++) {
				if (j == i)
					continue;
				if (s[j].l < last)
					continue ii;
				last = s[j].r;
			}
			ok[s[i].id] = true;
			ans++;
		}

		out.println(ans);

		for (int i = 0; i < n; i++) {
			if (ok[i]) {
				out.print((i + 1) + " ");
			}
		}

	}

	public static void main(String[] args) {
		new Thread(new C()).start();
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