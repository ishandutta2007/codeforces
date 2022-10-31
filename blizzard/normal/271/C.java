import java.util.*;
import java.io.*;

public class C {
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
		if (n / k < 3) {
			out.println("-1");
			return;
		}
		int[] a = new int[n + 1];
		for (int i = 1; i <= k; i++) {
			a[i] = i;
		}
		a[2 * k] = 1;
		for (int i = k + 1; i < k * 2; i++) {
			a[i] = i - k + 1;
		}
		int next = 1;
		for (int i = 2 * k + 1; i <= n; i++) {
			a[i] = next;
			next++;
			if (next > k) {
				next = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
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
		// Localea.setDefault(Locale.US);
		new C().run();
	}
}