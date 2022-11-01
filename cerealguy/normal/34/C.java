import java.io.*;
import java.util.*;

public class C implements Runnable {

	private void solve() throws IOException {
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s, ",");
		boolean[] have = new boolean[1002];
		while (st.hasMoreTokens()) {
			have[Integer.parseInt(st.nextToken())] = true;
		}
		boolean first = true;
		for (int i = 0; i < have.length; i++) {
			if (have[i]) {
				int start = i;
				while (have[++i])
					;
				if (!first)
					out.print(",");
				else
					first = false;
				if (start != (i - 1))
					out.print(start + "-" + (i - 1));
				else
					out.print(start);
			}
		}
	}

	public static void main(String[] args) {
		new Thread(new C()).start();
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