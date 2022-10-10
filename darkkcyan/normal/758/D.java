import java.io.*;
import java.util.*;

public final class Main {
	InputReader in;
	PrintWriter out;
	
	int n;
	String k;
	
	long dp[][];
	ArrayList<Long> pow;
	
	long process(int i, int dcnt) {
		if (i == k.length()) {
			if (dcnt > 0) return Long.MAX_VALUE;
			return 0;
		}
		if (dcnt == 0) return Long.MAX_VALUE;
		if (dp[i][dcnt] != -1) return dp[i][dcnt];
		if (k.charAt(i) == '0') return process(i + 1, dcnt - 1);
		
		dp[i][dcnt] = Long.MAX_VALUE;
		
		long cur = 0;
		for (int f = i; f < k.length(); ++f) {
			cur = cur * 10 + k.charAt(f) - '0';
			if (cur >= n) break;
			if (Long.MAX_VALUE / pow.get(dcnt - 1) < cur) break;
			long t = process(f + 1, dcnt - 1);
			if (Long.MAX_VALUE - t < cur * pow.get(dcnt - 1)) continue;
			dp[i][dcnt] = Math.min(dp[i][dcnt], t + cur * pow.get(dcnt - 1));
		}
		
		return dp[i][dcnt];
	}
	
	void main() {
		n = in.nextInt();
		k = in.nextString();
		
		pow = new ArrayList<Long>();
		pow.add(1L);
		while (pow.get(pow.size() - 1) <= Long.MAX_VALUE / n)
			pow.add(pow.get(pow.size() - 1) * n);
		dp = new long[k.length()][pow.size() + 1];
		for (int i = 0; i < k.length(); ++i)
			Arrays.fill(dp[i], -1);
		long ans = Long.MAX_VALUE;
		for (int i = 1; i <= pow.size(); ++i) {
			ans = Math.min(ans, process(0, i));
			if (ans != Long.MAX_VALUE) break;
		}
//		for (int i = 0; i < dp.length; ++i)
//			for (int f = 0; f < dp[i].length; ++f)
//				System.err.println(i + " " + f + " " + dp[i][f]);
		out.print(ans);
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