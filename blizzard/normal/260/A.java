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
		int a = nextInt();
		int b = nextInt();
		int n = nextInt();
		for (int i = 0; i < 10; i++) {
			if ((10 * a + i) % b == 0) {
				out.print(a);
				out.print(i);
				for (int j = 0; j < n - 1; j++) {
					out.print("0");
				}
				out.println();
				return;
			}
		}
		out.println("-1");
	}

	void run() throws IOException {
		//br = new BufferedReader(new FileReader("A.in"));
		//out = new PrintWriter("A.in");
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