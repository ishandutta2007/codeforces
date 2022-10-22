import java.util.*;
import java.io.*;
public class Main {
	public static void main (String[] args) {
		int n = readInt(), k = readInt();
		int[] h = new int[n];
		for (int i = 0; i < n; i++) h[i] = readInt();
		int sum = 0;
		for (int i = 0; i < k; i++) sum += h[i];
		int index = 0, best = sum;
		for (int i = 1; i + k - 1 < n; i++) {
			sum -= h[i-1];
			sum += h[i+k-1];
			if (sum < best) {
				best = sum;
				index = i;
			}
		}
		System.out.println(index+1);
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