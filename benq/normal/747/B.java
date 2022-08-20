import java.util.*;
import java.lang.*;
import java.io.*;

public class Ideone { // add public
	public static void main (String[] args) throws java.lang.Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String x = in.next();
		char[] s = new char[n];
		for(int i = 0; i < n; ++i) s[i] = x.charAt(i); 
		if (n % 4 != 0) {
			System.out.println("===");
			System.exit(0);
		} else {
			int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
			for (int i = 0; i < n; ++i) {
				if (s[i] == 'A') c1++;
				else if (s[i] == 'C') c2++;
				else if (s[i] == 'G') c3++;
				else if (s[i] == 'T') c4++;
				else c5++;
			}
			if (c1>n/4 || c2>n/4 || c3>n/4 || c4>n/4) {
				System.out.println("===");
				System.exit(0);
			}
			if (c1 == n/4 && c2 == n/4 && c3 == n/4 && c4 == n/4) {
				for (int i = 0; i < n; ++i) System.out.print(s[i]);
				System.exit(0);
			}
			int[] ar = new int[c5];
			int z = 0;
			for (int i = 0; i < n; ++i) if (s[i] == '?') ar[z++] = i;
			z = 0;
			while (c1<n/4) {
				s[ar[z++]] = 'A';
				c1++;
			}
			while (c2<n/4) {
				s[ar[z++]] = 'C';
				c2++;
			}
			while (c3<n/4) {
				s[ar[z++]] = 'G';
				c3++;
			}
			while (c4<n/4) {
				s[ar[z++]] = 'T';
				c4++;
			}
			for (int i = 0; i < n; ++i) System.out.print(s[i]);
		}
	}
}