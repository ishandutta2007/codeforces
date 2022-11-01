import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		String line = br.readLine();
		for (int i = 0; i < line.length();) {
			if (line.charAt(i) == '"') {
				int j = i + 1;
				while (line.charAt(j) != '"') {
					j++;
				}
				out.println("<" + line.substring(i + 1, j) + ">");
				i = j + 1;
			} else {
				if (line.charAt(i) != ' ') {
					int j = i;
					while (j < line.length() && line.charAt(j) != ' ') {
						j++;
					}
					out.println("<" + line.substring(i, j) + ">");
					i = j;
				} else {
					i++;
				}
			}
		}
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