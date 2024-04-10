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
		long ans = 0;
		for (int i = 0; i < n; i++) {
			for(int j = 0; j < n - i; j++) {
				ans += (i + 1);
			}
			ans-=i;
		}
		out.println(ans);
	}

	void run() throws IOException {
		 //br = new BufferedReader(new FileReader("input.txt"));
		 //out = new PrintWriter("output.txt");
		br = new BufferedReader(new InputStreamReader(System.in));
		 out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Localea.setDefault(Locale.US);
		new B().run();
	}
}