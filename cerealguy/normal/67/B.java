import java.io.*;
import java.util.*;

public class B {

	private void solve() throws IOException {
		n = nextInt();
		k = nextInt();
		b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		next = new int[n + 1];
		prev = new int[n + 1];
		start = 0;
		Arrays.fill(next, -1);
		Arrays.fill(prev, -1);
		get(0);
		for (int i = start; i != n; i = next[i]) {
			out.print((i + 1) + " ");
		}
		out.println();
	}

	int n;
	int k;
	int[] next, prev, b;
	int start;

	void get(int off) {
		if (off == n - 1) {
			start = n - 1;
			next[start] = n;
			prev[n] = start;
			return;
		}
		get(off + 1);
		if (b[off] == 0) {
			next[off] = start;
			prev[start] = off;
			start = off;
			return;
		}
		int cnt = 0;
		int i = start;
		while (cnt < b[off]) {
			if (i >= off + k)
				cnt++;
			i = next[i];
		}
		i = prev[i];
		prev[next[i]] = off;
		next[off] = next[i];
		next[i] = off;
		prev[off] = i;
	}

//	void debug() {
//		for (int i = start; i != n; i = next[i]) {
//			System.err.print(i + " ");
//		}
//		System.err.println();
//	}

	public static void main(String[] args) {
		new B().run();
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