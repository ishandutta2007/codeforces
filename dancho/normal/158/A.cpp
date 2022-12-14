#include <cstdio>
#include <cstring>

int n, k, a[1024];

int main()
{
	int i, j;
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	
	if ( a[k] > 0 )
	{
		j = k;
		while ( ( j+1 <= n ) && ( a[j+1] == a[k] ) )
		{
			j++;
		}
		printf( "%d\n", j );
	}
	else if ( a[k] == 0 )
	{
		j = k-1;
		while ( ( j > 0 ) && ( a[j] == 0 ) )
			j--;
		printf( "%d\n", j );
	}
	return 0;
}