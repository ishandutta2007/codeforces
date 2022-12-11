#include <cstdio>

typedef long long LL;

const int MAXN = 3e5 + 5, MAXA = 1e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = x * 10 + ( s - '0' ), s = getchar(); }
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

int prime[MAXA], pn;
bool isPrime[MAXA];

LL su[MAXN << 2];
int tims[MAXN << 2];

int D[MAXA];
int val[MAXN];
int N, M, mx;

void Init()
{
	for( int d = 1 ; d <= mx ; d ++ )
		for( int n = d ; n <= mx ; n += d )
			D[n] ++;
}

void Upt( const int x ) { su[x] = su[x << 1] + su[x << 1 | 1]; }

void Build( const int x, const int l, const int r )
{
    if( l > r ) return ; tims[x] = 6;
    if( l == r ) { su[x] = val[l]; return ; }
    int mid = l + r >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
    Upt( x );
}

void Cover( const int x, const int l, const int r )
{
	if( ! tims[x] ) return ; tims[x] --;
	if( l == r ) { su[x] = D[su[x]]; return ; }
	int mid = l + r >> 1;
	Cover( x << 1, l, mid );
	Cover( x << 1 | 1, mid + 1, r );
	Upt( x );
}

void Update( const int x, const int l, const int r, const int segL, const int segR )
{
	if( segL <= l && r <= segR ) { Cover( x, l, r ); return ; }
	int mid = l + r >> 1; 
	if( segL <= mid ) Update( x << 1, l, mid, segL, segR );
	if( mid < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR );
	Upt( x );
}

LL Query( const int x, const int l, const int r, const int segL, const int segR )
{
	if( segL <= l && r <= segR ) return su[x];
	int mid = l + r >> 1; LL ret = 0;
	if( segL <= mid ) ret += Query( x << 1, l, mid, segL, segR );
	if( mid < segR ) ret += Query( x << 1 | 1, mid + 1, r, segL, segR );
	return ret;
}

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ ) read( val[i] ), mx = MAX( mx, val[i] );
	Init(); 
	Build( 1, 1, N );
	for( int t, l, r ; M ; -- M )
	{
		read( t ), read( l ), read( r );
		if( t == 1 ) Update( 1, 1, N, l, r );
		if( t == 2 ) write( Query( 1, 1, N, l, r ) ), putchar( '\n' );
	}
	return 0;
}