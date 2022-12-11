#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5005, MAXLOG = 15;

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

int lch[MAXN], rch[MAXN];
int stk[MAXN], top;

int f[MAXN][MAXN];

int a[MAXN], val[MAXN], rnk[MAXN];
int N, len;

void Init()
{
	for( int i = 1 ; i <= N ; i ++ )
	{
		while( top && a[stk[top]] >= a[i] ) lch[i] = stk[top --];
		if( top ) rch[stk[top]] = i; stk[++ top] = i;
	}
	while( top > 1 ) rch[stk[top - 1]] = stk[top], top --;
	
	for( int i = 0 ; i <= N ; i ++ ) val[++ len] = a[i];
	std :: sort( val + 1, val + 1 + len );
	len = std :: unique( val + 1, val + 1 + len ) - val - 1;
	for( int i = 0 ; i <= N ; i ++ ) 
		rnk[i] = lower_bound( val + 1, val + 1 + len, a[i] ) - val;
}

void DFS( const int u, const int l, const int r, const int fa )
{
	if( ! u || l > r ) return ;

	DFS( lch[u], l, u - 1, u );
	DFS( rch[u], u + 1, r, u );
	
	int tot = 0, mn = INF, lim = rnk[u] + 1;
	for( int i = l ; i <= r ; i ++ ) tot += rnk[u] == rnk[i];
	for( int i = rnk[fa] ; ~ i ; i -- )
	{
		f[u][i] = i == rnk[u] ? r - l + 1 - tot : r - l + 1;
		for( ; i < lim ; ) lim --, mn = MIN( mn, f[lch[u]][lim] + f[rch[u]][lim] + val[lim] - ( lim == rnk[u] ) );
		f[u][i] = MIN( f[u][i], mn + 1 - val[i] );
	}
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	Init();
	
	DFS( stk[1], 1, N, 0 );
	write( f[stk[1]][0] ), putchar( '\n' );
	return 0;
}