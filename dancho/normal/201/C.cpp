#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int a[100020];

long long dprn[100020], dprr[100020];
long long dpln[100020], dplr[100020];

int main()
{
	int i;
	
	scanf( "%d", &n );
	for ( i = 1; i < n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	
	dpln[1] = 0;
	dplr[1] = 0;
	for ( i = 2; i <= n; i++ )
	{
		if ( a[i-1] % 2 == 0 )
		{
			dplr[i] = dplr[i-1] + a[i-1];
			dpln[i] = max( dpln[i-1] + a[i-1]-1, dplr[i-1] + a[i-1] );
		}
		else
		{
			if ( a[i-1] > 1 )
				dplr[i] = dplr[i-1] + a[i-1] - 1;
			else dplr[i] = -(1LL<<62);
			
			dpln[i] = max( dpln[i-1] + a[i-1], dplr[i] );
		}
		dplr[i] = max( dplr[i], 0LL );
	}

	dprn[n] = 0;
	dprr[n] = 0;
	for ( i = n-1; i > 0; i-- )
	{
		if ( a[i] % 2 == 0 )
		{
			dprr[i] = dprr[i+1] + a[i];
			dprn[i] = max( dprn[i+1] + a[i]-1, dprr[i+1] + a[i] );
		}
		else
		{
			if ( a[i] > 1 )
				dprr[i] = dprr[i+1] + a[i] - 1;
			else dprr[i] = -(1LL<<62);
			
			dprn[i] = max( dprn[i+1] + a[i], dprr[i] );
		}
		dprr[i] = max( dprr[i], 0LL );
	}
	
	long long ans = 0;
	for ( i = 1; i <= n; i++ )
	{
		ans = max( ans, dplr[i] + dprn[i] );
		ans = max( ans, dpln[i] + dprr[i] );
	}
	
	cout << ans << endl;
	return 0;
}