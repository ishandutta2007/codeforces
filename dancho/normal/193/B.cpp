#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, u, r;

long long a[64], b[64], k[64], p[64];

long long solve( long long x[], int mv )
{
	if ( mv < 0 ) return (-1LL<<62);
	if ( mv == 0 )
	{
		long long sol = 0;
		for ( int i = 1; i <= n; i++ )
		{
			sol = sol + x[i]*k[i];
		}
		return sol;
	}
	long long sol = 0;
	long long y[32], z[32];
	int i;

	for ( i = 1; i <= n; i++ )
	{
		y[i] = x[i]^b[i];
	}
	
	if ( mv%2 == 1 )
	{
		for ( i = 1; i <= n; i++ )
		{
			sol = sol + y[i]*k[i];
		}
	}
	else
	{
		for ( i = 1; i <= n; i++ )
		{
			sol = sol + x[i]*k[i];
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		z[i] = x[p[i]]+r;
	}
	sol = max( sol, solve( z, mv-1 ) );

	for ( i = 1; i <= n; i++ )
	{
		z[i] = y[p[i]]+r;
	}
	sol = max( sol, solve( z, mv-2 ) );
	return sol;
}

int main()
{
	int i;
	cin >> n >> u >> r;

	for ( i = 1; i <= n; i++ )
		cin >> a[i];
	for ( i = 1; i <= n; i++ )
		cin >> b[i];
	for ( i = 1; i <= n; i++ )
		cin >> k[i];
	for ( i = 1; i <= n; i++ )
		cin >> p[i];
	
	cout << solve( a, u ) << '\n';
	return 0;
}