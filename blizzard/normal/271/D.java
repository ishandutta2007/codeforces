import java.util.*;
import java.io.*;

public class D {
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
	final long MOD = 1000000000000007L;
	void solve() throws IOException {
		String s = nextLine();
		String p = nextLine();
		int k = nextInt();
		ArrayList<Integer> al = new ArrayList<>();
		al.add(-1);
		for (int i = 0; i < s.length(); i++) {
			if (p.charAt(s.charAt(i) - 'a') == '0') al.add(i);
		}
		HashSet<Long> set = new HashSet<Long>();
		long[] pp = new long[1531];
		pp[0] = 1;
		for (int i = 1; i < 1531; i++) {
			pp[i] = (pp[i-1] * 347) % MOD;;
		}
		long[][] hash = new long[1531][1531];
		for (int i = 0; i < s.length(); i++) {
			long h = 0;
			for (int j = i; j < s.length(); j++) {
				h = (h + pp[j - i] * s.charAt(j)) % MOD;
				hash[i][j] = h;
			}
		}
		for (int left = 0; left < s.length(); left++) {
			for (int right = left; right < s.length(); right++) {
				int l = 0;
				int r = al.size();
				int m;
				while (l < r - 1) {
					m = (l + r) / 2;
					if (al.get(m) < left) l = m; else r = m;
				}
				int q = l;
				int e;
				if (left == 0 && right == 2) 
					e = 1;
				l = 0;
				r = al.size();
				while (l < r - 1) {
					m = (l + r) / 2;
					if (al.get(m) <= right) l = m; else r = m;
				}
				int kol = l - q;
				if (kol <= k) {
					long h = hash[left][right];
					if (!set.contains(h)) {
						set.add(h);
						//out.println(left + " " + right);
					}
				}
			}
		}
		out.println(set.size());
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
		new D().run();
	}
}