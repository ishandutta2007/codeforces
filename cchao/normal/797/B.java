import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
	void solve() {
    int n = in.nextInt();
    int max_odd = -100000;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int x = in.nextInt();
      if (x >= 0) {
        sum += x;
        if (x % 2 != 0) max_odd = Math.max(max_odd, -x);
      }
      else if (x % 2 != 0) max_odd = Math.max(max_odd, x);
    }
    if (sum % 2 == 0) sum += max_odd;
    out.println(sum);
	}
	class InputReader {
		StringTokenizer tok; BufferedReader buf;
		InputReader(String file) {
			try {
				buf = new BufferedReader(new FileReader(file));
			} catch(FileNotFoundException e) { e.printStackTrace(); }
		}
		InputReader() {
			buf = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while(tok == null || !tok.hasMoreElements()) {
				try {
					String s = buf.readLine();
					if(s == null) {  return null; }
					tok = new StringTokenizer(s);
				} catch(IOException e) { return null; }
			}
			return tok.nextToken();
		}
		boolean hasNext() {
			while(tok == null || !tok.hasMoreElements()) {
				try {
					String s = buf.readLine();
					if(s == null) {return false; }
					tok = new StringTokenizer(s);
				} catch(IOException e) { return false; }
			}
			return true;
		}
		int nextInt() { return Integer.parseInt(next()); }
		long nextLong() { return Long.parseLong(next()); }
		double nextDouble() { return Double.parseDouble(next()); }
		BigInteger nextBigInteger() { return (new BigInteger(next())); }
	}
	InputReader in; PrintWriter out;
	void runFile(String task) {
		try {
			in = new InputReader(task + ".in");
			out = new PrintWriter(task + ".out");
		} catch(IOException e) {
			e.printStackTrace();
		}
		solve(); out.close();
	}
	void run() {
		in = new InputReader();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	public static void main(String[] args) { new Main().run(); }
}