import java.io.*;
import java.util.*;

public final class Main {
	InputReader in;
	PrintWriter out;
	
	void main() {
		String s = in.nextString();
		char pos[] = new char[4];
		int ans[] = new int[4];
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == '!') ans[i % 4]++;
			else pos[i % 4] = s.charAt(i);
		}
		
		String t = "RBYG";
		for (int i = 0; i < 4; ++i) {
			int f;
			for (f = 0; f < 4; ++f)
				if (pos[f] == t.charAt(i)) {
					out.print(ans[f] + " ");
					break;
				}
			if (f == 4) for (f = 0; f < 4; ++f) {
				if (pos[f] == 0) {
					out.print(ans[f] + " ");
					break;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		new Main();
	}

	public Main() {
		in = new InputReader("main.inp");
		out = new PrintWriter(System.out);
		main();
		out.close();
	}

	class InputReader {
		BufferedReader bf;
		StringTokenizer st = null;
		
		InputReader(String filename) {
			try {
				bf = new BufferedReader(new FileReader(filename));
			} catch (Exception e) {
				e.printStackTrace();
				System.err.println("use stdin instead");
				bf = new BufferedReader(new InputStreamReader(System.in));
			}
		}
		
		String nextString() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(bf.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			return st.nextToken();
		}
	
		long nextLong() {return Long.parseLong(nextString());}
		int nextInt() {return Integer.parseInt(nextString());}
		double nextDouble() {return Double.parseDouble(nextString());}
	}

}