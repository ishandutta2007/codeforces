import java.io.*;
import java.util.*;
public class Main {
	static final int MOD = 1_000_000_007;
	public static void main (String... args) {
	   	String s = read();
	   	long answer = 0;
	   	for (int i = 0; i < s.length(); i++) {
	   		int value = Integer.parseInt(""+s.charAt(i));
	   		if (value % 4 == 0) answer++;
	   	}
	   	for (int i = 0; i + 1 < s.length(); i++) {
	   		int value = Integer.parseInt(s.substring(i,i+2));
	   		if (value % 4 == 0) answer += i + 1;
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