#include <cstdio>
#include <cstring>

int n, a[1<<20];

int stop;
int id[1<<20], st[1<<20];

int main()
{
	int i, k;
	int sol = 0;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	
	id[0] = (1<<29);
	stop = 1;
	id[stop] = a[1];
	st[stop] = 0;
	for ( i = 2; i <= n; i++ )
	{
		k = 0;
		while ( id[stop] < a[i] )
		{
			if ( k < st[stop] )
				k = st[stop];
			stop--;
		}
		if ( stop > 0 )
		{
			k++;
			if ( sol < k )
				sol = k;
		}
		else
			k = 0;
		stop++;
		id[stop] = a[i];
		st[stop] = k;
	}
	
	printf( "%d\n", sol );
	return 0;
}