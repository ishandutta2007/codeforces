import java.util.*;
import java.io.*;
public class Main {
	public static void main (String[] args) {
		int n = readInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) a[i] = readInt();
		int[] b = new int[n];
		b[0] = 1;
		int answer = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] >= a[i-1]) b[i] = b[i-1] + 1;
			else b[i] = 1;
			answer = Math.max(answer,b[i]);
		}
		System.out.println(answer);
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
//dp[l][r] = maximum score of the player who goes first on x[l..r]
//dp[l][r] = max(sum(l+1..r) - dp[l+1][r] + x[l],sum(l..r-1) - dp[l][r-1] + x[r])