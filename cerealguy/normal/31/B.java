import java.io.*;
import java.util.*;

public class B implements Runnable {

	enum State {
		empty, before, after;
	}

	private void solve() throws IOException {
		String s = br.readLine();
		if (s.indexOf('@') < 0) {
			out.println("No solution");
			return;
		}

		String[] parts = s.split("@", -1);
		if (parts.length == 1) {
			out.println(s);
			return;
		}

		for (int i = 0; i < parts.length; i++) {
			String p = parts[i];
			if (p.length() < 1
					|| (p.length() < 2 && i != 0 && i != parts.length - 1)) {
				out.println("No solution");
				return;
			}
		}
		
		out.print(parts[0]+"@"+parts[1].charAt(0));
		parts[1] = parts[1].substring(1);
		for (int i = 1; i < parts.length - 1; i++) {
			out.print(","+parts[i]+ "@");
			out.print(parts[i + 1].charAt(0));
			parts[i + 1] = parts[i + 1].substring(1);
		}
		out.println(parts[parts.length - 1]);

	}

	public static void main(String[] args) {
		new Thread(new B()).start();
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