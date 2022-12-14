#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[32];

int t[4][4];

bool cmag()
{
	int i, j, k, s;
			s = 0;
			for ( i = 0; i < n; i++ )
				s = s + t[0][i];
			
			for ( i = 0; i < n; i++ )
			{
				k = 0;
				for ( j = 0; j < n; j++ )
					k = k + t[i][j];
				
				if ( k != s ) return 0;
				
				k = 0;
				for ( j = 0; j < n; j++ )
				{
					k = k + t[j][i];
				}
				if ( k != s ) return 0;
			}
	
	k = 0;
	for ( i = 0; i < n; i++ )
	{
		k = k + t[i][i];
	}
	if ( k != s ) return 0;
	
	 k = 0;
	for ( i = 0; i < n; i++ )
	{
		k = k + t[i][n-i-1];
	}
	if ( k != s ) return 0;
	
//	printf( "%d\n", s );
	return 1;
}

int main()
{
	int i, j;
	int s;
	
	scanf( "%d", &n );
	for ( i = 0; i < n*n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	
	if ( n <= 3 )
	{
		sort( a, a + n*n );
		do
		{
			for ( i = 0; i < n; i++ )
			{
				for ( j = 0; j < n; j++ )
				{
					t[i][j] = a[ n*i + j ];
				}
			}
			
			if ( cmag() ) break;
		}
		while ( next_permutation( a, a + n*n ) );
	}
	else
	{
	}

			s = 0;
			for ( i = 0; i < n; i++ )
				s = s + t[0][i];
		
	printf( "%d\n", s );
	for ( i = 0; i < n; i++ )
	{
		printf( "%d", t[i][0] );
		for ( j = 1; j < n; j++ )
			printf( " %d", t[i][j] );
		printf( "\n" );
	}
	return 0;
}