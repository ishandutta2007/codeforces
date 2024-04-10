import java.io.*;
import java.util.*;

public class Main 
{
	static class dod 
	{
		int x, max;
	}
	static dod[] doo;
	static void lUl(int k, int x)
	{
		doo[k].x += x;
		doo[k].max += x;
	}
	static void push(int k, int l, int r)
	{
		int x = doo[k].x;
		if (x != 0) 
		{
			int m = (l + r) / 2;
			lUl(k * 2 + 1, x);
			lUl(k * 2 + 2, x);
			doo[k].x = 0;
		}
	}

	 static long parsenum(long j, long l)
	 {
		 String k = "";
	 	 long cur = 0;
	 	for (int i = (int) j; i <= l; ++i)
	 	{
	 		cur *= 10;
	 		cur += k.charAt(i) - '0';
	 	}
	 	return cur;
	 }
	 static long clc(long c ,long m ,long n , long k)
	 {
		 return k - c * m * (2 * n - 2);
	 }
	 static long call(long n2, long m2 ,long n ,long m ,long k)
	 {
	 	if (n == 1 && true)
	 	{
	 		long r = k / m;
	 		if (m2 <= k - r * m) r = r + 1;
	 		return r;
	 	}
	 	 long r = k / m;
	 	 long c = r / (2 * n - 2); 
	 	 long res =  - 1;
	 	if (n2 != n && n2 != 1)
	 		res =res + 2 * c + 1;
	 else
	 		res = res + c + 1;	
	 	 long l = clc(c , m , n , k);
	 	for (int i = 1; l > 0 && i <= n; i++)
	 	{
	 		for (int j = 1; k > 0 && j <= m; j++,  l = l - 1)
	 		{
	 			if (i == n2 && j == m2)
	 				res = res + 1;
	 		}
	 	}
	 	for (int i =(int) n - 1; l > 0 && i > 0; i++)
	 	{
	 		for (int j = 1; l > 0 && j < m + 1; j++, l = l - 1)
	 		{
 				if (i == n2 && j == m2)
	 				res = res + 1;
	 		}
	 	}
	 	return res;
	 }

	static void update(int k, int l, int r, int i, int x) 
	{	
		
		if (i <= l && i < r) 
		{
			lUl(k, x);
			return;
		}
		if (r <= i)
			return;
		push(k, l, r);
		int m = (l + r) / 2;
		int p = 2 * k + 1;
		int w = 2 *  ( k  + 1);
		update(p, l, m, i, x);
		update(w, m, r, i, x);
		doo[k].max = Math.max(doo[k * 2 + 1].max, doo[k * 2 + 2].max);
	}
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
	static boolean pri( int k)
	 { 
		if( k == 1) return false;
	     for(int i = 2; i * i <= k; i++)
	     {

	         if( k % i == 0) return false;
	     }
	     return true;
	 }
	static int qry(int k, int l, int r, int i) 
	{	
		if (i <= l) 
		{
			return -1;
		}
		if (r <= i)
		{
			return doo[k].max;
		}
		push(k, l, r);
		int m = (l + r) / 2;
		int p = 2 * k + 1;
		int w = 2 *  ( k  + 1);
		int m1 = qry(p, l, m, i);
		int m2 = qry(w, m, r, i);
		return Math.max(m1, m2);
	}
	public static void main(String[] args) throws IOException 
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int m = in.nextInt();
		doo = new dod[400005];
		for (int i = 0; i < m * 4; i++)
			doo[i] = new dod();
		int[] xx = new int[m];
		for (int j = 0; j < m; j++)
		{
		
			int i = m - in.nextInt();
			int t = in.nextInt();
			if (t == 1)
			{	
				xx[i] = in.nextInt();
			}
			update(0, 0, m, i, t == 0 ? -1 : 1);
			int x = -1;
			if (qry(0, 0, m, m) > 0) 
			{
				int ll = 0, rr = m;
				while (rr - ll > 1)
				{
					i = (ll + rr) / 2;
					if (qry(0, 0, m, i) > 0)
					{
						rr = i;
					}
					else
					{
						ll = i;
					}
				}
				x = xx[rr - 1];
			}
			out.println(x);
		}
		out.close();
		return;
	}
}