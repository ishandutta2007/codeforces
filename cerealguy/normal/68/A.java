import java.io.*;
import java.util.*;

public class A {

	int[] p0;
	int[] p;
	int l, r;
	int[] cnt;

	private void solve() throws IOException {
		p0 = new int[4];
		for (int i = 0; i < 4; i++) {
			p0[i] = nextInt();
		}
		l = nextInt();
		r = nextInt();
		cnt = new int[r - l + 1];
		p = new int[4];
		for (int i = 0; i < 4; i++) {
			p[0] = p0[i];
			for (int j = 0; j < 4; j++) {
				if (j == i)
					continue;
				p[1] = p0[j];
				for (int k = 0; k < 4; k++) {
					if (k == i || k == j)
						continue;
					p[2] = p0[k];
					for (int l = 0; l < 4; l++) {
						if (l == i || l == j || l == k)
							continue;
						p[3] = p0[l];
						check();
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < r - l + 1; i++) {
			if (cnt[i] >= 7)
				ans++;
		}
		out.println(ans);
	}

	void check() {
		for (int i = l; i <= r; i++) {
			int x = i;
			for (int j : p) {
				x %= j;
			}
			if (x == i)
				cnt[i - l]++;
		}
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