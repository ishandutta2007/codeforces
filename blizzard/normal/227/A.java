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
		long x1 = nextInt();
		long y1 = nextInt();
		long x2 = nextInt();
		long y2 = nextInt();
		long x3 = nextInt();
		long y3 = nextInt();
		x2 = x2 - x1;
		y2 = y2 - y1;
		x3 = x3 - x1;
		y3 = y3 - y1;
		final double eps = 1e-7;
		double t = Math.atan2(x2*y3-x3*y2, x2*x3+y2*y3);
		if (Math.abs(t) < eps) {
			out.println("TOWARDS");
		} else if (t < 0) {
			out.println("RIGHT");
		} else {
			out.println("LEFT");
		}
	}

	void run() throws IOException {
		//br = new BufferedReader(new FileReader("huffman.in"));
		//out = new PrintWriter("huffman.out");
	//	 br = new BufferedReader(new FileReader("input.txt"));
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