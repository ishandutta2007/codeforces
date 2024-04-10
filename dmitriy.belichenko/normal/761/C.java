import java.io.*;
import java.util.*;
import java.math.*;
import java.util.concurrent.ThreadLocalRandom;
public class Main 
{

 static long N = 100;
 static long CNT = 62;
 static long  INF = 1 << 62;




	
	
    static void merge(long u, long v) 
    {
		 long pr[] = new long[50005];
		 long si[] = new  long[50005];
    	u = get(u);
    	v = get(v);
    	if (si[(int)v] > si[(int)u])
    	{
    		long k = v;
    		v = u;
    		u = k;
    	}
    	pr[(int)v] = u;
    	si[(int)u] += si[(int)v];
    }
	  static long get(long u) {
		  long pr[] = new long[50005];
			 long si[] = new  long[50005];
	      	if(pr[(int)u] == u) return  u;
	      	else return pr[(int)u] = get(pr[(int)u]);
	      }
	 static void init()
	 {
		 long pr[] = new long[50005];
	 long si[] = new  long[50005];
		 
	 int n = 5;
	      	for (int i = 0; i <= n; i++)
	      	{
	      		pr[i] = i;
	      		si[i] = 1;
	      	}
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

	// static String k;


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
	
	static boolean check(long x)
	 {
		long rr = 0;
		 long ll = 0;
		long m = 0, k;
	 	 long lt = summall(x - 1, ll);
	 	 long rt = summall(x - 1, rr);
	 	if (lt + rt + x <= m)
	 		return true;
	 	return false;
	 }
	static long summall(long  s,  long u)
	 {
	 	if (u == 0)
	 		return 0;
	 	if (u > s)
	 		return summall(s, s);
	 	return (2 * s - u + 1) * u / 2;
	 }
     static long bsearch(int i ,int cnt)
     { long t[] = new long[100];
    	 int mid;
    	 int l =  -1;
    	 int r = i;
    	  while (r-l > 1)
	        {
	            mid = (l+r)/2;
	            if (t[i]-t[mid] < cnt) r = mid;
	            else                l = mid;
	        }
			
    	 return r;
     }
   static  int n;
 
  
	 static void input()
	 { 
		 
		 Scanner in = new Scanner(System.in);
		 n = in.nextInt();
		  for(int i = 1; i <= n; i++);
//		  for(int i = 0; i < n; i++)
//		  {
//			  b[i] = in.nextInt();
//			  p[i] = p[i] - 1;
//		  }
	 }
	 static void count(int i , int c , int r)
	 {
		 long dp[] = new long[100];
	      if( r == 0)
	      {
	    	  if(dp[i] > c ) dp[i] = c; 
	    	

	      }
	      else
	        if (dp[i] >  dp[(int)(r-1)] + c)
	        {
	        	
	        	 dp[i] = dp[(int)(r-1)] + c ;
	        }
	 }
	 static void ddo( int i , int n , int m )
	 {
		    dist[i][0] = 0;
	   		dist[i][1] = m + 1;
	   		dist[i][2] = m + 1;
	   		dist[i][4] = m + 1;
	   		dist[i][3] = n * m;
	   		dist[i][5] = n * m;
	   		dist[i][6] = n * m;
	   		dist[i][7] = n * m;
	 }
	static boolean cc1(int i ,int j , int calc)
	 {
		
		if (s[i].charAt(j) >= 'a' && s[i].charAt(j) <= 'z')
				dist[i][1] = Math.min(dist[i][1], calc);
		if (s[i].charAt(j) >= 'a' && s[i].charAt(j) <= 'z') return true;
		else return false;
	 }
	
	static boolean cc2(int i ,int j , int calc)
	 {
		
		if (s[i].charAt(j) >= '0' && s[i].charAt(j) <= '9')
				dist[i][2] = Math.min(dist[i][2], calc);
		if (s[i].charAt(j) >= '0' && s[i].charAt(j) <= '9') return true;
		else return false;
	 }
	
	 static String[] s = new String[51];
	 static int dp[][] = new int[55][8]; //[had][num/char/special]
	 static int dist[][] = new int[51][8];
	public static void main(String[] args) throws Exception
	{
		int mon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		 Scanner in = new Scanner(System.in);
		   PrintWriter out = new PrintWriter(System.out);
		  
		 
		   	int n, m;
		   n = in.nextInt();
		   m = in.nextInt();
		   	for (int i = 0; i < n; ++i)
		   		s[i] = in.next();
		   	for (int i = 0; i < n; ++i)
		   	{
		   		ddo(i , n , m  );

		   		for (int j = 0; j < m; ++j)
		   		{
		   			int calc = Math.min(j, m - j);
		   			if (s[i].charAt(j) >= '0' && s[i].charAt(j) <= '9')
						dist[i][2] = Math.min(dist[i][2], calc);
		   			else
		   				if (s[i].charAt(j) >= 'a' && s[i].charAt(j) <= 'z')
		   					dist[i][1] = Math.min(dist[i][1], calc);
		   			else
		   				if (s[i].charAt(j) == '#' ||s[i].charAt(j) == '*' || s[i].charAt(j) == '&')
		   				dist[i][4] = Math.min(dist[i][4], calc);
		   		}
		   	}
		   	for (int i = 0; i <= n; i++)
		   		for (int j = 0; j < 8; j++)
		   			dp[i][j] = 1 << 20;
		   	dp[0][0] = 0;
		   	for (int i = 0; i < n; ++i)
		   		for (int j = 0; j < 8; j++)
		   			for (int z = 0; z < 8; ++z)
		   			{
		   				int to = j | z;
		   				dp[i + 1][to] = Math.min(dp[i + 1][to], dp[i][j] + dist[i][z]);
		   			}
		   	out.println( dp[n][7]);
		   	
		   out.close();
			return ;
		    
		
		
		
	}
 

}