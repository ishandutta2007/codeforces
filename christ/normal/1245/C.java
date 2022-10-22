import java.io.*;
import java.util.*;
public class Main {
	static final int MOD = 1_000_000_007;
	public static void main (String... args) {
	   	String s = read();
	   	int n = s.length();
	   	s = '#' + s;
	   	for (int i = 1; i <= n; i++) {
	   		if (s.charAt(i) == 'm' || s.charAt(i) == 'w') {
	   			System.out.println(0);
	   			return;
	   		}
	   	}
	   	int[] dp = new int[n+1];
	   	dp[0] = 1;
	   	for (int i = 1; i <= n; i++) {
	   		dp[i] = dp[i-1];
	   		if (s.charAt(i) == s.charAt(i-1) && (s.charAt(i) == 'n' || s.charAt(i) == 'u')) {
	   			dp[i] = (dp[i] + dp[i-2]) % MOD;
	   		}
	   	}
	   	System.out.println(dp[n]);
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