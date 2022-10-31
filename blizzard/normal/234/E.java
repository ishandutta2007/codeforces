import java.util.*;
import java.io.*;

public class solve {
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

	class Class implements Comparable {
		String s;
		int x;

		Class(String _s, int _x) {
			s = _s;
			x = _x;
		}

		@Override
		public int compareTo(Object o) {
			// TODO Auto-generated method stub
			Class tmp = (Class) o;
			return x - tmp.x;
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int x = nextInt();
		int a = nextInt();
		int b = nextInt();
		int c = nextInt();
		boolean[] f = new boolean[n];
		String s;
		Class[] m = new Class[n];
		for (int i = 0; i < n; i++) {
			s = nextToken();
			m[i] = new Class(s, nextInt());
		}
		Arrays.sort(m);
		int y;
		int ss = n / 4;
		int q;
		for (int i = 0; i < n / 4; i++) {
			out.println("Group " + (char) ('A' + i) + ":");
			for (int qq = 3; qq >= 0; qq--) {
				y = (x * a + b) % c;
				x = y;
				q = x % ss;
				for (int j = (qq + 1) * (n / 4) - 1; j >= (qq) * (n / 4); j--) {
					if (f[j] == true)
						continue;
					if (q == 0) {
						f[j] = true;
						out.println(m[j].s);
						break;
					}
					q--;
				}
			}
			ss--;
		}
	}

	void run() throws IOException {
		// br = new BufferedReader(new FileReader("huffman.in"));
		// out = new PrintWriter("huffman.out");
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
		new solve().run();
	}
}