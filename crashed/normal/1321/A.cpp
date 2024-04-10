#include <cmath>
#include <cstdio>

const int MAXN = 105;

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

int a[MAXN], b[MAXN];
int N;

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= N ; i ++ ) read( b[i] );
	for( int i = 1 ; i <= N ; i ++ ) if( a[i] == b[i] ) a[i] = b[i] = 0;
	int tot = 0, ta = 0;
	for( int i = 1 ; i <= N ; i ++ ) ta += a[i], tot += b[i];
	if( ta == 0 ) { puts( "-1" ); return 0; }
	write( int( ceil( 1.0 * ( tot + 1 ) / ta ) ) ), putchar( '\n' );
	return 0;
}
/*
10
1 1 1 0 0 0 0 0 0 0
0 0 0 1 1 1 1 1 1 1
*/