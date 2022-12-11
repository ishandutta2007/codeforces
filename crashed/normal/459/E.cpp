#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 3e5 + 5;

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
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

struct Edge
{
	int u, v, w;
	Edge() { u = v = w = 0; }
	Edge( int U, int V, int W ) { u = U, v = V, w = W; }
	bool operator < ( const Edge &b ) const { return w < b.w; }
}E[MAXN];

int f[MAXN], tmp[MAXN];
int N, M;

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= M ; i ++ ) 
		read( E[i].u ), read( E[i].v ), read( E[i].w );
	sort( E + 1, E + 1 + M );
	for( int i = 1, r ; i <= M ; i = r )
	{
		for( r = i ; r <= M && E[r].w == E[i].w ; r ++ )
			tmp[E[r].u] = f[E[r].u];
		for( int j = i ; j < r ; j ++ )
			f[E[j].v] = MAX( f[E[j].v], tmp[E[j].u] + 1 );
	}
	int ans = 0;
	for( int i = 1 ; i <= N ; i ++ )
		ans = MAX( ans, f[i] );
	write( ans ), putchar( '\n' );
	return 0;
}