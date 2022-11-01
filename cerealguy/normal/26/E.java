import java.io.*;
import java.util.*;

public class E implements Runnable {

	private void solve() throws IOException {
		int n = nextInt(), w = nextInt();
		int[] a = new int[n];
		int s = 0;
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
			s += a[i];
		}
		if (n == 1) {
			if (w != s) {
				out.println("No");
				return;
			} else {
				out.println("Yes");
				for (int i = 0; i < a[0]; i++) {
					out.print("1 1 ");
				}
				return;
			}
		}
		if (w == 1) {
			for (int i = 0; i < a.length; i++) {
				if (a[i] == 1) {
					out.println("Yes");
					out.print((i + 1) + " ");
					for (int j = 0; j < a.length; j++) {
						if (j == i)
							continue;
						for (int k = 0; k < a[j]; k++) {
							out.print((j + 1) + " " + (j + 1) + " ");
						}
					}
					out.println((i + 1));
					return;
				}
			}
			out.println("No");
			return;
		}
		if (w < 2 || w > s) {
			out.println("No");
			return;
		}
		out.println("Yes");

		StringBuilder output = new StringBuilder();
		int i;
		for (i = n - 1; i >= 2; i--) {
			int add = Math.min(a[i], w - 2);
			boolean first = true;
			for (int j = 0; j < add; j++) {
				if (first) {
					out.print((i + 1) + " ");
					out.print(output);
					output = new StringBuilder();
					out.print((i + 1) + " ");
					first = false;
				} else
					out.print((i + 1) + " " + (i + 1) + " ");
			}
			for (int j = add; j < a[i]; j++) {
				output.append((i + 1) + " " + (i + 1) + " ");
			}
			w -= add;
		}
		if (w >= a[0]) {
			int add = w - a[0];
			boolean first = true;
			for (int j = 0; j < add; j++) {
				if (first) {
					out.print(2 + " ");
					out.print(output);
					output = new StringBuilder();
					out.print(2 + " ");
					first = false;
				} else
					out.print(2 + " " + 2 + " ");
			}
			for (int j = add; j < a[1]; j++) {
				output.append(2 + " " + 2 + " ");
			}

			out.print(1 + " ");
			out.print(output);
			out.print(1 + " ");
			for (int j = 1; j < a[0]; j++) {
				out.print(1 + " " + 1 + " ");
			}
			return;
		} else {
			out.print(2 + " ");
			out.print(output);
			for (int j = 0; j < a[0] - w + 1; j++) {
				out.print(1 + " " + 1 + " ");
			}
			out.print(2 + " " + 1 + " ");
			for (int j = 1; j < a[1]; j++) {
				out.print(2 + " " + 2 + " ");
			}
			out.print(1 + " ");
			for (int j = 0; j < w - 2; j++) {
				out.print(1 + " " + 1 + " ");
			}
		}
	}

	public static void main(String[] args) {
		new Thread(new E()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}