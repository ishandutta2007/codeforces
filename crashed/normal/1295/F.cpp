#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int mod = 998244353;
const int MAXN = 105;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ); s = getchar(); }
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

int f[MAXN][MAXN];
int l[MAXN], r[MAXN], pnt[MAXN << 1];
int lef[MAXN], rig[MAXN];
int N;

int Qkpow( int base, int indx );
int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
int Mul( LL x, int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, int v ) { return x + v >= mod ? x + v - mod : x + v; }

int Qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = Mul( ret, base );
		base = Mul( base, base ), indx >>= 1;
	}
	return ret;
}

int C( const int n, const int m )
{
	if( n < m ) return 0; int ret = 1;
	for( int i = 1 ; i <= m ; i ++ ) 
		ret = Mul( ret, Mul( n - i + 1, Inv( i ) ) );
	return ret;
}

int main()
{
	read( N ); int tot = 0;
	for( int i = 1 ; i <= N ; i ++ ) read( l[i] ), read( r[i] );
	for( int i = 1 ; i <= N ; i ++ ) pnt[++ tot] = l[i], pnt[++ tot] = r[i] + 1;
	sort( pnt + 1, pnt + 1 + tot );
	tot = unique( pnt + 1, pnt + 1 + tot ) - pnt - 1;
	for( int i = 1 ; i <= N ; i ++ ) 
		lef[i] = lower_bound( pnt + 1, pnt + 1 + tot, l[i] ) - pnt,
		rig[i] = lower_bound( pnt + 1, pnt + 1 + tot, r[i] + 1 ) - pnt;
	
	int ans = 0, L;
	lef[0] = 1, rig[0] = tot + 1;
	for( int i = 1 ; i <= tot ; i ++ ) f[0][i] = 1;
	for( int i = 1 ; i <= N ; i ++ )
	{
		for( int j = lef[i] ; j < rig[i] ; j ++ )
		{
			L = pnt[j + 1] - pnt[j];
			for( int k = i ; k ; k -- )
			{
				if( j < lef[k] || rig[k] <= j ) break;
				f[i][j] = Add( f[i][j], Mul( f[k - 1][j + 1], C( i - k + L, i - k + 1 ) ) );
			}
		}
		for( int j = tot - 1 ; j ; j -- )
			f[i][j] = Add( f[i][j + 1], f[i][j] );
	}
	ans = f[N][1];
	for( int i = 1 ; i <= N ; i ++ )
		ans = Mul( ans, Inv( r[i] - l[i] + 1 ) );
	write( ans ), putchar( '\n' );
	return 0;
}