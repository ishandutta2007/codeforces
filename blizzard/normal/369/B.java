import java.util.*;
import java.io.*;

public class B {
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
		int l = nextInt();
		int r = nextInt();
		int sall = nextInt();
		int sk = nextInt();
		sk -= k * l;
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = l;
			sall -= l;
		}
		int t = sk / k;
		for (int i = 0; i < k; i++) {
			sk -= t;
			sall -= t;
			a[i] += t;
		}
		for (int i = 0; i < sk; i++) {
			a[i]++;
			sall--;
		}
		int p = a[k - 1];
		for (int i = k; i < n; i++) {
			if (sall > (p - a[i])) {
				sall -= (p - a[i]);
				a[i] = p;
			} else {
				a[i] += sall;
				sall = 0;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(a[i] + " ");
		}
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
		new B().run();
	}
}