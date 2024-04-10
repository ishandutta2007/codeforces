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
		  
		int n;
		n = in.nextInt();
	   String s;
	 String ans = "";
	   s = in.next();
	 //  System.out.println(s);
	   if( n % 2 == 0)
	   for(int i = 0 ;i < n; i++)
	   {
		if( i % 2 == 0) ans = ans + s.charAt(i);
		else ans = s.charAt(i) + ans;
		
	   }
	   if( n % 2 != 0)
		   for(int i = 0 ;i < n; i++)
		   {
			if( i % 2 != 0) ans = ans + s.charAt(i);
			else ans = s.charAt(i) + ans;
			
		   }
	  // for(int i = 0; i  < n; i++)
	  for(int i = n-1 ; i >= 0; i--)System.out.print(ans.charAt(i));
	   
	}
}