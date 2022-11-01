import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		String s = nextToken();
		out.println(check(s) ? "Yes" : "No");
	}

	private static boolean check(String s) {
		if (s.length() % 2 != 0) {
			return false;
		}
		int n = s.length();
		List<Integer> list = new ArrayList<>();
		int last = 0;
		for (int i = 0; i < n;) {
			int j = i + 1;
			while (j < n && s.charAt(j) == s.charAt(i)) {
				j++;
			}
			last += j - i;
			if ((last & 1) == 0) {
				if (!list.isEmpty()) {
					last = list.remove(list.size() - 1);
				} else {
					last = 0;
				}
			} else {
				list.add(last);
				last = 0;
			}

			i = j;
		}
		return list.isEmpty();

	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}