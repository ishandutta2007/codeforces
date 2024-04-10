import java.io.*;
import java.util.*;
public class Main {
	public static void main (String... args) {
	   	int n = readInt(), m = readInt();
	   	int[][] a = new int[n+1][m+1];
	   	int[][] dp = new int[n+1][m+1], dp2 = new int[n+1][m+1], dp3 = new int[n+1][m+1], dp4 = new int[n+1][m+1];
	   	for (int i = 1; i <= n; i++) {
	   		for (int j = 1; j <= m; j++) {
	   			a[i][j] = readInt();
	   		}
	   	}
	   	dp[1][1] = a[1][1];
	   	for (int i = 1; i <= n; i++) {
	   		for (int j = 1; j <= m; j++) {
	   			if (i > 1) dp[i][j] = Math.max(dp[i][j],dp[i-1][j]+a[i][j]);
	   			if (j > 1) dp[i][j] = Math.max(dp[i][j],dp[i][j-1]+a[i][j]);
	   		}
	   	}
	   	dp2[n][1] = a[n][1];
	   	for (int i = n; i >= 1; i--) {
	   		for (int j = 1; j <= m; j++) {
	   			if (i < n) dp2[i][j] = Math.max(dp2[i][j],dp2[i+1][j] + a[i][j]);
	   			if (j > 1) dp2[i][j] = Math.max(dp2[i][j],dp2[i][j-1] + a[i][j]);
	   		}
	   	}
	   	dp4[1][m] = a[1][m];
	   	for (int i = 1; i <= n; i++) {
	   		for (int j = m; j >= 1; j--) {
	   			if (i > 1) dp4[i][j] = Math.max(dp4[i][j],dp4[i-1][j] + a[i][j]);
	   			if (j < m) dp4[i][j] = Math.max(dp4[i][j],dp4[i][j+1] + a[i][j]);
	   		}
	   	}
	   	dp3[n][m] = a[n][m];
	   	for (int i = n; i >= 1; i--) {
	   		for (int j = m; j >= 1; j--) {
	   			if (i < n) dp3[i][j] = Math.max(dp3[i][j],dp3[i+1][j]+a[i][j]);
	   			if (j < m) dp3[i][j] = Math.max(dp3[i][j],dp3[i][j+1]+a[i][j]);
	   		}
	   	}
	   	int answer = 0;
	   	for (int i = 2; i < n; i++) {
	   		for (int j = 2; j < m; j++) {
	   			answer = Math.max(answer,dp[i][j-1] + dp3[i][j+1] + dp2[i+1][j] + dp4[i-1][j]);
	   			answer = Math.max(answer,dp[i-1][j] + dp3[i+1][j] + dp2[i][j-1] + dp4[i][j+1]);
	   		}
	   	}
	   	System.out.println(answer);
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
//dp[i] = # of ways to say the first i letters
//dp[i] = dp[i-1]
//if (s[i] == s[i-1] == 'n' or 'u') dp[i] += dp[i-2]