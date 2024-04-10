#include<bits/stdc++.h>
using namespace std;
bool pri( int k)
{ if( k == 1) return false;
    for(int i = 2; i * i <= k; i++)
    {

        if( k % i == 0) return false;
    }
    return true;
}
 long gcd(long a, long b)
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
int main()
{

    long long n , a , b;
    cin >> n ;
    for(int i = 1; i <= 1000; i++)
    {

        if( !pri(i * n + 1))
            {
                cout << i;
return 0;
            }
    }
  //  long long x[n];
  //  int ans = 0;

}