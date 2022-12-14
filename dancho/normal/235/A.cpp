#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long gcd( long long a, long long b )
{
	if ( b == 0 ) return a;
	return gcd( b, a%b );
}

long long lcm( long long a, long long b )
{
	return a*b/gcd(a,b);
}

long long lcm( long long a, long long b, long long c )
{
	return lcm( a, lcm( b, c ) );
}

long long n, ans;

int main()
{
	int i, j, k;
	
	cin >> n;
	ans = n;
	if ( n*(n-1) > ans ) ans = n*(n-1);
	if ( n % 2 == 1 )
	{
		if ( n*(n-1)*(n-2) > ans )
			ans = n*(n-1)*(n-2);
	}
	
	for ( i = 0; i <= 60; i++ )
	{
		for ( j = 0; j <= 70; j++ )
		{
			for ( k = 0; k <= 80; k++ )
			{
				if ( n-i > 0 && n-j > 0 && n-k > 0 )
				{
					if ( lcm( n-i, n-j, n-k ) > ans )
					{
						ans = lcm( n-i, n-j, n-k );
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}