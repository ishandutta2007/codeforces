import java.io.*;
import java.util.*;
public class Main {
	public static void main (String... args) {
	   	int n = readInt();
	   	int[][] h = new int[n+1][2];
	   	long[][] dp = new long[n+1][2];
	  	for (int j = 0; j < 2; j++) {
	  		for (int i = 1; i <= n; i++) {
	  			h[i][j] = readInt();
	  		}
	   	}
	   	for (int i = 1; i <= n; i++) {
	   		for (int j = 0; j < 2; j++) {
	   			dp[i][j] = Math.max(dp[i-1][j],dp[i-1][1 - j] + h[i][j]);
	   		}
	   	}
	   	System.out.println(Math.max(dp[n][0],dp[n][1]));
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
//dp[i][j] --> maximum sum of heights if weve taken players up to index i, and the last player we took was from row j
//dp[i][j] = Math.max(dp[i-1][j],dp[i-1][other_j] + h[i][j])

//0 --> 1
//1 --> 0