// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
public class Main {
	public static void main (String[] args) throws java.lang.Exception {
		Scanner in = new Scanner(System.in);
		int s = in.nextInt();
		int v1 = in.nextInt();
		int v2 = in.nextInt();
		int t1 = in.nextInt();
		int t2 = in.nextInt();
		int a = 2*t1+v1*s;
		int b = 2*t2+v2*s;
		if (a < b) System.out.println("First");
		else if (a > b) System.out.println("Second");
		else System.out.println("Friendship");
	}
}