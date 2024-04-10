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
		long n = nextInt();
		long m = nextInt();
		long p = 1;
		long k = 3;
		while (n > 0) {
			if (n % 2 == 0) {
				k = (k * k) % m;
				n /= 2; 
			} else {
				n -= 1;
				p = (p * k) % m;
			}
		}
		p = p + m;
		out.println((p - 1) % m);
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