import java.util.*;
import java.io.*;
public class Main {
	public static void main (String[] args) {
		int n = readInt();
		int[] f = new int[100_005];
		for (int i = 0; i < n; i++) {
			int a = readInt();
			++f[a];
		}
		long[] dp = new long[100_005];
		dp[0] = 0;
		dp[1] = (long)f[1] * 1;
		for (int i = 2; i <= 100_000; i++) {
			dp[i] = Math.max(dp[i-1],(long)f[i]*i+dp[i-2]);
		}
		System.out.println(dp[100_000]);
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String read () {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine()); 
			} catch (IOException e) {}
		}
		return st.nextToken();
	}
	static int readInt() {
		return Integer.parseInt(read());
	}
	static long readLong() {
		return Long.parseLong(read());
	}
}
//dp[i] = maximum number of points that Alex can earn using only numbers <= i
//we cannot take 2 adjacent numbers
//when we take a number i, we get f_i * i
//dp[i] = max(dp[i-1],f[i] * i + dp[i-2])