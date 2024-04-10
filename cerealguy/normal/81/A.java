import java.io.*;
import java.util.*;

public class A {

	private void solve() throws IOException {
		String s = nextToken();
		ArrayList<Character> stack = new ArrayList<Character>();
		stack.add((char) 0);
		for (int i = 0; i < s.length(); i++) {
			char last = stack.get(stack.size() - 1);
			if (s.charAt(i) != last) {
				stack.add(s.charAt(i));
			} else {
				stack.remove(stack.size() - 1);
			}
		}
		for (int i = 1; i < stack.size(); i++) {
			out.print(stack.get(i));
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