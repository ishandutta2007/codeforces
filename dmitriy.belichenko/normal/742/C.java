import java.io.*;
import java.util.*;
import java.math.*;
public class Main 
{

	static long nod(long a, long b) 
	{
		if (b == 0)
		{	
			return a;
		}
		
		else
			{
			 return nod(b, a % b);
			}
	}
	static long nok(long a, long b) 
	{
		long res = a*b / nod(a, b);
		return res;
	}
	public static void main(String[] args) throws Exception
	{
		long ans = 0;

		// TODO Auto-generated method stub
//		 Scanner in = new Scanner(new File("records.in"));
//		    PrintWriter out = new PrintWriter(new File("records.out"));
//			// TODO Auto-generated method stub
		   PrintWriter out = new PrintWriter(System.out);
		   Scanner in = new Scanner(System.in);
		   long n = in.nextInt();
		   
		  
		   long dl[] = new long[110];
		  
		   long a[] = new long[110];
			for (int i = 1; i < n + 1; i++)
			{
				 a[i] = in.nextInt();
			}
			int t;
			 boolean used[] = new boolean[110];
			   
			for (int u = 1; u <= n; u++) 
			{
				for(int i = 0; i < 110; i++)
				{
					used[i] = false;
				}
				t = u;
				do 
				{
					used[t] = true;
					t =(int) a[t];
					dl[u] = dl[u] + 1;
				} 
				while (!used[t]);
				
				if (t > u || t < u || t==0) 
				{
					int p[] = new int[(int)n];
					
					System.out.println(-1);
					return;
				}
				if (dl[u] % 2 == 0)
					{
					dl[u] =dl[u]/ 2;
					}
			}
			if(true) ans = dl[1];
			for(int i = 2; i < 100; i++)
				for(int j = 2; j < 100; j++)
				{
					long e;
					e =nok(i , j);
					//System.out.println();
				}
			
			for (int i = 2; i <= n - 1; i++)
			{
				ans = nok(ans, dl[i]);
			}
			
			System.out.println(ans);
		}
	}