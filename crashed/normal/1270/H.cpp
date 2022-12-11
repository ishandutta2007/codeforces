#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 5e5 + 5, MAXV = 1e6 + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

struct MinValue {
	int v, c;

	MinValue(): v( 1e9 ), c( 0 ) {}
	MinValue( int V ): v( V ), c( 1 ) {}
	MinValue( int V, int C ): v( V ), c( C ) {}
};

MinValue tre[MAXV << 2];
int tag[MAXV << 2];
bool app[MAXV];

int A[MAXN];

int N, Q;

inline MinValue operator + ( const MinValue &a, const MinValue &b ) {
	MinValue ret;
	ret.v = Min( a.v, b.v );
	if( a.v == ret.v ) ret.c += a.c;
	if( b.v == ret.v ) ret.c += b.c;
	return ret;
}

inline void Upt( const int &x ) {
	tre[x] = tre[x << 1] + tre[x << 1 | 1];
}

void Build( const int &x, const int &l, const int &r ) {
	if( l > r ) return ;
	tag[x] = 0;
	if( l == r ) tre[x] = MinValue( 0, app[l] ); 
	else {
		int mid = ( l + r ) >> 1;
		Build( x << 1, l, mid );
		Build( x << 1 | 1, mid + 1, r );
		Upt( x );
	}
}

inline void Add( const int &x, const int &delt ) {
	tre[x].v += delt, tag[x] += delt;
}

inline void Normalize( const int &x ) {
	if( ! tag[x] ) return ;
	Add( x << 1, tag[x] );
	Add( x << 1 | 1, tag[x] );
	tag[x] = 0;
}

void Update( const int &x, const int &l, const int &r, const int &segL, const int &segR, const int &delt ) {
	if( segL <= l && r <= segR ) { Add( x, delt ); return ; }
	int mid = ( l + r ) >> 1; Normalize( x );
	if( segL <= mid ) Update( x << 1, l, mid, segL, segR, delt );
	if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, delt );
	Upt( x );
}

void Switch( const int &x, const int &l, const int &r, const int &p ) {
	if( l == r ) { tre[x].c ^= 1; return ; }
	int mid = ( l + r ) >> 1; Normalize( x );
	if( p <= mid ) Switch( x << 1, l, mid, p );
	else Switch( x << 1 | 1, mid + 1, r, p );
	Upt( x );
}

int main() {
	read( N ), read( Q );
	rep( i, 1, N ) read( A[i] ), app[A[i]] = true;
	A[0] = 1e6 + 1, A[N + 1] = 0; 
	Build( 1, 0, 1e6 );
	rep( i, 1, N + 1 ) 
		if( A[i - 1] > A[i] ) 
			Update( 1, 0, 1e6, A[i], A[i - 1] - 1, +1 );
	while( Q -- ) {
		int x, y;
		read( x ), read( y );
		Switch( 1, 0, 1e6, A[x] );
		Switch( 1, 0, 1e6, y );
		if( A[x - 1] > A[x] )
			Update( 1, 0, 1e6, A[x], A[x - 1] - 1, -1 );
		if( A[x] > A[x + 1] )
			Update( 1, 0, 1e6, A[x + 1], A[x] - 1, -1 );
		A[x] = y;
		if( A[x - 1] > A[x] )
			Update( 1, 0, 1e6, A[x], A[x - 1] - 1, +1 );
		if( A[x] > A[x + 1] )
			Update( 1, 0, 1e6, A[x + 1], A[x] - 1, +1 );
		write( tre[1].c ), putchar( '\n' );
	}
	return 0;
}