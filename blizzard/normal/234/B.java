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
		int k = nextInt();
		int[] a = new int[n];
		boolean[] f = new boolean[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		for (int j = 0; j < k; j++) {
			int max = 0;
			for (int i = 0; i < n; i++) {
				if (f[i] == false) {
					max = Math.max(max, a[i]);
				}
			}
			for (int i = 0; i < n; i++) {
				if (f[i] == false && max == a[i]) {
					f[i] = true;
					break;
				}
			}
		}
		int min = 101;
		for (int i = 0; i < n; i++) {
			if (f[i] == true) {
				min = Math.min(min, a[i]);
			}
		}
		out.println(min);
		for (int i = 0; i < n; i++) {
			if (f[i] == true) {
				out.print((i + 1) + " ");
			}
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
		new solve().run();
	}
}