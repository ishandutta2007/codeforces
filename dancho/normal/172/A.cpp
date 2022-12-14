#include <cstdio>
#include <cstring>

int lcp( char a[], char b[], int ml )
{
	int i;
	for ( i = 0; i < ml && i < (int)strlen( b ); i++ )
	{
		if ( a[i] != b[i] ) break;
	}
	return i;
}

int n;
char pr[64], cr[64];

int main()
{
	int i, l;
	
	scanf( "%d", &n );
	scanf( "%s", pr );
	l = strlen( pr );
	for ( i = 1; i < n; i++ )
	{
		scanf( "%s", cr );
		l = lcp( pr, cr, l );
	}
	printf( "%d\n", l );
	return 0;
}