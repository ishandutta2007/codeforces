#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int n, k;
int t[4096], d[4096];

bool us[4096];

int la[4096][4096];
int mla[4096];

int main()
{
	int i, j, l, s;
	int bsol = 0;
	int ed = 86400;
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &t[i], &d[i] );
	}
	
	if ( k >= n )
	{
		printf( "%d\n", ed );
		return 0;
	}
	
	memset( mla, 127, sizeof( mla ) );
	for ( i = 1; i <= n; i++ )
	{
			la[i][0] = mla[i-0-1] + d[i];
			if ( ( la[i][0] < t[i] + d[i] ) || ( mla[i-0-1] == mla[n+2] ) )
				la[i][0] = t[i] + d[i];
		mla[i] = min( mla[i], la[i][0] );

//		printf( "LA %d %d -> %d\n", i, 0, la[i][0] );
	}
	
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= k; j++ )
		{
			if ( j < i )
			{
				la[i][j] = mla[i-j-1] + d[i];
				if ( ( la[i][j] < t[i] + d[i] ) || ( mla[i-j-1] == mla[n+2] ) )
					la[i][j] = t[i] + d[i];
				mla[i-j] = min( mla[i-j], la[i][j] );
				
//				printf( "LA %d %d -> %d\n", i, j, la[i][j] );
			}
		}
	}
	
	bsol = max( bsol, ed-la[n][k]+1 );
	bsol = max( bsol, t[k+1]-1 );
	for ( i = 1; i <= n; i++ )
	{
		if ( i+k >= n )
		{
			bsol = max( bsol, ed+1 - la[i][k-(n-i)] );
		}
		for ( j = 1; j < i; j++ )
		{
			l = k-(i-j-1);
			if ( l < 0 ) continue;
			if ( l >= j ) s = 1;
			else s = la[j][l];
//			printf( "%d %d -> %d\n", i, j, t[i]-s );
			bsol = max( bsol, t[i]-s );
		}
	}

	printf( "%d\n", bsol );
	return 0;
}