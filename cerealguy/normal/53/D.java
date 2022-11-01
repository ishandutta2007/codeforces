import java.io.*;
import java.util.*;

public class D implements Runnable {

	private void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				int j;
				for (j = i; a[j] != b[i]; ++j)
					;
				for (; j > i; --j) {
					ans.add(j - 1);
					a[j] = a[j - 1];
				}
				a[i] = b[i];
			}
		}
		out.println(ans.size());
		for (int i : ans) {
			out.println((i + 1) + " " + (i + 2));
		}
	}

	public static void main(String[] args) {
		new Thread(new D()).start();
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
}