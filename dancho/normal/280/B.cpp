#include <cstdio>
#include <cstring>

int n;

int a[1<<17];
int mx;
int st[1<<17], stop;

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	
	mx = -1;
	stop = 0;
	for ( i = 1; i <= n; i++ )
	{
		while ( ( stop > 0 ) && ( st[stop] <= a[i] ) )
		{
			if ( st[stop] < a[i] )
			{
				if ( ( st[stop] ^ a[i] ) > mx )
					mx = (st[stop]^a[i]);
			}
			stop--;
		}
		st[++stop] = a[i];
	}

	for ( i = n; i > 0; i-- )
	{
		while ( ( stop > 0 ) && ( st[stop] <= a[i] ) )
		{
			if ( st[stop] < a[i] )
			{
				if ( ( st[stop] ^ a[i] ) > mx )
					mx = (st[stop]^a[i]);
			}
			stop--;
		}
		st[++stop] = a[i];
	}
	printf( "%d\n", mx );
	return 0;
}