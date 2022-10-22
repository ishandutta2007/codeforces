import java.io.*;
import java.util.*;
public class Main {
	public static void main (String... args) {
	   	int n = readInt();
	   	int[] a = new int[n+1]; int[][] dp = new int[n+1][3];
	   	for (int i = 1; i <= n; i++) {
	   		a[i] = readInt();
	   		Arrays.fill(dp[i],1_000_000_000);
	   		if (a[i] == 1 || a[i] == 3) dp[i][2] = Math.min(dp[i-1][0],dp[i-1][1]);
	   		if (a[i] == 2 || a[i] == 3) dp[i][1] = Math.min(dp[i-1][0],dp[i-1][2]);
	   		dp[i][0] = Math.min(dp[i-1][0],Math.min(dp[i-1][1],dp[i-1][2])) + 1;
	   	}
	   	System.out.println(Math.min(dp[n][0],Math.min(dp[n][1],dp[n][2])));
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
	static StringTokenizer st;
	static String read () {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {}
		}
		return st.nextToken();
	} 
	static int readInt () {
		return Integer.parseInt(read());
	}
}
//dp[i][j] --> least number of rests in the first i days such that the last activity done was j
//0 --> rest, 1 --> gym, 2 --> contest
//if (a[i] == 1 || a[i] == 3) dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
//if (a[i] == 2 || a[i] == 3) dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
//dp[i][0] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + 1;