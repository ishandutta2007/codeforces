import java.io.*;
import java.util.*;
import java.math.*;
import java.util.concurrent.ThreadLocalRandom;
public class Main 
{
	
	static long gcd(long a, long b) 
	{
		if (b == 0)
		{	
			return a;
		}
		
		else
		{
			 return gcd(b, a % b);
		}
	}
	public static void main(String[] args) throws Exception
	{

		
		   PrintWriter out = new PrintWriter(System.out);
		   Scanner in = new Scanner(System.in);
		 // long n , k , q;
		  
		int a , b , c;
	    a = in.nextInt();
	    b = in.nextInt();
	    c = in.nextInt();
	    int k = b/2;
	    int u = c/4;
	   int ans = Math.min(a, Math.min(k, u));
	   System.out.print(ans * 7);
	}
}