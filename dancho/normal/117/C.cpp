#include <cstdio>
#include <cstring>

int n;
long long A[5020][100];
long long B[5020][100];

int main()
{
	int i, j, k;
	int q, r;
	char x[5020];
	long long a;
	
	memset( A, 0, sizeof( A ) );
	memset( B, 0, sizeof( B ) );
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%s", x );
		for ( j = 0; j < n; j++ )
		{
			k = j % 62;
			if ( x[j] == '1' )
			{
				A[i][j/62] |= (1LL<<k);
			}
			else if ( ( x[j] == '0' ) && ( j+1 != i ) )
			{
//				printf( "SET %d %d\n", i, j+1 );
				B[i][j/62] |= (1LL<<k);
			}
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		for ( k = 1; k <= n; k++ )
		{
			if ( i == k ) continue;
			//check k -> i;
			j = i-1;
			q = j/62;
			r = j%62;
			if ( A[k][q]&(1LL<<r) )
			{
//				printf( "ED %d %d __ %lld %lld\n", k, i, A[i][0], B[k][0] );
				for ( j = 0; j < 83; j++ )
				{
					if ( A[i][j] & B[k][j] )
					{
//						a = (A[i][j]&B[k][j]);
//						if ( ( a != (1LL<<((k-1)%62)) ) || ( j != (k-1)/62 ) )
							break;
					}
				}
				if ( j < 83 )
				{
					a = ( A[i][j] & B[k][j] );
//					printf( "%lld\n", a );
					for ( r = 0; r < 62; r++ )
					{
//						if ( j == (k-1)/62 )
						//{
//							if ( r == (k-1)%62 ) continue;
						//}
						if ( a&(1LL<<r) )
							break;
					}
					j = j*62+r + 1;
					printf( "%d %d %d\n", i, j, k );
					return 0;
				}
			}
		}
	}
	printf( "-1\n" );
	return 0;
}