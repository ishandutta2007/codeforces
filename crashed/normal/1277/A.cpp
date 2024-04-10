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

int base[15];

int main()
{
	int T, cnt, n, other;
	base[1] = 1;
	for( int i = 2 ; i <= 10 ; i ++ ) base[i] = base[i - 1] * 10 + 1;
	read( T );
	while( T -- )
	{
		cnt = other = 0;
		read( n );
		for( int i = n ; i > 9 ; i /= 10 ) cnt ++;
		for( int i = base[cnt + 1] ; i <= n ; i += base[cnt + 1] ) other ++;
		write( cnt * 9 + other ), putchar( '\n' );
	}
	return 0;
}
/*
1
1000000000
*/