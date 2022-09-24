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
	static long n;
	 static long p[] = new long[50005];
	 static long si[] = new  long[50005];
    static void merge(long u, long v) 
    {
    	u = get(u);
    	v = get(v);
    	if (si[(int)v] > si[(int)u])
    	{
    		long k = v;
    		v = u;
    		u = k;
    	}
    	p[(int)v] = u;
    	si[(int)u] += si[(int)v];
    }
	  static long get(long u) {
	      	if(p[(int)u] == u) return  u;
	      	else return p[(int)u] = get(p[(int)u]);
	      }
	 static void init()
	 {
	      	for (int i = 0; i <= n; i++)
	      	{
	      		p[i] = i;
	      		si[i] = 1;
	      	}
	 }
	public static void main(String[] args) throws Exception
	{

		
		   PrintWriter out = new PrintWriter(System.out);
		   Scanner in = new Scanner(System.in);
		 // long n , k , q;
		    n = in.nextInt();
      // s;
     long ans = 0;

      	init();
      	int k;
      	for (int i = 1; i <= n; i++)
      	{
      		k = in.nextInt();
      		merge(i, k );
      	}
      	TreeSet<Long> s = new TreeSet<Long>();
      	for (int i = 1; i <= n; i++) s.add(get(i));
      	ans = s.size();
      	out.println(ans);
      	 out.close();
      }
      
	  
	}