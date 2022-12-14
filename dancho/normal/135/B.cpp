#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
	long long x, y;
	bool operator<( const point& p ) const
	{
		if ( x == p.x ) return y < p.y;
		return x < p.x;
	}
};

long long dist( point a, point b )
{
	return ( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

long long ang( point a, point b, point c )
{
	return ( (a.x-b.x)*(c.x-b.x) + (a.y-b.y)*(c.y-b.y) );
}

bool isPr( point p[4] )
{
	int i;
	for ( i = 0; i < 4; i++ )
	{
		if ( ang( p[(i+3)%4], p[i], p[(i+1)%4] ) != 0 )
			return 0;
	}
	return 1;
}

bool isPrno( point p[4] )
{
	sort( p, p + 4 );
	do
	{
		if ( isPr( p ) ) return 1;
	}
	while( next_permutation( p, p + 4 ) );
	return 0;
}

bool isSq( point p[4] )
{
	if ( isPr( p ) == 0 ) return 0;
	int i;
	long long d = dist( p[0], p[1] );
	for ( i = 0; i < 4; i++ )
	{
		if ( dist( p[i], p[(i+1)%4] ) != d )
			return 0;
	}
	return 1;
}

bool isSqno( point p[4] )
{
	sort( p, p + 4 );
	do
	{
		if ( isSq( p ) ) return 1;
	}
	while( next_permutation( p, p + 4 ) );
	return 0;
}

int main()
{
	int i, j, k, l;
	point P[16], p[4], q[4];
	for ( i = 0; i < 8; i++ )
	{
		cin >> P[i].x >> P[i].y;
	}
	
	for ( k = 0; k < (1<<8); k++ )
	{
		j = k; i = 0;
		while ( j > 0 )
		{
			if ( j & 1 ) i++;
			j = j / 2;
		}
		if ( i != 4 ) continue;
		j = 0; l = 0;
		for ( i = 0; i < 8; i++ )
		{
			if ( k&(1<<i) )
				p[j++] = P[i];
			else
				q[l++] = P[i];
		}
		if ( ( isSqno( p ) ) && ( isPrno( q ) ) )
		{
			printf( "YES\n" );
			j = 0; l = 0;
			for ( i = 0; i < 8; i++ )
			{
				if ( k&(1<<i) )
				{
					j++;
					if ( j == 4 )
						printf( "%d\n", i+1 );
					else
						printf( "%d ", i+1 );
				}
			}
			for ( i = 0; i < 8; i++ )
			{
				if ( (k&(1<<i)) == 0 )
				{
					l++;
					if ( l == 4 )
						printf( "%d\n", i+1 );
					else
						printf( "%d ", i+1 );
				}
			}
			return 0;
		}
	}
	
	printf( "NO\n" );
	return 0;
}