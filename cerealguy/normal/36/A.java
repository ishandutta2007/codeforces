import java.io.*;
import java.util.*;

public class A implements Runnable {

	private void solve() throws IOException {
		nextToken();
		String s = nextToken();
		int res = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != '1')
				continue;
			for (int j = i + 1; j < s.length(); j++) {
				if (s.charAt(j) == '1') {
					if (res == -1)
						res = j - i;
					if (res != j - i) {
						out.println("NO");
						return;
					}
					break;
				}
			}
		}
		out.println("YES");
	}

	public static void main(String[] args) {
		new Thread(new A()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
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