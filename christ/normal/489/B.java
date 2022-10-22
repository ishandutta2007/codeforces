import java.util.*;
import java.io.*;
public class Main {
	public static void main (String[] args) {
		int n = readInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) a[i] = readInt();
		int m = readInt();
		int[] b = new int[m];
		for (int i = 0; i < m; i++) b[i] = readInt();
		Arrays.sort(a);
		Arrays.sort(b);
		boolean[] matched = new boolean[m];
		int answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!matched[j] && Math.abs(a[i] - b[j]) <= 1) {
					matched[j] = true;
					answer++;
					break;
				}
			}
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