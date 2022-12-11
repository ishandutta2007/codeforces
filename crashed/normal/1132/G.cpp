#include <cctype>
#include <cstdio>

#define rep( x, a, b ) for( int ( x ) = a ; x <= b ; x ++ )
#define per( x, a, b ) for( int ( x ) = a ; x >= b ; x -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( ! isdigit( s ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( isdigit( s ) ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
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

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1];

int mx[MAXN << 2], tag[MAXN << 2];

int stk[MAXN], top;

int A[MAXN], head[MAXN], DFN[MAXN], siz[MAXN];
int N, K, cnt, ID;

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void Init( const int u )
{
	DFN[u] = ++ ID, siz[u] = 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		Init( v = Graph[i].to ), siz[u] += siz[v];
}

void Add( const int x, const int v ) { mx[x] += v, tag[x] += v; }
void Upt( const int x ) { mx[x] = MAX( mx[x << 1], mx[x << 1 | 1] ); }
void Normalize( const int x ) { if( tag[x] ) Add( x << 1, tag[x] ), Add( x << 1 | 1, tag[x] ), tag[x] = 0; }

void Update( const int x, const int l, const int r, const int segL, const int segR, const int v )
{
	if( segL <= l && r <= segR ) return void( Add( x, v ) );
	int mid = l + r >> 1; Normalize( x );
	if( segL <= mid ) Update( x << 1, l, mid, segL, segR, v );
	if( mid < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, v );
	Upt( x );
}

int main()
{
	read( N ), read( K );
	rep( i, 1, N ) read( A[i] ); A[++ N] = INF;
	rep( i, 1, N )
	{
		while( top && A[stk[top]] < A[i] ) AddEdge( i, stk[top --] );
		stk[++ top] = i;
	}
	Init( N );
	rep( i, 1, K - 1 ) Update( 1, 1, N, DFN[i], DFN[i] + siz[i] - 1, 1 );
	rep( i, K, N - 1 ) 
		Update( 1, 1, N, DFN[i], DFN[i] + siz[i] - 1, 1 ), 
		write( mx[1] ), putchar( i == N - 1 ? '\n' : ' ' ),
		Update( 1, 1, N, DFN[i - K + 1], DFN[i - K + 1], -INF );
	return 0;
}