#include <cstdio>
#include <cstring>

int rev( int x )
{
	int i, j;
	j = 0;
	for ( i = 0; i < 8; i++ )
	{
		j = j*2 + x%2;
		x = x / 2;
	}
	return j;
}

int main()
{
	int k;
	int pr, cr;
	char x;
	
	pr = 0;
	while ( scanf( "%c", &x ) == 1 )
	{
		if ( x == '\n' ) break;
		cr = (int) x;
		k = (rev( pr ) - rev( x ) + 256)%256;
		printf( "%d\n", k );
		pr = cr;
	}
	return 0;
}