import java.io.*;
import java.util.*;
public class Main {
	public static void main (String... args) {
	   	String s = read();
	   	int n = s.length();
	   	s = '#' + s;
	   	long[][] dp = new long[n+1][3];
	   	for (int i = 1; i <= n; i++) {
	   		for (int j = 0; j < 3; j++) dp[i][j] = dp[i-1][j];
	   		if (s.charAt(i) == 'o') {
	   			dp[i][1] += dp[i-1][0];
	   		} else if (s.charAt(i) == 'v' && s.charAt(i-1) == 'v') {
	   			dp[i][0]++;
	   			dp[i][2] += dp[i-2][1];
	   		}
	   	}
	   	System.out.println(dp[n][2]);
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