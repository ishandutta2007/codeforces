#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x )
{
    x = 0; char s = getchar(); int f = 1;
    while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    x *= f;
}

template<typename _T>
void write( _T x )
{
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

int buc[MAXN][30];

char str[MAXN];
int N, Q;

int main()
{
	read( N ), read( Q );
	scanf( "%s", str + 1 );
	rep( i, 1, N )
	{
		rep( j, 0, 25 ) buc[i][j] = buc[i - 1][j];
		buc[i][str[i] - 'a'] ++; 
	}
	int l, r;
	while( Q -- )
	{
		LL ans = 0;
		read( l ), read( r );
		rep( i, 0, 25 )
			ans += 1ll * ( i + 1 ) * ( buc[r][i] - buc[l - 1][i] );
		write( ans ), putchar( '\n' );
	}
	return 0;
}