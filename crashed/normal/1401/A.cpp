#include <cstdio>

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

int main()
{
	int T, N, K;
	read( T );
	while( T -- )
	{
		read( N ), read( K );
		if( K >= N ) write( K - N );
		else write( ( N - K ) & 1 );
		putchar( '\n' ); 
	}
	return 0;
}