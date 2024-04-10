import java.util.*;
import java.lang.*;
import java.io.*;

public class Ideone { // add public
	public static void main (String[] args) throws java.lang.Exception {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a = 0, b = 0;
		for (int i = 1; i <= n; ++i) {
			if (i > n/i) break;
			if (n % i != 0) continue;
			a = i; b = n/i;
		}
		System.out.println(a+" "+b);
	}
}