import java.util.*;
import java.io.*;
public class Main {
	public static void main (String[] args) {
		int n = readInt(), answer = 0;
		int[] a = new int[]{100,20,10,5,1};
		for (int i : a) {
			int canTake = n / i;
			answer += canTake;
			n -= canTake * i;
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