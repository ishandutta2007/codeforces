import java.io.*;
import java.util.*;
public class Main {
	static boolean solve (String s) {
		int pos = -1;
		for (int i = 0; i + 1 < s.length(); i++) {
			if (s.charAt(i) == 'A' && s.charAt(i+1) == 'B') {
				pos = i;
				break;
			}
		}
		if (pos == -1) return false;
		for (int i = pos + 2; i + 1 < s.length(); i++) {
			if (s.charAt(i) == 'B' && s.charAt(i+1) == 'A') {
				return true;
			}
		}
		return false;
	}
	public static void main (String... args) {
	   	String s = read();
	   	if (solve(s)) System.out.println("YES");
	   	else {
	   		StringBuilder sb = new StringBuilder();
	   		for (int i = 0; i < s.length(); i++) {
	   			if (s.charAt(i) == 'A') sb.append('B');
	   			else if (s.charAt(i) == 'B') sb.append('A');
	   			else sb.append(s.charAt(i));
 	   		}
	   		if (solve(sb.toString())) System.out.println("YES");
	   		else System.out.println("NO");
	   	}
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