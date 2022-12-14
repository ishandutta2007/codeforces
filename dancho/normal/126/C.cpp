#include <cstdio>
#include <cstring>

int n;
char x[2048][2048];
int cru[2048], ccu[2048];
int crd[2048], ccd[2048];

int main()
{
	int i, j, k;
	int ans = 0;
	
	scanf( "%d", &n );
	for ( i = 0; i < n; i++ )
	{
		scanf( "%s", x[i] );
	}
	
	memset( cru, 0, sizeof( cru ) );
	memset( ccu, 0, sizeof( ccu ) );
	memset( crd, 0, sizeof( crd ) );
	memset( ccd, 0, sizeof( ccd ) );
	
	for ( i = n-1; i > 0; i-- )
	{
		for ( j = 0, k = i; k < n; j++, k++ )
		{
			if ( x[k][j] == '1' )
			{
				if ( ( crd[k] + ccd[j] ) % 2 == 1 ) continue;
				ans++;
				crd[k]++;
				ccd[j]++;
			}
			else if ( x[k][j] == '0' )
			{
				if ( ( crd[k]+ccd[j] ) % 2 == 0 ) continue;
				ans++;
				crd[k]++;
				ccd[j]++;
			}
		}
	}

	for ( j = n-1; j > 0; j-- )
	{
		for ( i = 0, k = j; k < n; i++, k++ )
		{
			if ( x[i][k] == '1' )
			{
				if ( ( cru[i] + ccu[k] ) % 2 == 1 ) continue;
				ans++;
				cru[i]++;
				ccu[k]++;
			}
			else if ( x[i][k] == '0' )
			{
				if ( ( cru[i]+ccu[k] ) % 2 == 0 ) continue;
				ans++;
				cru[i]++;
				ccu[k]++;
			}
		}
	}
	
	for ( i = 0; i < n; i++ )
	{
		if ( x[i][i] == '1' )
		{
			if ( (ccu[i]+cru[i]+ccd[i]+crd[i])%2 == 0 ) ans++;
		}
		else if ( x[i][i] == '0' )
		{
			if ( (ccu[i]+cru[i]+ccd[i]+crd[i])%2 == 1 ) ans++;
		}
	}
	printf( "%d\n", ans );
	return 0;
}