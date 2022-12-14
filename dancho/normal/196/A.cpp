#include <cstdio>
#include <cstring>

int n;
char a[200020];
int mx[200020];

int main()
{
	int i, j, k;
	scanf( "%s", a );
	n = strlen( a );
	
	mx[n] = n;
	mx[n-1] = n-1;
	for ( i = n-2; i >= 0; i-- )
	{
		if ( a[i] >= a[mx[i+1]] )
			mx[i] = i;
		else mx[i] = mx[i+1];
	}
	
	i = 0;
	while ( i < n )
	{
		printf( "%c", a[mx[i]] );
		i = mx[i]+1;
	}
	printf( "\n" );
	return 0;
}