import java.util.*;
import java.io.*;

public class solve_dk {
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
	class Friend implements Comparable<Friend> {
		int l, r, v, num;

		
		public Friend(int l, int r, int v, int num) {
			super();
			this.l = l;
			this.r = r;
			this.v = v;
			this.num = num;
		}


		public int compareTo(Friend oth) {
			return (this.v - oth.v);
		}
	}int[] m, d, p ,t;
	int n;
	boolean check(int x) {
		for (int i = 1; i < 1000; i++) {
			for (int j = 0; j < n; j++) {
				if (d[j] == i) {
					x += p[j];
				}
			}
			for (int j = 0; j < n; j++) {
				if (d[j] - t[j]== i) {
					x -= p[j];
					if (x < 0) return false;
				}
			}
		}
		return true;
	}
	void solve() throws IOException {
		n  = nextInt();
		
		m = new int[n];
		d = new int[n];
		p = new int[n];
		t = new int[n];
		
		for (int i = 0; i < n; i++) {
			m[i] = nextInt();
			d[i] = nextInt();
			p[i] = nextInt();
			t[i] = nextInt();
		}
		int[] part = new int[13];
		part[1] = 366;
		part[2] = part[1] + 31;
		part[3] = part[2] + 28;
		part[4] = part[3] + 31;
		part[5] = part[4] + 30;
		part[6] = part[5] + 31;
		part[7] = part[6] + 30;
		part[8] = part[7] + 31;
		part[9] = part[8] + 31;
		part[10] = part[9] + 30;
		part[11] = part[10] + 31;
		part[12] = part[11] + 30;
		for (int i = 0; i < n; i++) {
			d[i] = part[m[i]] + d[i];
		}
		int l = 0;
		int r = 10000000;
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if (!check(l)) l++;
		out.println(l);
	}

	void run() throws IOException {
		//br = new BufferedReader(new FileReader("huffman.in"));
		//out = new PrintWriter("huffman.out");
		 br = new BufferedReader(new FileReader("input.txt"));
		 out = new PrintWriter("output.txt");
		// br = new BufferedReader(new InputStreamReader(System.in));
		// out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Localea.setDefault(Locale.US);
		new solve_dk().run();
	}
}