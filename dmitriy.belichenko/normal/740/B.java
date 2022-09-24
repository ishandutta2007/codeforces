import java.util.*;
import java.io.*;
import java.math.*;
public class Main {


	public static void main(String[] args)
	{
		String s;
		Scanner in = new Scanner(System.in);

			   int n, m;
			   n = in.nextInt();
			   m = in.nextInt();
			 int a[] = new int[n];
			 int dp[] = new int[m];
			 int c = 0;
			for(int i = 0; i < n; i++) 
			{
				 a[i] = in.nextInt();
			}      
			for(int i = 0; i < m; i++) 
			{
				c = 0;
			    int l;
			    l = in.nextInt();
			    int r;
			    r = in.nextInt();
			   l = l -1;
			   r = r - 1;
			   
			   for(int j = l; j <= r; j++) {
			      c = c + a[j];
			   }
			   dp[i] = c;
			}
			long res = 0;
			for(int i = 0; i < m; i++) 
			{
			      if(dp[i] >= 1) 
			      {
			            res += dp[i];
			      }
			}
			System.out.println(res);
			 
			}
	}