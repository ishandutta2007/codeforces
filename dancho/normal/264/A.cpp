#include <cstdio>
#include <cstring>

int m;
char st[1<<20];

void gogo( int i )
{
	if ( i >= m ) return;
	if ( st[i] == 'r' )
	{
		printf( "%d\n", i+1 );
		gogo( i+1 );
	}
	else
	{
		gogo(i+1 );
		printf( "%d\n", i+1 );
	}
}

int main()
{
	scanf( "%s", st );
	m = strlen( st );
	gogo( 0 );
}