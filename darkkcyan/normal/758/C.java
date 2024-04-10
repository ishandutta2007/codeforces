import java.io.*;
import java.util.*;

public final class Main {
	InputReader in;
	PrintWriter out;
	
	void main() {
		int n, m, x, y; long k;
		n = in.nextInt(); m = in.nextInt();
		k = in.nextLong();
		x = in.nextInt(); y = in.nextInt(); --x; --y;
		
		long rp[] = new long[n];
		long cp[][] = new long[n][m];
		
		long t;
		if (n > 1) {
			t = (k / (2 * (n - 1) * m)); k %= 2 * (n - 1) * m;
		} else {
			t = k / m; k %= m;
		}
		int i, f, d = 1;
		for (i = 0; k >= m; i += d, k -= m) {
			if (i == n - 1) d = -1;
			if (i == 0) d = 1;
			if (n == 1) d = 0;
			rp[i] ++;
		}
		for (f = 0; f < k; ++f) cp[i][f]++;
		
		long ma = -1, mi = Long.MAX_VALUE;
		long sg = 0;
		for (i = 0; i < n; ++i) {
			for (f = 0; f < m; ++f) {
				long cur = t + rp[i] + cp[i][f];
				if (i != n - 1 && i != 0) cur += t;
				ma = Math.max(ma, cur);
				mi = Math.min(mi, cur);
				if (i == x && f == y) sg = cur;
			}
		}
		
		out.println(ma + " " + mi + " " + sg);
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