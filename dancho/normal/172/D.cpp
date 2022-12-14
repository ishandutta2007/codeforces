#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a, n;
bool us[10000020];
long long c[10000020];

int main()
{
	int i, j, k, mst;
	long long ans = 0;
	
	memset( us, 0, sizeof( us ) );
	
	for ( i = 1; i <= 10000000; i++ )
	{
		c[i] = 1;
	}
	
	for ( i = 2; i*i <= 10000000; i++ )
	{
		if ( us[i] == 0 )
		{
//			printf( "%d\n", i );
			for ( j = i; j <= 10000000; j=j+i )
			{
				us[j] = 1;
//				if ( ( j >= a ) && ( j <= a+n-1 ) )
				{
					k = j;
					mst = 0;
					while ( k % i == 0 )
					{
						mst++;
						if ( mst%2 == 0 )
							c[j] = c[j]*i*i;
						k = k / i;
					}
				}
			}
		}
	}
	
	scanf( "%d %d", &a, &n );
//	printf( "%d %d\n", a, n );
	
	for ( i = 1; i <= n; i++, a++ )
	{
		ans = ans + a/c[a];
	}
	
	cout << ans << endl;
	return 0;
}