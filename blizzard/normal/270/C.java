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
	class P implements Comparable<P> {
		long k;
		long x;
		@Override
		public int compareTo(P o) {
			if (this.k > o.k) return 1;
			if (this.k < o.k) return -1;
			return 0;
		}
		public P(long k, long x) {
			super();
			this.k = k;
			this.x = x;
		}
	}
	
	void solve() throws IOException {
		int n = nextInt();
		P[] a = new P[n];
		for (int i = 0; i < n; i++) {
			a[i] = new P(nextLong(), nextLong());
		}
		Arrays.sort(a);
		long tek = 0;
		long curk = 0;
		long k = a[0].k; 
		long x = a[0].x;
		curk = k;
		tek = x;
		for (int i = 1; i < n; i++) {
			k = a[i].k;
			x = a[i].x;
			while (curk < k && tek > 1) {
				tek = (tek + 3) / 4;
				curk++;
			}
			tek = Math.max(tek, x);
			curk = k;
		}
		while (tek > 1) {
			tek = (tek + 3) / 4;
			curk++;
		}
		if (curk == a[n-1].k) curk++;
		out.println(curk);
	}

	void run() throws IOException {
		// br = new BufferedReader(new FileReader("input.txt"));
		// out = new PrintWriter("output.txt");
		 br = new BufferedReader(new InputStreamReader(System.in));
		 out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Localea.setDefault(Locale.US);
		new C().run();
	}
}