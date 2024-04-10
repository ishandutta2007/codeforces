import java.util.*;
import java.io.*;

public class A {
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
	int[] a;
	int n;
	boolean check(int x) {
		int j = n - 1;
		for (int i = n - x - 1; i >= 0; i--) {
			if (a[i] * 2 > a[j]) {
				return false;
			}
			j--;
		}
		return true;
	}
	void solve() throws IOException {
		n = nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		int l = (n / 2);
		if (n % 2 == 0) l--;
		int r = n;
		while (l < r - 1) {
			int m = (l + r) / 2;
			if (check(m)) {
				r = m;
			} else {
				l = m;
			}
		}
		out.println(r);
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
		// Locale.setDefault(Locale.US);
		new A().run();
	}
}