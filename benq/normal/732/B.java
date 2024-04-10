import java.util.*;
import java.lang.*;
import java.io.*;

public class Ideone {
	public static void main (String[] args) throws java.lang.Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int[] x = new int[n];
		int ans = 0;
		for (int i = 0; i < n; ++i) x[i] = in.nextInt();
		for (int i = 0; i < n-1; ++i) 
			while (x[i]+x[i+1]<k) {
				x[i+1]++;
				ans++;
			}
		System.out.println(ans);
		for (int i = 0; i < n; ++i) System.out.print(Integer.toString(x[i])+" ");
	}
}