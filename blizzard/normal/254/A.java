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
	
	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[2 * n];
		int[] b = new int[5001];
		int[] x = new int[n];
		int[] y = new int[n];
		int kol = 0;
		for (int i = 0; i < 2 * n; i++) {
			a[i] = nextInt();
			if (b[a[i]] == 0) {
				b[a[i]] = i + 1;
			} else {
				x[kol] = b[a[i]];
				y[kol] = i + 1;
				b[a[i]] = 0;
				kol++;
			}
		}
		if (kol == n) {
			for (int i = 0; i < kol; i++) {
				out.println(x[i] + " " + y[i]);
			}
		} else {
			out.println("-1");
		}
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