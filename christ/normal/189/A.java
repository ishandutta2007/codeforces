import java.util.*;
import java.io.*;
public class Main {
	public static void main (String[] args) {
		int n = readInt(), a = readInt(), b = readInt(), c = readInt();
		int[] dp = new int[n+1];
		Arrays.fill(dp,(int)-1e9);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			if (i - a >= 0) dp[i] = Math.max(dp[i],dp[i-a] + 1);
			if (i - b >= 0) dp[i] = Math.max(dp[i],dp[i-b] + 1);
			if (i - c >= 0) dp[i] = Math.max(dp[i],dp[i-c] + 1);
		} 
		System.out.println(dp[n]);
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
//dp[i] = maximum number of ribbon pieces to cut a ribbon of length i (using a,b,c)