import java.io.*;
import java.util.*;

public class E {

	int n;
	int[] a;
	int[] b;
	boolean[] ok;

	private void solve() throws IOException {
		n = nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		ok = new boolean[n];
		get1();
		get2();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (ok[i]) cnt++;
		}
		out.println(cnt);
		for (int i = 0; i < n; i++) {
			if (ok[i]) {
				out.print((i+1)+" ");
			}
		}
		out.println();
	}

	void get1() {
		int[] s = new int[n];
		s[0] = 0;
		for (int i = 1; i < n; i++) {
			s[i] = s[i - 1] + a[i - 1] - b[i - 1];
		}
		int min = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] < s[min])
				min = i;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == s[min])
				ok[i] = true;
		}
	}

	void get2() {
		int[] s = new int[n];
		s[0] = 0;
		for (int i = n - 1; i > 0; i--) {
			s[i] = s[(i + 1) % n] + a[(i + 1) % n] - b[i];
		}
		int min = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] < s[min])
				min = i;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == s[min])
				ok[i] = true;
		}
	}

	public static void main(String[] args) {
		new E().run();
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