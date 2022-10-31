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
	
	boolean isPrime(int x) {
		if (x == 1) return false;
		for (int i = 2; i <= Math.sqrt(x); i++) {
			if (x % i == 0) return false;
		}
		return true;
	}
	HashMap<Integer, Integer> map;
	int q(int a) {
		if (map.containsKey(a)) return (map.get(a));
		int cop = a;
		while (!isPrime(cop)) {
			cop++;
		}
		map.put(a, cop - a);
		return cop - a;
	}
	void solve() throws IOException {
		int n =nextInt();
		int m =nextInt();
		map = new HashMap<>();
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = nextInt();
			}
		}
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += q(a[i][j]);
			}
			ans = Math.min(ans, sum);
		}
		for (int i = 0; i < m; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				sum += q(a[j][i]);
			}
			ans = Math.min(ans, sum);
		}
		out.println(ans);
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
		new B().run();
	}
}