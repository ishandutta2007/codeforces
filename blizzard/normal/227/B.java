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
		long ansa = 0, ansb = 0;
		int[] a = new int[100000];
		int[] b = new int[100031];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			b[a[i]] = i;
		}
		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int x = nextInt();
			ansa += b[x] + 1;
			ansb += n - b[x];
		}
		out.print(ansa);
		out.print(" ");
		out.println(ansb);
	}

	void run() throws IOException {
		//br = new BufferedReader(new FileReader("huffman.in"));
		//out = new PrintWriter("huffman.out");
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
		new solve_dk().run();
	}
}