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
	
	boolean same(int n) {
		ArrayList<Integer> al = new ArrayList<>();
		int cop = n;
		while (cop > 0) {
			al.add(cop % 10);
			cop /= 10;
		}
		for (int i = 0; i < al.size(); i++) {
			for (int j = i + 1; j < al.size(); j++) {
				if (al.get(i) == al.get(j)) return true;;
			}
		}
		return false;
	}
	void solve() throws IOException {
		int n = nextInt();
		n++;
		while (same(n)) n++;
		out.println(n);
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
		new A().run();
	}
}