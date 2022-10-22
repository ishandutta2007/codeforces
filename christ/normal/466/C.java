import java.util.*;
import java.io.*;
public class Main {
	public static void main (String[] args) {
		int n = readInt();
		int[] a = new int[n];
		long[] psa = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = readInt();
			if (i == 0) psa[i] = a[i];
			else psa[i] = psa[i-1] + a[i];
		}
		TreeMap<Long,Integer> mp = new TreeMap<>();
		long answer = 0;
		for (int i = 0; i + 1 < n; i++) {
			int have;
			if (psa[i] % 2 == 1) have = 0;
			else have = mp.getOrDefault(psa[i]/2,0);
			if (psa[i] % 2 == 0 && psa[n-1] - psa[i] == psa[i] / 2) {
				answer += have; 
			}
			mp.put(psa[i],mp.getOrDefault(psa[i],0) + 1);
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
//psa[n] - psa[i] = psa[i]
//psa[n] = psa[i] * 2
//psa[i] = psa[n] / 2

//for each i, find # of j < i s.t. psa[j] * 2 = psa[i]