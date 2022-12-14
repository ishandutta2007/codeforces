#include <cstdio>
#include <cstring>

long long n;
int dl;
char digs[32];

char sl[8][32];

int cs[32][32];

int sol( int p, int r )
{
	if ( cs[p][r] != -1 )
		return cs[p][r];
	if ( p >= dl )
	{
		if ( r == 0 )
			return (cs[p][r] = 1);
		return (cs[p][r] = 0);
	}
	
	int sp = 20-p;
	int cdig = digs[ dl-1-p ] - '0';
	
	int b0, b4, b7;
	for ( b0 = 0; b0 <= 6; ++b0 )
	{
		for ( b4 = 0; b4 + b0 <= 6; ++b4 )
		{
			b7 = 6-b4-b0;
			if ( (4*b4 + 7*b7 + r)%10 == cdig )
			{
				if ( sol( p+1, (4*b4 + 7*b7 + r)/10 ) == 1 )
				{
					for ( int i = 0; i < b0; ++i )
						sl[i][sp] = '0';
					for ( int i = b0; i < b0+b4; ++i )
						sl[i][sp] = '4';
					for ( int i = b0+b4; i < b0+b4+b7; ++i )
						sl[i][sp] = '7';
					return (cs[p][r]=1);
				}
			}
		}
	}
	
	return (cs[p][r]=0);
}

int main()
{
	int t, T;
	scanf( "%d", &T );
	for ( t = 0; t < T; ++t )
	{
		scanf( "%I64d", &n );
		sprintf( digs, "%I64d", n );
		memset( sl, '0', sizeof( sl ) );
		for (int i = 0; i < 6; i++)
		{
			sl[i][21] = '\0';
		}
		
		dl = strlen( digs );
		memset( cs, -1, sizeof( cs ) );
		if ( !sol( 0, 0 ) )
			printf( "-1\n" );
		else
		{
			for ( int i = 0; i < 6; ++i )
			{
				long long k;
				sscanf( sl[i], "%I64d", &k );
				if ( i+1 < 6 )
					printf( "%I64d ", k );
				else
					printf( "%I64d\n", k );
			}
		}
	}
	return 0;
}