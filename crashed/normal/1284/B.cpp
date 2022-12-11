#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5, MAXV = 1e6 + 5;

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
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

vector<int> s[MAXN];

int BIT[MAXV];
int l[MAXN];
int N;

int lowbit( const int x ) { return x & ( -x ); }
void update( const int x, const int v ) { for( int i = x ; i <= 1e6 + 1 ; i += lowbit( i ) ) BIT[i] += v; }
int getSum( const int x ) { int ret = 0; for( int i = x ; i ; i -= lowbit( i ) ) ret += BIT[i]; return ret; }

int main()
{
	LL ans = 0;
	int mn, mx, a, tot = 0;
	bool flag;
	read( N );
	for( int i = 1 ; i <= N ; i ++ )
	{
		read( l[i] );
		flag = false, mn = INF, mx = -INF;
		for( int j = 1 ; j <= l[i] ; j ++ )
		{
			read( a ); s[i].push_back( a );
			if( a > mn ) flag = true;
			mx = MAX( mx, a ), mn = MIN( mn, a );
		}
		if( mx > mn ) ans ++;
		if( flag ) tot ++;
		else
		{
			mx ++, mn ++;
			ans += getSum( mx - 1 );
			update( mn, 1 );
		}
	}
	memset( BIT, 0, sizeof BIT );
	for( int i = N ; i ; i -- )
	{
		flag = false, mn = INF, mx = -INF;
		for( int j = 0 ; j < l[i] ; j ++ ) 
		{
			if( s[i][j] > mn ) flag = true;
			mx = MAX( mx, s[i][j] ), mn = MIN( mn, s[i][j] );
		}
		if( flag ) continue;
		mx ++, mn ++;
		ans += getSum( mx - 1 );
		update( mn, 1 );
	}
	write( ans + 1ll * ( N - tot ) * tot * 2 + 1ll * tot * ( tot - 1 ) ), putchar( '\n' );
	return 0;
}
/*
3
2 1 2
2 1 2
2 1 2
*/