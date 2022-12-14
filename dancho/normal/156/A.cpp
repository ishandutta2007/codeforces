#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;
char s[1000000], u[1000000];

int ia( int x )
{
	if ( x < 0 ) return -x;
	return x;
}

int main()
{
	int i, j, k;
	int mi = (1<<29);
	
	scanf( "%s", s );
	scanf( "%s", u );
	n = strlen( s );
	m = strlen( u );
	
	for ( j = -max(n,m); j < max(n,m); j++ )
	{
		k = 0;
		if ( j < 0 ) k = k -j;
		if ( m+j-1 > n-1 ) k = k - (n-1-m-j+1);
		for ( i = max( 0, -j ); i < m && i+j < n; i++ )
		{
			if ( i+j < 0 || i+j >= n || i < 0 || i >= m )
			{
				k = (1<<29);
				break;
			}
			if ( s[i+j] != u[i] ) k++;
		}
		if ( k < mi ) mi = k;
//		printf( "%d %d\n", j, k );
	}
	printf( "%d\n", mi );
	return 0;
}