import java.io.*;
import java.util.*;

public final class Main {
	InputReader in;
	PrintWriter out;
	
	void main() {
		int n = in.nextInt();
		int s = (int)Math.sqrt(n);
		for (int i = s; i >= 1; --i) {
			if (n % i > 0) continue;
			out.println(i + " " + (n / i));
			return;
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