#include <cstdio>
#include <cstring>

int p[1<<20];
int n;

int main()
{
	int l, r;
	int i, j;
	
	scanf( "%d", &n );
	l = 1; r = n;
	while ( r - l + 1 >= 4 )
	{
		p[l] = l+1;
		p[l+1] = r;
		p[r] = r-1;
		p[r-1] = l;
		l += 2;
		r -= 2;
	}
	
	if ( r-l+1 == 1 )
	{
		p[l] = l;
	}
	else if ( r-l+1 == 2 )
	{
		printf( "-1\n" );
		return 0;
	}
	else if ( r-l+1 == 3 )
	{
		printf( "-1\n" );
		return 0;
	}
	
	for ( i = 1; i < n; i++ )
		printf( "%d ", p[i] );
	printf( "%d\n", p[n] );
	return 0;
}