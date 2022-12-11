#include <cstdio>

typedef long long LL;

const int mod = 998244353;
const int MAXN = 1.5e5 + 5;

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

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1];

int su[MAXN << 2], BIT[MAXN];

int siz[MAXN], heavy[MAXN], LPos[MAXN], LTail[MAXN], bel[MAXN], dep[MAXN], seq[MAXN];

int head[MAXN], coe[MAXN], fath[MAXN], only[MAXN];
int N, Q, cnt, tot, ID, inv;

int Qkpow( int, int );
inline int Mul( LL x, int v ) { return x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }
inline void Upt( const int x ) { su[x] = Add( su[x << 1], su[x << 1 | 1] ); }

#define Lb( x ) ( x & ( -x ) )

void Update( int x, int v ) { for( ; x <= N ; x += Lb( x ) ) BIT[x] = Add( BIT[x], v ); }
int Get( int x ) { int ret = 0; for( ; x ; x -= Lb( x ) ) ret = Add( ret, BIT[x] ); return ret; }
void Update( int l, int r, int v ) { if( l <= r ) Update( l, v ), Update( r + 1, mod - v ); }

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

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void DFS1( const int u, const int fa )
{
	fath[u] = fa;
	dep[u] = dep[fa] + 1, siz[u] = 1, heavy[u] = -1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
		{
			DFS1( v, u ), siz[u] += siz[v];
			if( heavy[u] == -1 || siz[heavy[u]] < siz[v] ) heavy[u] = v;
		}
	coe[u] = Mul( N - siz[u], inv );
}

void DFS2( const int u, const int fa )
{
	seq[LPos[u] = ++ ID] = u;
	if( ~ heavy[u] ) DFS2( heavy[u], u ), bel[u] = bel[heavy[u]];
	else bel[u] = ++ tot; LTail[bel[u]] = u;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && v ^ heavy[u] )
			DFS2( v, u );
}

void Init()
{
	inv = Inv( N );
	DFS1( 1, 0 ), DFS2( 1, 0 );
}

void Update( const int x, const int l, const int r, const int p, const int v )
{
	if( l == r ) { su[x] = Add( su[x], v ); return ; }
	int mid = l + r >> 1;
	if( p <= mid ) Update( x << 1, l, mid, p, v );
	else Update( x << 1 | 1, mid + 1, r, p, v );
	Upt( x );
}

int Query( const int x, const int l, const int r, const int segL, const int segR )
{
	if( segL <= l && r <= segR ) return su[x];
	int mid = l + r >> 1, ret = 0;
	if( segL <= mid ) ret = Add( ret, Query( x << 1, l, mid, segL, segR ) );
	if( mid < segR ) ret = Add( ret, Query( x << 1 | 1, mid + 1, r, segL, segR ) );
	return ret;
}

void Change( const int u, const int val )
{
	int nw = Mul( val, Mul( siz[u], inv ) );
	Update( 1, LPos[u] - 1, nw );
	Update( LPos[u] + siz[u], N, nw );
	only[u] = Add( only[u], val );
	if( ~ heavy[u] ) Update( 1, 1, N, LPos[heavy[u]], Mul( coe[heavy[u]], val ) );
}

int Query( int u )
{
	int ret = Add( Get( LPos[u] ), only[u] );
	while( u )
	{
		ret = Add( ret, Query( 1, 1, N, LPos[LTail[bel[u]]], LPos[u] ) );
		u = LTail[bel[u]];
		if( fath[u] ) ret = Add( ret, Mul( coe[u], only[fath[u]] ) );
		u = fath[u];
	}
	return ret;
}

int main()
{
	read( N ), read( Q );
	for( int i = 1, a, b ; i < N ; i ++ )
		read( a ), read( b ), AddEdge( a, b ), AddEdge( b, a );
	Init();
	for( int opt, u, d ; Q ; -- Q )
	{
		read( opt ), read( u );
		if( opt == 1 ) read( d ), Change( u, d );
		else write( Query( u ) ), putchar( '\n' );
	}
	return 0;
}