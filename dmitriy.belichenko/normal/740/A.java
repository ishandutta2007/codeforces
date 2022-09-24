import java.util.*;
import java.io.*;
import java.math.*;
public class Main {


	public static void main(String[] args)
	{
		String s;
		Scanner in = new Scanner(System.in);
		long n , a , b , c;
		 long res = 0;
		  long ans = Long.MAX_VALUE;
			  n = in.nextLong();
			  a = in.nextLong();
			  b = in.nextLong();
			  c = in.nextLong();
			  long q[] = new long[100];
			  q[1] = a;
			  q[2] = b;
			  q[3]= c;
			  long k = n % 4;
			  long  arr[] = new long[100005];
			  for(int i = 0; i < 100000; i++) arr[i] = Long.MAX_VALUE;
			      arr[1] = a;
			      arr[2] = Math.min( b, 2 * a);
			      arr[3] = Math.min( Math.min(a + b, c), a* 3);
			   for(int i = 4; i <= 100; i++) 
			   {
				  for(int j = 1; j <=3 ; j++) arr[i] = Math.min(arr[i - j] + q[j], arr[i]);
			   }
			   if( k == 0) {
				   res = 0;
				   System.out.print(res);
			      return ;
	   }
		
		
			  res = ans;
			for(int i = 0; i < 10000; i++) 
			{
			       if( (i + n  % 4) % 4 ==0) 
			       {
			                 
			             res = Math.min(res, arr[i]);
			             
			             }
			         }
			System.out.print(res);
			 
			
			
	}
}