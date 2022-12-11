#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e9;
const int mod = 1e9 + 7, inv2 = ( mod + 1 ) / 2;

#ifdef _DEBUG
const int MAXN = 100 + 5;
#else
const int MAXN = 1e5 + 5;
#endif // _DEBUG

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
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

inline LL Shrink( const LL x )
{
	if( x < 0 ) return MAX( - INF, x );
	return MIN( x, INF );
}

struct Block
{
	int l, r; LL su;
	Block(): l( 0 ), r( 0 ), su( 0 ) {}
	Block( int L, int R, LL S ): l( L ), r( R ), su( S ) {}

	Block operator + ( const Block &q ) const
	{
		Block ret;
		ret.l = l, ret.r = q.r;
		int dist = r - l + 1;
		if( dist > 30 || su + ( q.su << dist ) > INF ) ret.su = INF;
		else ret.su = su + ( q.su << dist ); return ret;
	}
};

std :: vector<int> que[MAXN];

Block stk[MAXN];
int part[MAXN];

int qL[MAXN], ans[MAXN];

int pref[MAXN], pw[MAXN], inv[MAXN];

int A[MAXN];
int N, Q;

inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Fix( const LL a ) { return ( a % mod + mod ) % mod; }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int Get( const int l, const int r )
{ return Mul( inv[l], Sub( pref[r], pref[l - 1] ) ); }

signed main()
{
	read( N ), read( Q );
	rep( i, 1, N ) read( A[i] );
	rep( i, 1, Q )
	{
		int r; read( qL[i] ), read( r );
		que[r].push_back( i );
	}
	pw[0] = 1; rep( i, 1, N ) pw[i] = Mul( pw[i - 1], 2 );
	inv[0] = 1; rep( i, 1, N ) inv[i] = Mul( inv[i - 1], inv2 );
	pref[0] = 0; rep( i, 1, N ) pref[i] = Add( pref[i - 1], Mul( pw[i], Fix( A[i] ) ) );
	int top = 0;
	rep( i, 1, N )
	{
		stk[++ top] = Block( i, i, A[i] );
		part[top] = Add( part[top - 1], Fix( stk[top].su ) );
		while( top > 1 && stk[top].su > 0 )
		{
			stk[top - 1] = stk[top - 1] + stk[top], top --;
			part[top] = Add( part[top - 1], Fix( stk[top].su ) );
		}
		for( int j = 0 ; j < ( int ) que[i].size() ; j ++ )
		{
			int u = que[i][j];
			int l = 1, r = top, mid;
			while( l < r )
			{
				mid = ( l + r ) >> 1;
				if( qL[u] <= stk[mid].r ) r = mid;
				else l = mid + 1;
			}
			ans[u] = Add( Get( qL[u], stk[l].r ), Mul( 2, Sub( part[top], part[l] ) ) );
		}
	}
	rep( i, 1, Q ) write( ans[i] ), putchar( '\n' );
	return 0;
}