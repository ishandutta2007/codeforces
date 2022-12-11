#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;
typedef pair<LL, LL> Item;

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

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

LL suf[MAXN];
Item a[MAXN];
int N;

int main()
{
	read( N ); LL su = 0;
	rep( i, 1, N )
	{
		read( a[i].second ), read( a[i].first );
		su += a[i].second;
	}
	su <<= 1;
	sort( a + 1, a + 1 + N );
	LL ned = 0, free = 0;
	per( i, N, 1 ) suf[i] = suf[i + 1] + a[i].second;
	LL ans = su - MAX( 0ll, a[1].second - MAX( 0ll, a[1].first - suf[2] ) );
	rep( i, 1, N - 1 )
	{
		ned = MAX( ned, a[i].first - free );
		free += a[i].second;
		if( suf[i + 1] >= ned )
			ans = MIN( ans, su - free - MIN( MAX( 0ll, a[i + 1].second - MAX( 0ll, a[i + 1].first - suf[i + 2] - free ) ),
										     MAX( suf[i + 1] - ned, 0ll ) ) );
	}
	write( ans ), putchar( '\n' );
	return 0;
}

/*
5
8 1
7 1
6 2
4 1
3 1
*/