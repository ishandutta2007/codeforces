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
	
	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int[] l = new int[n];
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		l[0] = 0;
		for (int i = 1; i < n; i++) {
			if (a[i-1] >= 0) {
				l[i] = l[i-1] + 1;
			} else {
				l[i] = l[i-1];
			}
		}
		r[n-1] = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i + 1] <= 0) {
				r[i] = r[i+1] + 1;
			} else {
				r[i] = r[ i + 1];
			}
		}
		int ans = n;
		int tek;
		for (int i = 0; i < n - 1; i++) {
			tek = l[i+1] + r[i];
			ans = Math.min(ans, tek);
 		}
		out.println(ans);
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
		new solve().run();
	}
}