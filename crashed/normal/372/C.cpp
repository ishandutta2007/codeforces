#include <cstdio>
#include <iostream>

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 150005, MAXM = 305;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar();int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + s - '0', s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) { putchar( '-' ), x = -x; }
	if( 9 < x ) { write( x / 10 ); }
	putchar( x % 10 + '0' );
}

template<typename _T>
_T ABS( const _T a ) 
{
	return a < 0 ? -a : a;
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

LL pre[MAXN], nxt[MAXN];
int deq[MAXN], he, ta;
int a[MAXM], b[MAXM], t[MAXM];
int N, M, D;

int main()
{
	read( N ), read( M ), read( D );
	for( int i = 1 ; i <= M ; i ++ ) read( a[i] ), read( b[i] ), read( t[i] );
	for( int i = 1 ; i <= N ; i ++ ) pre[i] = 0;
	t[0] = 1;
	LL ran;
	for( int k = 1 ; k <= M ; k ++ )
	{
		ran = 1ll * D * ( t[k] - t[k - 1] );
		he = 1, ta = 0;
		for( int i = 1 ; i <= N ; i ++ ) nxt[i] = pre[i] + b[k] - ABS( a[k] - i );
		for( int i = 1 ; i <= N ; i ++ )
		{
			while( he <= ta && deq[he] < i - ran ) he ++;
			if( he <= ta ) nxt[i] = MAX( nxt[i], pre[deq[he]] + b[k] - ABS( a[k] - i ) );
			while( he <= ta && pre[deq[ta]] <= pre[i] ) ta --; deq[++ ta] = i;
		}
		he = 1, ta = 0;
		for( int i = N ; i ; i -- )
		{
			while( he <= ta && deq[he] > i + ran ) he ++;
			if( he <= ta ) nxt[i] = MAX( nxt[i], pre[deq[he]] + b[k] - ABS( a[k] - i ) );
			while( he <= ta && pre[deq[ta]] <= pre[i] ) ta --; deq[++ ta] = i;
		}
		std :: swap( pre, nxt );
	}
	LL res = -INF;
	for( int i = 1 ; i <= N ; i ++ ) res = MAX( res, pre[i] );
	write( res ), putchar( '\n' );
	return 0;
}