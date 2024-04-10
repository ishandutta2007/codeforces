#include <cstdio>
#include <algorithm>

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

struct customer
{
	int t, l, r;
	customer() { t = l = r = 0; }
	bool operator < ( const customer & b ) const { return t < b.t; }
}a[MAXN];

int N, M;

int main()
{
	int Q, mn, mx;
	bool flag;
	read( Q );
	while( Q -- )
	{
		read( N ), read( M ); mn = mx = M, flag = true;
		for( int i = 1 ; i <= N ; i ++ ) read( a[i].t ), read( a[i].l ), read( a[i].r );
		std :: sort( a + 1, a + 1 + N );
		for( int i = 1 ; i <= N ; i ++ )
		{
			mn = mn - ( a[i].t - a[i - 1].t );
			mx = mx + ( a[i].t - a[i - 1].t );
			if( MAX( mn, a[i].l ) > MIN( mx, a[i].r ) ) { flag = false; break; }
			mn = MAX( mn, a[i].l ), mx = MIN( mx, a[i].r );
		}
		puts( flag ? "YES" : "NO" );
	}
	return 0;
}