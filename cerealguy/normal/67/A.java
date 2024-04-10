import java.io.*;
import java.util.*;

public class A {

	int n;

	private void solve() throws IOException {
		n = nextInt();
		String s = nextToken();
		int[] a = new int[n];
		a[0] = 1;
		for (int i = 0; i < n - 1; i++) {
			char c = s.charAt(i);
			switch (c) {
			case '=':
				a[i + 1] = a[i];
				break;
			case 'L':
				a[i + 1] = 1;
				break;
			case 'R':
				a[i + 1] = a[i] + 1;
				break;
			}
		}
		int[] b = new int[n];
		b[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			char c = s.charAt(i);
			switch (c) {
			case '=':
				b[i] = b[i + 1];
				break;
			case 'L':
				b[i] = b[i + 1] + 1;
				break;
			case 'R':
				b[i] = 1;
				break;
			}
		}
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = Math.max(a[i], b[i]);
		}
		for (int i = 0; i < n; i++) {
			if (i > 0)
				out.print(" ");
			out.print(res[i]);
		}
		out.println();
	}

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
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
}