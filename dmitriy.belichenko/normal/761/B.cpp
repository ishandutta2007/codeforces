#include<string>
#include<iostream>
#include<vector>
using namespace std;
 static long N = 100;
 static long CNT = 62;





 static long get(long u) {
		  long pr[50005];
			 long si[50005];
	      	if(pr[(int)u] == u) return  u;
	      	else return pr[(int)u] = get(pr[(int)u]);
	      }

    static void merge(long u, long v)
    {
		 long pr[50005];
		 long si[50005];
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

	 static void init()
	 {
		 long pr[50005];
	 long si[50005];

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
	static bool pri( int k)
	 {
		if( k == 1) return false;
	     for(int i = 2; i * i <= k; i++)
	     {

	         if( k % i == 0) return false;
	     }
	     return true;
	 }
static long summall(long  s,  long u)
	 {
	 	if (u == 0)
	 		return 0;
	 	if (u > s)
	 		return summall(s, s);
	 	return (2 * s - u + 1) * u / 2;
	 }
	static bool check(long x)
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

     static long bsearch(int i ,int cnt)
     { long t[100];
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

		// Scanner in = new Scanner(System.in);
		// n = in.nextInt();
		  for(int i = 1; i <= n; i++);
//		  for(int i = 0; i < n; i++)
//		  {
//			  b[i] = in.nextInt();
//			  p[i] = p[i] - 1;
//		  }
	 }
	 static void count(int i , int c , int r)
	 {
		 long dp[100];
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
	    vector <int> f, s;
  int one(int lt , int n )
  {

    for (int i = 1; i < n; i++)
	{
		int x;
		cin >> x;
		int del = x - lt;
		f.push_back(x - lt);
		lt = x;
	}
   return lt;
  }
   int two(int lt , int n )
  {

   for (int i = 1; i < n; i++)
	{
		int x;
		cin >> x;
        int del = x - lt;
		s.push_back(del);
		lt = x;
	}
   return lt;
  }
  bool chekk(int n )
  {
      for (int i = 0; i < n; i++)
	{
		bool flag = 0;
		for (int j = 0; j < n; j++)
			if (f[j] != s[(i + j) % n])
			{
				flag = 1;
				break;
			}
		if (flag == 0)
		{
			cout << "YES";
			return 1;
		}
	}
	return 0;
  }
	 int main()
    {

	int n, l;
	cin >> n >> l;
	int lt;
	int ss;
	cin >> ss;
	lt = one(ss , n );
	int u = l + ss - lt;
	f.push_back(u);
	cin >> ss;
	lt = ss;
	lt = two(ss , n);
	 u = l + ss - lt;
	s.push_back(u);
	bool flag = chekk(n);
	if( ! flag)
	cout << "NO" << endl;
	return 0;
}