// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
public class Main {
	public static void main (String[] args) throws java.lang.Exception {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt(); int sum = 0; 
		int ans = 0;
		String s = in.next();
		int[] arr = new int[10];
		
		for (int i = 0; i < s.length(); ++i) {
		    int t = Character.getNumericValue(s.charAt(i));
		    arr[t] ++;
		    sum += t;
		}
		while (sum<k) {
		    for (int i = 0; i < 10; ++i) if (arr[i] > 0) {
		        ans ++;
		        sum += (9-i);
		        arr[i] --;
		        break;
		    }
		}
		System.out.println(ans);
	}
}