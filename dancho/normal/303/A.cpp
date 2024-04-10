#include <cstdio>
#include <cstring>

int n;
int a[1<<20], b[1<<20], c[1<<20];

int main()
{
	int i;
	scanf( "%d", &n );
	if ( n%2 == 0 )
	{
		printf( "-1\n" );
		return 0;
	}
	
	for ( i = 0; i < n; i++ )
	{
		a[i] = i;
		c[i] = (n-i)%n;
		b[i] = (n+c[i]-a[i])%n;
	}
	
	for ( i = 0; i < n-1; i++ )
		printf( "%d ", a[i] );
	printf( "%d\n", a[n-1] );
	for ( i = 0; i < n-1; i++ )
		printf( "%d ", b[i] );
	printf( "%d\n", b[n-1] );
	for ( i = 0; i < n-1; i++ )
		printf( "%d ", c[i] );
	printf( "%d\n", c[n-1] );
}