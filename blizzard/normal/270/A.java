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
	
	void solve() throws IOException {
		int n = nextInt();
		boolean[] f = new boolean[180];
		for (int nn = 3; nn < 1000; nn++) {
			if (Math.abs((double)(nn - 2)*180/nn - (nn - 2)*180/nn) < 1e-8) {
				if ((nn - 2)*180/nn < 180) f[(nn - 2)*180/nn] = true;
				if ((nn - 2)*180/nn == 179) System.err.println(nn);
			}
		}
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			if (f[x]) {
				out.println("YES");
			} else {
				out.println("NO");
			}
		}
	}

	void run() throws IOException {
		// br = new BufferedReader(new FileReader("input.txt"));
	//	 out = new PrintWriter("output.txt");
		 br = new BufferedReader(new InputStreamReader(System.in));
		 out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Localea.setDefault(Locale.US);
		new A().run();
	}
}