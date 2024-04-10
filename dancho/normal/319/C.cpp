#include <cstdio>
#include <cstring>
#include <iostream>

int n;
int a[1<<20], b[1<<20];
long long dp[1<<20];

int deq[1<<20];
int beg, end;

long long eval( int x, int y )
{
	return dp[y] + (long long) a[x]*b[y];
}

int cross( int x, int y )
{
	int l, r, m;
	if ( eval( n, x ) <= eval( n, y ) )
		return n+1;
	l = y; r = n;
	while ( l+1 < r )
	{
		m = (l+r)/2;
		if ( eval( m, x ) > eval( m, y ) )
			r = m;
		else
			l = m;
	}
	return r;
}

int main()
{
	int i;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &b[i] );
	}
	
	dp[1] = 0;
	deq[1] = 1;
	beg = end = 1;
	
	for ( i = 2; i <= n; i++ )
	{
		while ( ( beg < end ) && ( eval( i, deq[beg] ) >= eval( i, deq[beg+1] ) ) )
			beg++;

		dp[i] = eval( i, deq[beg] );
		
		while ( ( beg < end ) && ( cross( deq[end], i ) <= cross( deq[end-1], deq[end] ) ) )
			end--;
		if ( cross( deq[end], i ) <= n )
		{
			deq[++end] = i;
		}
	}
	
	std::cout << dp[n] << "\n";
	return 0;
}